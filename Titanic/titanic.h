#ifndef TITANIC_H
#define TITANIC_H

#include <QMainWindow>
#include "abstractchartview.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Titanic; }
QT_END_NAMESPACE

class Titanic : public QMainWindow
{
    Q_OBJECT

public:
    Titanic(Data* data, QWidget *parent = nullptr);
    ~Titanic();

private slots:
    void actionRatio_H_F();

private:
    Ui::Titanic *ui;
    Data* data;
    QScopedPointer<AbstractChartView> chartWiew();
};
#endif // TITANIC_H
