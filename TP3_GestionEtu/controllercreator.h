#ifndef CONTROLLERCREATOR_H
#define CONTROLLERCREATOR_H

#include "promotion.h"

#include "controller.h"
#include "controlleradd.h"
#include "controllerdelete.h"

/**
 * @brief The ControllerCreator class, class du design patern factory, cree les controller
 */
class ControllerCreator
{
public:
    /**
     * @brief Controller cree le bon controller
     * si input.len==1 -> ControllerDelete
     * si input.len==5 et input[3] est un des bacs possible -> ControllerAdd
     * sinon -> ControllerDelete
     * @param data pointeur vers les données
     * @param input pointeur vers les inputs
     * @return pointer vers le controller choisi
     */
    static Controller *Controller(Promotion *data, QStringList* input);
};

#endif // CONTROLLERCREATOR_H
