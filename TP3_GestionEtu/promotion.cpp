#include "promotion.h"

#include <QFile>
#include <QDir>
#include <QBarSet>

Promotion::Promotion()
{
}

Promotion::~Promotion()
{
    for(Student* student : students) delete student;
    students.clear();
}

bool Promotion::loadFileCSV()
{
    QFile file(QDir::currentPath()+"/../TP3_GestionEtu/data/promoDUT.csv");
    if (! file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }
    QTextStream stream(&file);
    while(!file.atEnd()){
        QString line =file.readLine();
        QStringList l = line.split(";");
        students.append(new Student(l.at(0).toInt(),l.at(1),l.at(2),l.at(3),l.at(4).split("\n").at(0)));
    }
    return true;
}

int Promotion::exist(int etudiant)
{
    int i=0;
    for(Student* student : students){
        if(student->getNumero()==etudiant)
            return i;
        ++i;
    }
    return -1;
}

int Promotion::exist(QString etudiant)
{
    return exist(etudiant.mid(0,3).toInt());
}

void Promotion::addEtu(int numero, QString prenom, QString nom, QString bac, QString departement)
{
    students.append(new Student(numero,prenom,nom,departement,bac));
}

void Promotion::deleteEtu(int rank, bool)
{
    students.removeAt(rank);
}

void Promotion::deleteEtu(int numEtu)
{
    int rank=exist(numEtu);
    if(rank==-1) return;
    deleteEtu(rank);
}


QPieSeries *Promotion::getNumberByDepartement()
{
    int LENGTH=97+6+1;
    int* stats= new int[LENGTH];
    for(int i=0;i<LENGTH;++i)stats[i]=0;

    for(Student* student : students){
        QString dep=student->getDepartement();
        if(dep=="AUTRE") ++stats[LENGTH-1];
        int depNum=dep.toInt();
        if(depNum<=96) ++stats[depNum];
        else ++stats[depNum-873];
    }

    QPieSeries *series = new QPieSeries();
    for(int i=0;i<LENGTH;++i)
        if(stats[i]!=0){
            if(i<=96)
                series->append(QString::number(i),stats[i]);
            else if(i==LENGTH-1)
                series->append("AUTRE",stats[i]);
            else series->append(QString::number(i+873),stats[i]);
        }

    return series;
}

QBarSeries *Promotion::getNumberByBac()
{
    QMap<QString, int> stats;

    QStringList bacs;
    bacs<<"S"<<"ES"<<"STI"<<"L"<<"STI"<<"Etr"<<"Autre";
    for(QString bac : bacs)
        stats.insert("bac",0);

    for(Student* student : students){
        ++stats[student->getBac()];
    }

    QBarSeries *series = new QBarSeries;
    for(QString bac : bacs){
        if(stats[bac]!=0){
            auto set = new QBarSet(bac);
            *set<<stats[bac];
            series->append(set);
        }
    }

    return series;
}
