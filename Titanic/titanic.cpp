#include "titanic.h"
#include "piechart.h"
#include "ui_titanic.h"

#include <BarChartView.h>
#include <HorizontalChartWiew.h>

Titanic::Titanic(Data* data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Titanic)
    , data(data)
{
    ui->setupUi(this);
    connect(ui->actionRatio_H_F, SIGNAL(triggered()), this, SLOT(actionRatio_H_F()));
    connect(ui->actionCategorie, SIGNAL(triggered()), this, SLOT(actionCategorie()));
    connect(ui->actionAgeCategorie, SIGNAL(triggered()), this, SLOT(actionAgeCategorie()));
}

Titanic::~Titanic()
{
    delete ui;
}

void Titanic::actionRatio_H_F()
{
    chartView=std::make_unique<PieChart>();
    this->setCentralWidget(chartView->getChartView(data));
}

void Titanic::actionCategorie()
{
    chartView=std::make_unique<BarChartView>();
    this->setCentralWidget(chartView->getChartView(data));
}

void Titanic::actionAgeCategorie()
{
    chartView=std::make_unique<HorizontalChartWiew>();
    this->setCentralWidget(chartView->getChartView(data));
}


