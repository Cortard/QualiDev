#pragma once

#include "observer.h"
#include "promotion.h"

#include <QGroupBox>

/**
 * @brief The ViewForms class, classe de vue pour le graphique en camembert, obvservateur
 */
class ViewPieChart   : public Observer
{
private:
    /**
     * @brief promotion pointeur vers les donnees
     */
    Promotion* promotion;
    /**
     * @brief box pointeur vers la box qui doit contenir le graphique
     */
    QGroupBox *box;

public:
    /**
     * @brief ViewPieChart constructeur
     * @param promotion pointeur vers les donnees
     * @param box pointeur vers la box qui doit contenir le graphique
     */
    ViewPieChart(Promotion *promotion, QGroupBox *box);
    /**
     * @brief refresh fonction appeler par l'observateur, refresh la vue
     */
    void refresh() override;
};

