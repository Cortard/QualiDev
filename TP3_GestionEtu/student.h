#include <QString>

#pragma once

/**
 * @brief The Student class class etudiant, contient les donnes d'un etudiant
 */
class Student
{
private:
    /**
     * @brief numero numero de l'etudiant
     */
    int numero;
    /**
     * @brief prenom prenom de l'etudiant
     */
    QString prenom;
    /**
     * @brief nom nom de l'etudiant
     */
    QString nom;
    /**
     * @brief departement departement de l'etudiant
     */
    QString departement;
    /**
     * @brief bac type du bac de l'etudiant
     */
    QString bac;


public:
    /**
     * @brief Student cree un nouvel etudian
     * @param numero numero de l'etudiant
     * @param prenom prenom de l'etudiant
     * @param nom nom de l'etudiant
     * @param departement departement de l'etudiant
     * @param bac type du bac de l'etudiant
     */
    Student(int numero, const QString &prenom, const QString &nom, const QString &departement, const QString &bac);
    /**
     * @brief toQstring renvoi les informations sous forme de SQtring
     * @return de la forme : "numero - nom prenom (departement)"
     */
    QString toQstring();
    /**
     * @brief getNumero renvoi le numero de l'etudiant
     * @return numero de l'etudiant
     */
    int getNumero() const;
    /**
     * @brief getDepartement renvoi le departement de l'etudiant
     * @return departement de l'etudiant
     */
    QString getDepartement() const;
    /**
     * @brief getBac renvoi le bac de l'etudiant
     * @return bac de l'etudiant
     */
    QString getBac() const;
};

