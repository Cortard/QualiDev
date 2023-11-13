#pragma once

#include "promotion.h"

#include <QListWidget>
#include "observer.h"

/**
 * @brief The ViewList class, classe de vue pour la liste, observable
 */
class ViewList : public QObject, public Observer
{
    Q_OBJECT
private:
    /**
     * @brief promotion pointeur vers les donnees
     */
    Promotion* promotion;
    /**
     * @brief listView pointeur vers la liste ou afficher les donnes
     */
    QListWidget* listView;

public:
    /**
     * @brief ViewList constructeur
     * @param promotion pointeur vers les donnees
     * @param listView pointeur vers la liste ou afficher les donnes
     */
    ViewList(Promotion *promotion, QListWidget *listView);
    /**
     * @brief refresh fonction appeler par l'observateur, refresh la vue
     */
    void refresh() override;

public slots:
    /**
     * @brief deleteEtu fonction trigger par le bouton sous la liste
     */
    void deleteEtu();
};

