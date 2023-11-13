#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "promotion.h"

/*! Class Controller, abstract. Controllers make link between view and data */
class Controller
{
protected:
    /**
     * @brief data, pointer vers les donnes
     */
    Promotion* data;
    /**
     * @brief input, pointer vers la listes de input
     */
    QStringList* input;
public:
    /**
     * @brief Controller constructeur
     * @param data pointeur vers les données
     * @param input pointeur vers les inputs
     */
    Controller(Promotion *data, QStringList* input);
    /**
     * @brief action fonction qui effectue l'action specialisé de controller
     * @return resultat de l'action, voir doc particulière
     */
    virtual int action()=0;
    /**
     * @brief ~Controller destructeur virtuelle
     */
    virtual ~Controller(){};
};

#endif // CONTROLLER_H
