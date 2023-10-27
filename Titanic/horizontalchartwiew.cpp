#include "horizontalchartwiew.h"
#include "qpainter.h"

#include <QBarCategoryAxis>
#include <QBarSet>
#include <QChart>
#include <QChart>
#include <QChartView>
#include <QGridLayout>
#include <QHorizontalStackedBarSeries>
#include <QValueAxis>
#include <QWidget>

HorizontalChartWiew::HorizontalChartWiew()
{

}


QWidget *HorizontalChartWiew::getChartView(Data *data)
{
    QGridLayout *gridlayout= new QGridLayout();

    QChartView* charts[2];

    top(data,charts);
    gridlayout->addWidget(charts[0],0,0);
    gridlayout->addWidget(charts[1],0,1);
    bottom(data,charts);
    gridlayout->addWidget(charts[0],1,0);
    gridlayout->addWidget(charts[1],1,1);

    QWidget *widget = new QWidget();
    widget->setLayout(gridlayout);
    return widget;
}

void HorizontalChartWiew::top(Data *data, QChartView* res[2])
{

    auto peri = new QBarSet("Péri");
    auto survecu = new QBarSet("Survécu");
    auto population = new QBarSet("Population");

    int value[4][3]={{0,0,0},{0,0,0},{0,0,0},{0,0,0}};
    for(Passenger passenger : data->passengers){
        ++value[passenger.getClasse()][passenger.getSurvived()];
        ++value[passenger.getClasse()][2];
    }
    for(int i=0; i<4; i++){
        *peri<<value[i][0];
        *survecu<<value[i][1];
        *population<<value[i][2];
    }

    auto *seriesSimple = new QHorizontalStackedBarSeries;
    seriesSimple->append(population);

    auto *seriesDouble = new QHorizontalStackedBarSeries;
    seriesDouble->append(peri);
    seriesDouble->append(survecu);

    auto chartSimple = new QChart;
    chartSimple->addSeries(seriesSimple);
    chartSimple->setTitle("Population/Catégorie");
    chartSimple->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories {"Troisème", "Deuxième", "Première", "Equipage"};
    auto axisYSimple = new QBarCategoryAxis;
    axisYSimple->append(categories);
    chartSimple->addAxis(axisYSimple, Qt::AlignLeft);
    seriesSimple->attachAxis(axisYSimple);
    auto axisXSimple = new QValueAxis;
    axisXSimple->setRange(0,885);
    chartSimple->addAxis(axisXSimple, Qt::AlignBottom);
    seriesSimple->attachAxis(axisXSimple);
    chartSimple->legend()->setVisible(true);
    chartSimple->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartViewSimple = new QChartView(chartSimple);
    chartViewSimple->setRenderHint(QPainter::Antialiasing);

    auto chartDouble = new QChart;
    chartDouble->addSeries(seriesDouble);
    chartDouble->setTitle("Survivant/Catégorie");
    chartDouble->setAnimationOptions(QChart::SeriesAnimations);
    auto axisYDouble = new QBarCategoryAxis;
    axisYDouble->append(categories);
    chartDouble->addAxis(axisYDouble, Qt::AlignLeft);
    seriesDouble->attachAxis(axisYDouble);
    auto axisXDouble = new QValueAxis;
    axisXDouble->setRange(0,885);
    chartDouble->addAxis(axisXDouble, Qt::AlignBottom);
    seriesDouble->attachAxis(axisXDouble);
    chartDouble->legend()->setVisible(true);
    chartDouble->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartViewDouble = new QChartView(chartDouble);
    chartViewDouble->setRenderHint(QPainter::Antialiasing);

    res[0]=chartViewSimple;
    res[1]=chartViewDouble;
    return;
}

void HorizontalChartWiew::bottom(Data *data, QChartView* res[2])
{
    auto peri = new QBarSet("Péri");
        auto survecu = new QBarSet("Survécu");
        auto population = new QBarSet("Population");

    int value[2][3]={{0,0,0},{0,0,0}};
    for(Passenger passenger : data->passengers){
        ++value[passenger.getAge()][passenger.getSurvived()];
        ++value[passenger.getAge()][2];
    }
    for(int i=0; i<2; i++){
        *peri<<value[i][0];
        *survecu<<value[i][1];
        *population<<value[i][2];
    }

    auto *seriesSimple = new QHorizontalStackedBarSeries;
    seriesSimple->append(population);

    auto *seriesDouble = new QHorizontalStackedBarSeries;
    seriesDouble->append(peri);
    seriesDouble->append(survecu);

    auto chartSimple = new QChart;
    chartSimple->addSeries(seriesSimple);
    chartSimple->setTitle("Population/Âge");
        chartSimple->setAnimationOptions(QChart::SeriesAnimations);
    QStringList categories {"Adule", "Enfant"};
    auto axisYSimple = new QBarCategoryAxis;
    axisYSimple->append(categories);
    chartSimple->addAxis(axisYSimple, Qt::AlignLeft);
    seriesSimple->attachAxis(axisYSimple);
    auto axisXSimple = new QValueAxis;
    axisXSimple->setRange(0,2092);
    chartSimple->addAxis(axisXSimple, Qt::AlignBottom);
    seriesSimple->attachAxis(axisXSimple);
    chartSimple->legend()->setVisible(true);
    chartSimple->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartViewSimple = new QChartView(chartSimple);
    chartViewSimple->setRenderHint(QPainter::Antialiasing);

    auto chartDouble = new QChart;
    chartDouble->addSeries(seriesDouble);
    chartDouble->setTitle("Survivant/Âge");
        chartDouble->setAnimationOptions(QChart::SeriesAnimations);
    auto axisYDouble = new QBarCategoryAxis;
    axisYDouble->append(categories);
    chartDouble->addAxis(axisYDouble, Qt::AlignLeft);
    seriesDouble->attachAxis(axisYDouble);
    auto axisXDouble = new QValueAxis;
    axisXDouble->setRange(0,2092);
    chartDouble->addAxis(axisXDouble, Qt::AlignBottom);
    seriesDouble->attachAxis(axisXDouble);
    chartDouble->legend()->setVisible(true);
    chartDouble->legend()->setAlignment(Qt::AlignBottom);
    QChartView *chartViewDouble = new QChartView(chartDouble);
    chartViewDouble->setRenderHint(QPainter::Antialiasing);

    res[0]=chartViewSimple;
    res[1]=chartViewDouble;
    return;
}
