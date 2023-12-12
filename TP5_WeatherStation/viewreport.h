#ifndef VIEWREPORT_H
#define VIEWREPORT_H

#include <QGroupBox>

#include "weatherreport.h"
#include "observer.h"
#include "ui_TP5_WeatherStation.h"

/**
 * @brief The ViewReport class gere la vue du bulletin meteo
 */
class ViewReport : public QObject, public Observer
{
    Q_OBJECT
private:
    WeatherReport *model;   //> model containing temp, localisation
    Ui::TP5_WeatherStationClass* ui;
    QString* city;
public:
    ViewReport(WeatherReport *wreport, Ui::TP5_WeatherStationClass* ui, QString* city);

    /**
     * @brief init la vue
     */
    void init();
    /**
     * @brief update update la vue du bulletin meteo
     */
    void update() override;

};

#endif // VIEWREPORT_H
