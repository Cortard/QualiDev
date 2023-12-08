#ifndef WEATHERREPORT_H
#define WEATHERREPORT_H

#include <QDebug>

#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QString>

#include "observer.h"

/**
 * @brief The WeatherReport class
 * @author FJa
 */
class WeatherReport : public Observable
{
private:
    QString main,description; //> text report
    double temp,temp_min,temp_max; //> temperatures
    double lon,lat; //> localisation
public:
    WeatherReport();

    // getters
    const QString& getDescription() const {return description;}
    double getTemp() const {return temp;}
    double getTempMin() const {return temp_min;}
    double getTempMax() const {return temp_max;}
    double getLon() const {return lon;}
    double getLat() const {return lat;}
    void setDescription(const QString &newDescription);
    void setTemp(double newTemp);
    void setTemp_min(double newTemp_min);
    void setTemp_max(double newTemp_max);
    void setLon(double newLon);
    void setLat(double newLat);
};

#endif // WEATHERREPORT_H
