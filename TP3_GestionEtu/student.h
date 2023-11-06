#include <QString>

#pragma once

class Student
{
private:
    int numero;
    QString prenom;
    QString nom;
    QString departement;
    QString bac;


public: 
    Student();
    Student(int numero, const QString &prenom, const QString &nom, const QString &departement, const QString &bac);
    QString toQstring();
    int getNumero() const;
};

