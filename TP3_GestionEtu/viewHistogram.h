#pragma once

#include "observer.h"
#include "promotion.h"

#include <QGroupBox>

/**
 * @brief The ViewHistogram class, classe de vue pour le graphique en barre, obvservateur
 */
class ViewHistogram   : public Observer
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
     * @brief ViewHistogram constructeur
     * @param promotion pointeur vers les donnees
     * @param box pointeur vers la box qui doit contenir le graphique
     */
    ViewHistogram(Promotion *promotion, QGroupBox *box);
    /**
     * @brief refresh fonction appeler par l'observateur, refresh la vue
     */
    void refresh() override;
};

