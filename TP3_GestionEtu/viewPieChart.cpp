#include "viewPieChart.h"

#include <QChart>
#include <QChartView>
#include <QPieSeries>
#include <QVBoxLayout>

ViewPieChart::ViewPieChart(Promotion *promotion, QGroupBox *box) : promotion(promotion),
    box(box)
{
}

void ViewPieChart::refresh()
{
    if(box->layout()!=nullptr)
        delete box->layout();

    QPieSeries *series = promotion->getNumberByDepartement();

    for(QPieSlice* slice : series->slices()){
        slice->setLabelVisible();
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Répartition géographique");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(chartView);

    box->setLayout(vbox);
}
