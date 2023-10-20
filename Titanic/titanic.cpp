#include "titanic.h"
#include "ui_titanic.h"

Titanic::Titanic(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Titanic)
{
    ui->setupUi(this);
}

Titanic::~Titanic()
{
    delete ui;
}

