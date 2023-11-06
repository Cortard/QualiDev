#ifndef CONTROLLERDELETE_H
#define CONTROLLERDELETE_H

#include "controller.h"

class ControllerDelete : public Controller
{
public:
    ControllerDelete();
    ControllerDelete(Promotion *data);
    bool deleteEtu(int etudiant);
    bool deleteEtu(QStringList etudiants);
};

#endif // CONTROLLERDELETE_H
