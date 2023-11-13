#include "student.h"


Student::Student(int numero, const QString &prenom, const QString &nom, const QString &departement, const QString &bac) : numero(numero),
    prenom(prenom),
    nom(nom),
    departement(departement),
    bac(bac)
{}

QString Student::toQstring()
{
    return QString::number(numero)+" - "+nom+" "+prenom+" ("+departement+")";
}

int Student::getNumero() const
{
    return numero;
}

QString Student::getDepartement() const
{
    return departement;
}

QString Student::getBac() const
{
    return bac;
}
