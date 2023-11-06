#include "data.h"

#include <QFile>
#include <QDir>

Data::Data()
{

}

bool Data::readData(QString path)
{

    QList<QString> extensions={".dbf"};
    if(!verifExtension(path,extensions))
        return false;

    QFile file(path);
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

bool Data::verifExtension(QString path, QList<QString> extension)
{
    for(QString type : extension)
        if(path.contains(type)) return true;
    return false;
}
