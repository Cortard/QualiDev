#include "observer.h"
#include "promotion.h"

#include <QLineEdit>
#include <QObject>
#include <QComboBox>

#pragma once

class ViewForms  : public QObject, public Observer
{
    Q_OBJECT
private:
    Promotion* promotion;
    QLineEdit* numero;
    QLineEdit* prenom;
    QLineEdit* nom;
    QComboBox* departement;
    QComboBox* bac;

    virtual void refresh();

public:
    ViewForms();
    ViewForms(Promotion *promotion, QLineEdit *numero, QLineEdit *prenom, QLineEdit *nom, QComboBox *departement, QComboBox *bac);
public slots:
    void addEtu();
};

