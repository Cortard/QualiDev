#include "titanic.h"

#include <QApplication>
#include "data.h"

int main(int argc, char *argv[])
{
    Data* data = new Data;
    qDebug()<<data->readData();
    QApplication a(argc, argv);
    Titanic w(data);
    w.show();
    return a.exec();
}
