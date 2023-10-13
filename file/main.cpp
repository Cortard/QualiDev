#include <iostream>
#include <QList>
#include <QDebug>
#include <QFile>
#include <QDir>


int main()
{
    QList<uchar> impairs(100);
    QList<uchar>::iterator iterator = impairs.begin();
    *iterator=1;
    for(; iterator!=impairs.end();){
        *iterator=(*iterator++)+2;
    }

    QFile file(QDir::currentPath()+"/out.txt");
    if (!file.open(QIODeviceBase::ReadWrite)){
        std::cout<<"file not open";
        return 2;
    }

    QTextStream out(&file);
    foreach (uchar number, impairs) {
        out<<number<<" "<<number*number<<"\n";
    }

    uchar i =0;
    QTextStream in(&file);
    int carre, v;
    while (! in.atEnd()){
        in >> v >> carre;
        std::cout << (int)i <<" : "<< carre<< std::endl;
        i++;
    }

    return 0;
}
