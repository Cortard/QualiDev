#pragma once

#include <QMainWindow>
#include "ui_TP3_GestionEtu.h"
#include "viewList.h"
#include "viewForms.h"
#include "viewformsdelete.h"
#include "viewPieChart.h"
#include "viewHistogram.h"

/**
 * @brief The TP3_GestionEtu class fenetre principale
 */
class TP3_GestionEtu : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief TP3_GestionEtu construit le fenetre
     * @param parent pointeur vers parent
     * @param promotion pointeur vers les donnes a exploiter
     */
    TP3_GestionEtu(QWidget *parent = nullptr, Promotion* promotion=nullptr);
    /**
     * @brief ~TP3_GestionEtu destructeur
     */
    ~TP3_GestionEtu() {delete promotion; }
private:
    /**
     * @brief ui, pointeur vers l'ui de la fenetre
     */
    Ui::TP3_GestionEtuClass ui;
    /**
     * @brief promotion pointeur vers les donnes a exploiter
     */
    Promotion* promotion;

    /**
     * @brief listView pointeur vers la view pour la liste des etudiants
     */
    ViewList* listView;
    /**
     * @brief listForm pointeur vers la view pour le formulaire d'ajout
     */
    ViewForms* listForm;
    /**
     * @brief listFormDelete pointeur vers la view pour le formulaire de suppression
     */
    ViewFormsDelete* listFormDelete;
    /**
     * @brief pieChartView pointeur vers la view pour le diagramme cammembert
     */
    ViewPieChart* pieChartView;
    /**
     * @brief histogramView pointeur vers la view pour le diagramme barres
     */
    ViewHistogram* histogramView;
};
