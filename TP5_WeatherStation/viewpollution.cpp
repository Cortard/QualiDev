#include "viewpollution.h"
#include <QDebug>
#include <QDateTime>

ViewPollution::ViewPollution(DbManager* dbm, QWidget* widget, QString* city) :dbm(dbm), widget(widget), city(city)
{
    series = new QLineSeries();

    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("Simple date/line chart example");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    //    chart->createDefaultAxes();
    axisX = new QDateTimeAxis;
    axisX->setTickCount(10);
    axisX->setFormat("HH:mm");
    axisX->setTitleText("Date");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    axisY = new QValueAxis;
    axisY->setLabelFormat("%i");
    axisY->setTitleText("Air Quality Indice");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    QGridLayout *chartLayout = new QGridLayout;
    chartLayout->addWidget(chartView, 0, 0);
    chartLayout->setContentsMargins(0, 0, 0, 0);

    // update chart
    widget->setLayout(chartLayout);

    ViewPollution::update();
}

void ViewPollution::update()
{
    series->clear();

    QList<int*>* datas=dbm->getAllData(*city);

    if (datas->empty()) {
        qDebug() << "No data available.";
        return;
    }

    int min=datas->at(0)[0];
    int max=min;
    for(int* data: *datas){
        if(data[0]<min) min=data[0];
        else if(data[0]>max) max=data[0];
        series->append(data[0]*1000., data[1]);
        delete data;
    }
    delete datas;

    QDateTime dt0;
    dt0.setSecsSinceEpoch(min);
    QDateTime dt1;
    dt1.setSecsSinceEpoch(max);
    axisX->setRange( dt0,dt1);
    axisY->setRange(0,5); //ymin,ymax (do not change for these mock values)

    widget->repaint();
}
