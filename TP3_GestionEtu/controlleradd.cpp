#include "controlleradd.h"

#include <Qchar>

ControllerAdd::ControllerAdd(Promotion *data, QStringList* input) : Controller(data, input)
{

}

int ControllerAdd::action()
{
    QString numero=input->at(0);
    QString prenom=input->at(1);
    QString nom=input->at(2);
    QString bac=input->at(3);
    QString departement=input->at(4);

    for(QChar digit : numero)
        if(!digit.isDigit()) return -1;
    int num=numero.toInt();
    if(data->exist(num)!=-1) return -1;
    data->addEtu(num,prenom,nom,bac,departement);
    data->notify();
    return true;
}
