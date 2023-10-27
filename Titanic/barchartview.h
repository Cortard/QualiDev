#ifndef BARCHARTVIEW_H
#define BARCHARTVIEW_H

#include "abstractchartview.h"



class BarChartView : public AbstractChartView
{
public:
    BarChartView();
    QWidget *getChartView(Data *data);
};

#endif // BARCHARTVIEW_H
