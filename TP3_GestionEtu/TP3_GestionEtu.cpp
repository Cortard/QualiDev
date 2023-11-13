#include "TP3_GestionEtu.h"

TP3_GestionEtu::TP3_GestionEtu(QWidget *parent, Promotion* promotion)
    : QMainWindow(parent),
    promotion(promotion)
{
    ui.setupUi(this);

    listView=new ViewList(promotion, ui.listWidget);
    promotion->addObserveur(listView);
    connect(ui.pushButton_delete_list, SIGNAL(clicked()), listView, SLOT(deleteEtu()));

    listForm=new ViewForms(promotion, ui.lineEdit_add_number, ui.lineEdit_add_firstname, ui.lineEdit_add_lastname, ui.lineEdit_add_department, ui.lineEdit_add_BAC);
    promotion->addObserveur(listForm);
    connect(ui.pushButton_addStudent, SIGNAL(clicked()), listForm, SLOT(addEtu()));

    listFormDelete=new ViewFormsDelete(promotion, ui.lineEdit_remove_number);
    promotion->addObserveur(listFormDelete);
    connect(ui.pushButton_delete_number, SIGNAL(clicked()), listFormDelete, SLOT(deleteEtu()));

    pieChartView=new ViewPieChart(promotion, ui.groupBox_department);
    promotion->addObserveur(pieChartView);

    histogramView= new ViewHistogram(promotion, ui.groupBox_bacs);
    promotion->addObserveur(histogramView);

    promotion->notify();
}
