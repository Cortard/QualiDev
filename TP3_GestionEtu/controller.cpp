#include "controller.h"

Controller::Controller()
{

}

Controller::Controller(Promotion *data) : data(data)
{}

bool Controller::exist(int etudiant)
{
    for(Student* student : data->students)
        if(student->getNumero()==etudiant)
            return true;
    return false;
}

bool Controller::exist(QString etudiant)
{
    for(Student* student : data->students)
        if(student->toQstring()==etudiant)
            return true;
    return false;
}
