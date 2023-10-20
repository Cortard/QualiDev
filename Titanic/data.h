#ifndef DATA_H
#define DATA_H

#include "passenger.h"
#include "QList"

class Data
{
public:
    Data();
    bool readData();
    QList<Passenger> passengers;
};

#endif // DATA_H
