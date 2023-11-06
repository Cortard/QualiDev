#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include "observer.h"

#include <QList>

class Observable
{
protected:
    QList<Observer*> observeurs;
public:
    Observable();
    void addObserveur(Observer* observeur);
    void notify();
};

#endif // OBSERVABLE_H
