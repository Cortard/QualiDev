#include "controllerdelete.h"

ControllerDelete::ControllerDelete()
{

}

ControllerDelete::ControllerDelete(Promotion *data) : Controller(data)
{}

bool ControllerDelete::deleteEtu(int etudiant)
{
    if(!exist(etudiant)) return false;
    Student* aSupp;
    for(Student* student : data->students)
        if(student->getNumero()==etudiant){
            aSupp=student;
            break;
        }

    data->students.removeOne(aSupp);
    delete aSupp;

    data->notify();

    return true;
}

bool ControllerDelete::deleteEtu(QStringList etudiants)
{
    for(QString etudiant : etudiants){
        if(!exist(etudiant)) return false;
        Student* aSupp;
        for(Student* student : data->students)
            if(student->toQstring()==etudiant){
                aSupp=student;
                break;
            }

        data->students.removeOne(aSupp);
        delete aSupp;
    }
    data->notify();

    return true;
}
