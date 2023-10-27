#include "titanic.h"

#include <QApplication>
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
    data->readData();
    QApplication a(argc, argv);
    Titanic w(data);
    w.show();
    return a.exec();
}
