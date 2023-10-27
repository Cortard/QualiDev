#include "barchartview.h"

#include <QBarCategoryAxis>
#include <QBarSeries>
#include <QBarSet>
#include <QChart>
#include <QChartView>
#include <QValueAxis>

BarChartView::BarChartView()
{

}

QWidget *BarChartView::getChartView(Data *data)
{
    auto peri = new QBarSet("Péri");
    auto survivant = new QBarSet("Survivant");

    int value[4][2]={{0,0},{0,0},{0,0},{0,0}};
    for(Passenger passenger : data->passengers)
        ++value[passenger.getClasse()][passenger.getSurvived()];

    for(int i=0; i<4; i++){
        *peri<<value[i][0];
        *survivant<<value[i][1];
    }

    QBarSeries *series = new QBarSeries;
    series->append(peri);
    series->append(survivant);

    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Survivant categorie");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories {"Crew", "First", "Second", "Third"};
    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QValueAxis;
    axisY->setRange(0,673);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    return chartView;
}
