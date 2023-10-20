#include "passenger.h"

Passenger::Passenger()
{

}

Passenger::Passenger(const QString &iden, int classe, int age, int sexe, int survived) : iden(iden),
    classe(classe),
    age(age),
    sexe(sexe),
    survived(survived)
{}

int Passenger::getSexe() const
{
    return sexe;
}
