#ifndef PIECHART_H
#define PIECHART_H

#include "abstractchartview.h"

class PieChart : AbstractChartView
{
public:
    PieChart();
    QWidget *getChartView(Data *data);
};

#endif // PIECHART_H
