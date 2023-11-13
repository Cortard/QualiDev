#include "controllerdelete.h"

ControllerDelete::ControllerDelete(Promotion *data, QStringList* input) : Controller(data,input)
{}

int ControllerDelete::action()
{
    int cpt=0;
    for(QString etudiant : *input){
        int rank=data->exist(etudiant);
        if(rank==-1) continue;
        data->deleteEtu(rank, 0);
        ++cpt;
    }
    data->notify();

    return cpt;
}

