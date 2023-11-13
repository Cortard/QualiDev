#include "viewHistogram.h"

#include <QChart>
#include <QVBoxLayout>
#include <QChart>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QChartView>

ViewHistogram::ViewHistogram(Promotion *promotion, QGroupBox *box) : promotion(promotion),
    box(box)
{
}

void ViewHistogram::refresh()
{
    if(box->layout()!=nullptr)
        delete box->layout();

    QBarSeries *series = promotion->getNumberByBac();

    auto chart = new QChart;
    chart->addSeries(series);
    chart->setTitle("Serie de bacs");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    QStringList categories {"Bacs"};
    auto axisX = new QBarCategoryAxis;
    axisX->append(categories);
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    auto axisY = new QValueAxis;
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(chartView);

    box->setLayout(vbox);
}
