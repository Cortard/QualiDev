#include "observer.h"
#include "promotion.h"

#include <QLineEdit>
#include <QObject>
#include <QComboBox>

#pragma once

/**
 * @brief The ViewForms class, classe de vue pour le formulaire d'ajout, obvservateur
 */
class ViewForms  : public QObject, public Observer
{
    Q_OBJECT
private:
    /**
     * @brief promotion pointeur vers les donnees
     */
    Promotion* promotion;
    /**
     * @brief numero pointeur vers l'entree du numero
     */
    QLineEdit* numero;
    /**
     * @brief prenom pointeur vers l'entree du prenom
     */
    QLineEdit* prenom;
    /**
     * @brief nom  pointeur vers l'entree du nom
     */
    QLineEdit* nom;
    /**
     * @brief departement pointeur vers l'entree du departement
     */
    QComboBox* departement;
    /**
     * @brief bac pointeur vers l'entree du bac
     */
    QComboBox* bac;


public:
    /**
     * @brief ViewForms constructeur
     * @param prenom pointeur vers l'entree du prenom
     * @param nom  pointeur vers l'entree du nom
     * @param departement pointeur vers l'entree du departement
     * @param bac pointeur vers l'entree du bac
     */
    ViewForms(Promotion *promotion, QLineEdit *numero, QLineEdit *prenom, QLineEdit *nom, QComboBox *departement, QComboBox *bac);
    /**
     * @brief refresh fonction appeler par l'observateur, refresh la vue
     */
    void refresh() override;

 public slots:
    /**
     * @brief addEtu fonction trigger par le formulaire
     */
    void addEtu();
};

