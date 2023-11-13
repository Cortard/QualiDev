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


public:
    ViewForms(Promotion *promotion, QLineEdit *numero, QLineEdit *prenom, QLineEdit *nom, QComboBox *departement, QComboBox *bac);
    void refresh() override;

 public slots:
    void addEtu();
};

