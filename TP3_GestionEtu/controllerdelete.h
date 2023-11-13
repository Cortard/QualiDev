#ifndef CONTROLLERDELETE_H
#define CONTROLLERDELETE_H

#include "controller.h"

/**
 * @brief The ControllerDelete class, class qui s'occupe de supprimer des donnes
 */
class ControllerDelete : public Controller
{
public:
    /**
     * @brief ControllerDelete constructeur
     * @param data pointeur vers les données
     * @param input pointeur vers les inputs
     */
    ControllerDelete(Promotion *data, QStringList* input);
    /**
     * @brief action fonction qui suprime les inputs si existe
     * @return resultat de l'action, nombre d'input supprimées
     */
    int action() override;
    /**
     * @brief ~ControllerDelete destructeur
     */
    ~ControllerDelete(){};
};

#endif // CONTROLLERDELETE_H
