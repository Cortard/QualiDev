#ifndef DATA_H
#define DATA_H

#include "passenger.h"
#include "QList"

class Data
{
public:
    Data();
    bool readData();
private:
    QList<Passenger> passengers;
};

#endif // DATA_H
