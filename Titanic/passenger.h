#ifndef PASSENGER_H
#define PASSENGER_H

#include <QString>

/**
 * @brief The Passenger class, classe qui contient les donnes d'un passagé
 */
class Passenger
{
public:
    /**
     * @brief Passenger, constructeur par défaut (vide)
     */
    Passenger();
    /**
     * @brief Passenger, constructeur utilisé pour initialiser les donnees
     * @param iden, QString numero de passagé de la forme, Px avec x le num de passagé
     * @param classe, int classe du passagé 0 = crew,   1 = first, 2 = second, 3 = third
     * @param age, int age du passagé 0 = child,  1 = adult
     * @param sexe, int sexe du passagé 0 = female, 1 = male
     * @param survived, int les passagé a t'il survecu 0 = no,     1 = yes
     */
    Passenger(const QString &iden, int classe, int age, int sexe, int survived);
    /**
     * @brief getSexe renvoi le sexe du passagé 0 = female, 1 = mal
     * @return le sexe du passagé 0 = female, 1 = mal
     */
    int getSexe() const;
    /**
     * @brief getClasse renvoi la classe du passagé 0 = crew,   1 = first, 2 = second, 3 = third
     * @return la classe du passagé 0 = crew,   1 = first, 2 = second, 3 = third
     */
    int getClasse() const;
    /**
     * @brief getSurvived renvoi si le passagé a survecu 0 = no,     1 = yes
     * @return si le passagé a survecu 0 = no,     1 = yes
     */
    int getSurvived() const;
    /**
     * @brief getAge renvoi l' age du passagé 0 = child,  1 = adult
     * @return l' age du passagé 0 = child,  1 = adult
     */
    int getAge() const;

private:
    /**
     * @brief iden QString numero de passagé de la forme, Px avec x le num de passagé
     */
    QString iden;
    /**
     * @brief classe int classe du passagé 0 = crew,   1 = first, 2 = second, 3 = third
     */
    int classe;
    /**
     * @brief age int age du passagé 0 = child,  1 = adult
     */
    int age;
    /**
     * @brief sexe int sexe du passagé 0 = female, 1 = male
     */
    int sexe;
    /**
     * @brief survived int les passagé a t'il survecu 0 = no,     1 = yes
     */
    int survived;
};

#endif // PASSENGER_H
