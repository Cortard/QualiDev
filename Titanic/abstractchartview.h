#ifndef ABSTRACTCHARTVIEW_H
#define ABSTRACTCHARTVIEW_H

#include <QWidget>
#include "data.h"

/**
 * @brief The AbstractChartView class, une classe abstraite qui permet le mise en place de la strategie
 */
class AbstractChartView
{
public:
    /**
     * @brief AbstractChartView, constructeur (vide)
     */
    AbstractChartView();
    /**
     * @brief getChartView Fonction qui renvoi le `QWidget*` qui correspond à la vue choisie. Méthode abstraite
     * @param data La source des données
     * @return `QWidget*` qui correspond à la vue choisie
     */
    virtual QWidget* getChartView(Data *data)=0;
};

#endif // ABSTRACTCHARTVIEW_H
