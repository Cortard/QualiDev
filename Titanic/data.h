#ifndef DATA_H
#define DATA_H

#include "passenger.h"
#include "QList"

/**
 * @brief The Data class, classe qui contient le jeu de données
 */
class Data
{
public:
    /**
     * @brief Data, constructeur (vide)
     */
    Data();
    /**
     * @brief readData, lit les data qui sont dans un fichier dont le path est ecrit en dur
     * @return bool, ouverture et recuperation des données effectuees avec succes
     */
    bool readData();
    /**
     * @brief passengers, QList<Passenger> qui contient toutes les données du jeu
     */
    QList<Passenger> passengers;
};

#endif // DATA_H
