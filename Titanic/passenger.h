#ifndef PASSENGER_H
#define PASSENGER_H

#include <QString>

/**
 * @brief The Passenger class
 */
class Passenger
{
public:
    Passenger();
    Passenger(const QString &iden, int classe, int age, int sexe, int survived);
private:
    QString iden;
    int classe;
    int age;
    int sexe;
    int survived;
};

#endif // PASSENGER_H
