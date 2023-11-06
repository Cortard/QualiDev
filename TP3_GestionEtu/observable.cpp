#include "observable.h"

Observable::Observable()
{

}

void Observable::addObserveur(Observer *observeur)
{
    observeurs.append(observeur);
}

void Observable::notify()
{
    for(Observer* observeur : observeurs)
        observeur->refresh();
}
