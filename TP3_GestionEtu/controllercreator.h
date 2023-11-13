#ifndef CONTROLLERCREATOR_H
#define CONTROLLERCREATOR_H

#include "promotion.h"

#include "controller.h"
#include "controlleradd.h"
#include "controllerdelete.h"


class ControllerCreator
{
public:
    static Controller *Controller(Promotion *data, QStringList* input);
};

#endif // CONTROLLERCREATOR_H
