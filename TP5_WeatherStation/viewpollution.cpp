#include "viewpollution.h"
#include <QDebug>
#include <QDateTime>

ViewPollution::ViewPollution(DbManager* dbm, QWidget* widget) :dbm(dbm), widget(widget)
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

    // example on how to convert DateTime to Unix,UTC in milliseconds
    QDateTime currentdt = QDateTime::currentDateTime();
    qint64 msdt = currentdt.toMSecsSinceEpoch();
    qDebug() << currentdt << " " << QDateTime::fromMSecsSinceEpoch(msdt);

    // generate some mock values
    // get current time, and add 1 hour (3600000ms) to get next X entry
    // Warning, OpenWeatherMap provides dt in seconds
    // => so they will be registered in seconds into the DB...
    // => you will need to convert to milliseconds (*1000.) before to append

    QList<int*>* datas=dbm->getAllData();

    int min=datas->at(0)[0];
    int max=min;
    for(int* data: *datas){
        if(data[0]<min) min=data[0];
        else if(data[0]>max) max=data[0];
        series->append(data[0], data[1]);
        delete data;
    }
    delete datas;

    // Compute min,max and update axis Ranges
    // Otherwise repaint() will no update the curve ;(
    QDateTime dt0;
    dt0.setMSecsSinceEpoch(min); //xmin for mock values
    QDateTime dt1;
    dt1.setMSecsSinceEpoch(max); //xmax
    axisX->setRange( dt0,dt1);
    axisY->setRange(-5,9); //ymin,ymax (do not change for these mock values)

    widget->repaint();
}
