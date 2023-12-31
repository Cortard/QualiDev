#include "viewreport.h"
#include "dbmanager.h"

ViewReport::ViewReport(WeatherReport *wreport, Ui::TP5_WeatherStationClass *ui, QString* city)
    : model(wreport), ui(ui), city(city)
{
    init();
    ViewReport::update();
}

void ViewReport::init()
{
    ui->lineEdit_temp->clear();
    ui->lineEdit_temp->setReadOnly(1);
    ui->lineEdit_temp_min->clear();
    ui->lineEdit_temp_min->setReadOnly(1);
    ui->lineEdit_temp_max->clear();
    ui->lineEdit_temp_max->setReadOnly(1);
    ui->lineEdit_lon->clear();
    ui->lineEdit_lon->setReadOnly(1);
    ui->lineEdit_lat->clear();
    ui->lineEdit_lat->setReadOnly(1);
    ui->lineEdit_description->clear();
    ui->lineEdit_description->setReadOnly(1);
    ui->label_8->setText(*city);
}

void ViewReport::update()
{
    ui->lineEdit_temp->setText(QString::number(model->getTemp()));
    ui->lineEdit_temp_min->setText(QString::number(model->getTempMin()));
    ui->lineEdit_temp_max->setText(QString::number(model->getTempMax()));
    ui->lineEdit_lon->setText(QString::number(model->getLon()));
    ui->lineEdit_lat->setText(QString::number(model->getLat()));
    ui->lineEdit_description->setText(model->getDescription());
    ui->label_8->setText(*city);
}
