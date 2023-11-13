#include "viewForms.h"
#include "controllercreator.h"

ViewForms::ViewForms(Promotion *promotion, QLineEdit *numero, QLineEdit *prenom, QLineEdit *nom, QComboBox *departement, QComboBox *bac) : promotion(promotion),
    numero(numero),
    prenom(prenom),
    nom(nom),
    departement(departement),
    bac(bac)
{
}

void ViewForms::addEtu()
{
    QStringList input={};
    input<<numero->text()<<prenom->text()<<nom->text()<<bac->currentText()<<departement->currentText();
    Controller* controller = ControllerCreator::Controller(promotion, &input);
    int res= controller->action();
    if(res==-1)
        numero->clear();
    delete controller;
}

void ViewForms::refresh()
{
    numero->clear();
    nom->clear();
    prenom->clear();

    bac->clear();
    QStringList bacs;
    bacs<<"S"<<"ES"<<"STI"<<"L"<<"STI"<<"Etr"<<"Autre";
    for(QString nom : bacs)
        bac->addItem(nom);

    departement->clear();
    for(unsigned char i=1;i<=96;++i)
        departement->addItem(QString::number(i));
    for(int i=971;i<=976;++i)
        departement->addItem(QString::number(i));
    departement->addItem("AUTRE");
}

