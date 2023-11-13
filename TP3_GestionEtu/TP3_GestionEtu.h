#pragma once

#include <QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewformsdelete.h"
#include "viewPieChart.h"
#include "viewHistogram.h"

class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    TP3_GestionEtu(QWidget *parent = nullptr, Promotion* promotion=nullptr);
    ~TP3_GestionEtu() {delete promotion;}
private:
    Ui::TP3_GestionEtuClass ui;
    Promotion* promotion;

    ViewList* listView;
    ViewForms* listForm;
    ViewFormsDelete* listFormDelete;
    ViewPieChart* pieChartView;
    ViewHistogram* histogramView;
};
