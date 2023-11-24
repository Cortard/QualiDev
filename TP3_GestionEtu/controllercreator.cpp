#include "controllercreator.h"

Controller* ControllerCreator::Controller(Promotion *data, QStringList *input)
{
    if(input->length()==1)
        return new ControllerDelete(data,input);

    if(input->length()==5){
        QStringList bacs;
        bacs<<"S"<<"ES"<<"STI"<<"L"<<"STI"<<"Etr"<<"Autre";
        if(bacs.contains(input->at(3)))
            return new ControllerAdd(data,input);
    }

    return new ControllerDelete(data,input);
}

