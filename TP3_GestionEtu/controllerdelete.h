#ifndef CONTROLLERDELETE_H
#define CONTROLLERDELETE_H

#include "controller.h"

class ControllerDelete : public Controller
{
public:
    ControllerDelete(Promotion *data, QStringList* input);
    int action() override;
    ~ControllerDelete(){};
};

#endif // CONTROLLERDELETE_H
