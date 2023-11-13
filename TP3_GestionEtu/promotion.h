#include <QBarSeries>
#include <QList>
#include <QPieSeries>
#include "student.h"
#include "observable.h"

#pragma once


class Promotion : public Observable
{
public:
    QList<Student*> students;

	Promotion();
    ~Promotion();
    bool loadFileCSV();

    int exist(int etudiant);
    int exist(QString etudiant);
    void addEtu(int numero,QString prenom,QString nom,QString bac,QString departement);
    void deleteEtu(int numEtu);
    void deleteEtu(int rank, bool);

    QPieSeries* getNumberByDepartement();
    QBarSeries* getNumberByBac();
};

