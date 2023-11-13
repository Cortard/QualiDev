#ifndef CONTROLLERADD_H
#define CONTROLLERADD_H

#include "controller.h"

class ControllerAdd : public Controller
{
public:
    ControllerAdd(Promotion *data, QStringList* input);
    int action() override;
    ~ControllerAdd(){};
};

#endif // CONTROLLERADD_H
