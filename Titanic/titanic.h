#ifndef TITANIC_H
#define TITANIC_H

#include <QMainWindow>
#include "abstractchartview.h"
#include "data.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Titanic; }
QT_END_NAMESPACE

/**
 * @brief The Titanic class, classe de la fentre qui affiche les graphique
 */
class Titanic : public QMainWindow
{
    Q_OBJECT

public:
    Titanic(Data* data, QWidget *parent = nullptr);
    ~Titanic();

private slots:
    /**
     * @brief actionRatio_H_F, fonction qui correspond au trigger du bouton Ratio_H_F
     */
    void actionRatio_H_F();
    /**
     * @brief actionCategorie, fonction qui correspond au trigger du bouton Categorie
     */
    void actionCategorie();
    /**
     * @brief actionAgeCategorie, fonction qui correspond au trigger du bouton AgeCategorie
     */
    void actionAgeCategorie();

private:
    /**
     * @brief ui, interface user de la fentre titanic
     */
    Ui::Titanic *ui;
    /**
     * @brief data, pointer vers les données à afficher
     */
    Data* data;
    /**
     * @brief chartView, smart pointer qui contient le `chartView` (vue du grphique) du graphique actuellement affiché
     */
    std::unique_ptr<AbstractChartView> chartView;
};
#endif // TITANIC_H
