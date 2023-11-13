#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

#include <QList>

/**
 * @brief The Observable class, class du design pattern observateur, observable
 */
class Observable
{
protected:
    /**
     * @brief observeurs listes des pointeurs vers les obsevateurs
     */
    QList<Observer*> observeurs;
public:
    /**
     * @brief Observable constructeur
     */
    Observable();
    /**
     * @brief addObserveur ajoute un observateur a la liste
     * @param observeur adresse le l'observateur
     */
    void addObserveur(Observer* observeur);
    /**
     * @brief notify appel la fonction refresh de tout les abonnes
     */
    void notify();
};

#endif // OBSERVABLE_H
