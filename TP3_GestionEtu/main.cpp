#include "TP3_GestionEtu.h"
#include "promotion.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Promotion
    Promotion* promo;
    promo=new Promotion();
    qDebug()<<promo->loadFileCSV();

    // Create Interface
    TP3_GestionEtu w(nullptr,promo);
    w.show();

    return a.exec();
}
