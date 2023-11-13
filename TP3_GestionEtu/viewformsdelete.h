#ifndef VIEWFORMSDELETE_H
#define VIEWFORMSDELETE_H

#include "observer.h"
#include "promotion.h"

#include <QLineEdit>
#include <QObject>

/**
 * @brief The ViewForms class, classe de vue pour le formulaire de suppretion, obvservateur
 */
class ViewFormsDelete  : public QObject, public Observer
{
    Q_OBJECT
private :
    /**
     * @brief promotion pointeur vers les donnees
     */
    Promotion* promotion;
    /**
     * @brief numero pointeur vers l'entree du numero de l'etudiant a supprimer
     */
    QLineEdit* numero;

public:
    /**
     * @brief ViewFormsDelete constructeur
     * @param promotion pointeur vers les donnees
     * @param numero pointeur vers l'entree du numero de l'etudiant a supprimer
     */
    ViewFormsDelete(Promotion *promotion, QLineEdit *numero);
    /**
     * @brief refresh fonction appeler par l'observateur, refresh la vue
     */
    void refresh() override;

public slots:
    /**
     * @brief deleteEtu fonction trigger par le formulaire
     */
    void deleteEtu();
};

#endif // VIEWFORMSDELETE_H
