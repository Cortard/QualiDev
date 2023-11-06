#include "viewForms.h"

ViewForms::ViewForms()
{
}

ViewForms::ViewForms(Promotion *promotion, QLineEdit *numero, QLineEdit *prenom, QLineEdit *nom, QComboBox *departement, QComboBox *bac) : promotion(promotion),
    numero(numero),
    prenom(prenom),
    nom(nom),
    departement(departement),
    bac(bac)
{
    refresh();
}

void ViewForms::addEtu()
{

}

void ViewForms::refresh()
{
    bac->addItem("S");
    bac->addItem("ES");
    bac->addItem("STI");

    for(unsigned char i=1;i<=95;++i)
        departement->addItem(QString::number(i));
    for(int i=971;i<=976;++i)
        departement->addItem(QString::number(i));
    departement->addItem("AUTRE");
}

