#include "titanic.h"

#include <QApplication>
#include "data.h"

int main(int argc, char *argv[])
{
    Data data;
    qDebug()<<data.readData();
    QApplication a(argc, argv);
    Titanic w;
    w.show();
    return a.exec();
}
