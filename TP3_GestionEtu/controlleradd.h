#ifndef CONTROLLERADD_H
#define CONTROLLERADD_H

#include "controller.h"

/**
 * @brief The ControllerAdd class, class qui s'occupe d'ajouter aux donnes
 */
class ControllerAdd : public Controller
{
public:
    /**
     * @brief ControllerAdd constructeur
     * @param data pointeur vers les données
     * @param input pointeur vers les inputs
     */
    ControllerAdd(Promotion *data, QStringList* input);
    /**
     * @brief action fonction qui ajoute les inputs si n'existe pas deja
     * @return resultat de l'action, -1 si le numero est deja pris, 1 sinon
     */
    int action() override;
    /**
     * @brief ~ControllerAdd destructeur
     */
    ~ControllerAdd(){};
};

#endif // CONTROLLERADD_H
