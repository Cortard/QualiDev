#include "piechart.h"

#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>


PieChart::PieChart()
{

}

QWidget *PieChart::getChartView(Data *data)
{
    //female , male
    int nb[] {0,0} ;

    for(Passenger passenger : data->passengers)
        ++nb[passenger.getSexe()];

    QPieSeries *series = new QPieSeries();
    series->append("Femme", nb[0]);
    series->append("Homme", nb[1]);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Ratio H/F dans le titanic :");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
