#ifndef TITANIC_H
#define TITANIC_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Titanic; }
QT_END_NAMESPACE

class Titanic : public QMainWindow
{
    Q_OBJECT

public:
    Titanic(QWidget *parent = nullptr);
    ~Titanic();

private:
    Ui::Titanic *ui;
};
#endif // TITANIC_H
