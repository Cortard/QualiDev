#include "promotion.h"

#include <QFile>
#include <QDir>

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
        students.append(new Student(l.at(0).toInt(),l.at(1),l.at(2),l.at(3),l.at(4)));
    }
    return true;
}
