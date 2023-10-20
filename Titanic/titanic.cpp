#include "titanic.h"
#include "piechart.h"
#include "ui_titanic.h"

Titanic::Titanic(Data* data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Titanic)
    , data(data)
{
    ui->setupUi(this);
    connect(ui->actionRatio_H_F, SIGNAL(triggered()), this, SLOT(actionRatio_H_F()));
}

Titanic::~Titanic()
{
    delete ui;
}

void Titanic::actionRatio_H_F()
{
    chartWiew().reset(new PieChart())
    this->setCentralWidget(chartView.getChartView(data));
}


