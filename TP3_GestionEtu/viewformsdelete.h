#ifndef VIEWFORMSDELETE_H
#define VIEWFORMSDELETE_H

#include "observer.h"
#include "promotion.h"

#include <QLineEdit>
#include <QObject>

class ViewFormsDelete  : public QObject, public Observer
{
    Q_OBJECT
private :
    Promotion* promotion;
    QLineEdit* numero;

public:
    ViewFormsDelete(Promotion *promotion, QLineEdit *numero);
    void refresh() override;

public slots:
    void deleteEtu();
};

#endif // VIEWFORMSDELETE_H
