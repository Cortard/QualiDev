#ifndef HORIZONTALCHARTWIEW_H
#define HORIZONTALCHARTWIEW_H

#include "AbstractChartView.h"

#include <QChartView>


/**
 * @brief The HorizontalChartWiew class, class de la vue des quatres graphiques de bars horizontales
 */
class HorizontalChartWiew : public AbstractChartView
{
public:
    /**
     * @brief HorizontalChartWiew, constructeur (vide)
     */
    HorizontalChartWiew();
    /**
     * @brief getChartViewFonction qui renvoi le `QWidget*` qui correspond à la vue des quatres graphiques de bars horizontales.
     * @param data La source des données
     * @return `QWidget*` qui correspond à la vue des quatres graphiques de bars horizontales
     */
    QWidget *getChartView(Data *data);
private:
    /**
     * @brief top Methode qui crée les deux graphique du haut
     * @param data La source des données
     * @param res Tableau ou seront ecrit les deux graphiques sous cette ordre : [heut-gauche, haut-droit]
     */
    void top(Data *data, QChartView* res[2]);
    /**
     * @brief bottom Methode qui crée les deux graphique du bas
     * @param data La source des données
     * @param res Tableau ou seront ecrit les deux graphiques sous cette ordre : [bas-gauche, bas-droit]
     */
    void bottom(Data *data, QChartView* res[2]);
};

#endif // HORIZONTALCHARTWIEW_H
