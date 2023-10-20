#include "data.h"

#include <QFile>
#include <QDir>

Data::Data()
{

}

bool Data::readData()
{
    QFile file(QDir::currentPath()+"/../titanic/titanic.dbf");
    if (! file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return false;
    }
    QTextStream stream(&file);
    try {
        for(int i=0;i<5;i++)
        stream.readLine();
        QString iden;
        int classe;
        int age;
        int sexe;
        int survived;
        while(! stream.atEnd()){
            stream>>iden>>classe>>age>>sexe>>survived;
            this->passengers.append(Passenger(iden,classe,age,sexe,survived));
        }
    }catch(...){
        return false;
    }
    return true;
}
