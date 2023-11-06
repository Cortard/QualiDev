#include "titanic.h"

#include <QApplication>
#include <QDir>
#include "data.h"

/**
 * @brief main Main Class
 * @param argc default param
 * @param argv default param
 * @return Execution of window
 */
int main(int argc, char *argv[])
{
    Data* data = new Data;
    qDebug()<<data->readData(QDir::currentPath()+"/../titanic/titanic.dbf");
    QApplication a(argc, argv);
    Titanic w(data);
    w.show();
    return a.exec();
}
