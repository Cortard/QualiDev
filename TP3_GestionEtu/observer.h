#ifndef OBSERVER_H
#define OBSERVER_H

/**
 * @brief The Observer class, class abstraite du design pattern observateur, observeur
 */
class Observer
{
public:
    /**
     * @brief Observer constructeur
     */
    Observer();
    /**
     * @brief refresh fonction virtuelle, fonction appelé par l'observé
     */
    virtual void refresh()=0;
};

#endif // OBSERVER_H
