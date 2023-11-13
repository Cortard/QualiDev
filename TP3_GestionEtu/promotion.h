#include <QBarSeries>
#include <QList>
#include <QPieSeries>
#include "student.h"
#include "observable.h"

#pragma once

/**
 * @brief The Promotion class des donnes, observable
 */
class Promotion : public Observable
{
public:
    /**
     * @brief students liste des etudiants
     */
    QList<Student*> students;

    /**
     * @brief Promotion constructeur
     */
    Promotion();
    /**
     * @brief Promotion destructeur
     */
    ~Promotion();
    /**
     * @brief loadFileCSV charge les donnees sous forme csv au path : ./data/promoDUT.csv
     * @return
     */
    bool loadFileCSV();

    /**
     * @brief exist verifie si un etudiant existe deja
     * @param etudiant numero de l'etudiant
     * @return -1 s'il n'existe pas, son rang dans la liste des donnes sinon
     */
    int exist(int etudiant);
    /**
     * @brief exist verifie si un etudiant existe deja
     * @param etudiant etudiant.toQstring() de l'etudiant a chercher
     * @return -1 s'il n'existe pas, son rang dans la liste des donnes sinon
     */
    int exist(QString etudiant);
    /**
     * @brief addEtu ajout un etudiant
     * @param numero nouveau numero de l'etudiant
     * @param prenom prenom de l'etudiant
     * @param nom nom de l'etudiant
     * @param bac type du bac de l'etudiant
     * @param departement departement de l'etudiant
     */
    void addEtu(int numero,QString prenom,QString nom,QString bac,QString departement);
    /**
     * @brief deleteEtu surpprime un etudiant
     * @param numEtu numero de l'etudiant
     */
    void deleteEtu(int numEtu);
    /**
     * @brief deleteEtu surpprime un etudiant
     * @param rank rang de l'etudiant dans la liste des donnes
     */
    void deleteEtu(int rank, bool);

    /**
     * @brief getNumberByDepartement renvoi le nombre d'etudiant par departement, s'il n'a aucun etudiant, le departement n'es pas cité
     * @return QPieSeries* series pour un diagramme camambert qt
     */
    QPieSeries* getNumberByDepartement();
    /**
     * @brief getNumberByBac renvoi le nombre d'etudiant par bac, s'il n'a aucun etudiant, le bac n'es pas cité
     * @return QBarSeries* series pour un diagramme en barre qt
     */
    QBarSeries* getNumberByBac();
};

