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
     * @brief readData, lit les data qui sont dans un fichier dont le path est en paramtres
     * @arg path, QString, path des donnes a ouvrir
     * @return bool, ouverture et recuperation des données effectuees avec succes
     */
    bool readData(QString path);
    /**
     * @brief passengers, QList<Passenger> qui contient toutes les données du jeu
     */
    QList<Passenger> passengers;
private :
    /**
     * @brief verifExtension, verifi si le path en parametres est d'une des extensions en parametre
     * @param path fichier a verifier
     * @param extension liste des extension axeptées
     * @return si le fichier à une extension valide
     */
    bool verifExtension(QString path, QList<QString> extension);
};

#endif // DATA_H
