#ifndef PIECHART_H
#define PIECHART_H

#include "abstractchartview.h"

/**
 * @brief The PieChart class, class de la vue camembers
 */
class PieChart : public AbstractChartView
{
public:
    /**
     * @brief PieChart, constructeur (vide)
     */
    PieChart();
    /**
     * @brief getChartView Fonction qui renvoi le `QWidget*` qui correspond à la vue camembers
     * @param data La source des données
     * @return `QWidget*` qui correspond à la vue camembers
     */
    QWidget *getChartView(Data *data);
};

#endif // PIECHART_H
