#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include "abstractchartview.h"


/**
 * @brief The BarChartView class, class de la vue des bars verticale
 */
class BarChartView : public AbstractChartView
{
public:
    /**
     * @brief BarChartView, constructeur (vide)
     */
    BarChartView();
    /**
     * @brief getChartView Fonction qui renvoi le `QWidget*` qui correspond à la vue des bars verticale.
     * @param data La source des données
     * @return `QWidget*` qui correspond à la vue des bars verticale
     */
    QWidget *getChartView(Data *data);
};

#endif // BARCHARTVIEW_H
