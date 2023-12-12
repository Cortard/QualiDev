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
 * @brief The WeatherReport class stock les donnes du bulletin meteo
 */
class WeatherReport : public Observable
{
private:
    QString main,description; //> text report
    double temp,temp_min,temp_max; //> temperatures
    double lon,lat; //> localisation
public:
    /**
     * @brief Constructor
     *
     * Constructor sets up all the data to 0.0
     */
    WeatherReport();

    // getters
    /**
     * @brief Return the description of the current weather
     */
    const QString& getDescription() const {return description;}
    /**
     * @brief Return the temperature of the current weather
     */
    double getTemp() const {return temp;}
    /**
     * @brief Return the minimal temperature of the current weather
     */
    double getTempMin() const {return temp_min;}

    /**
     * @brief Return the maximal emperature of the current weather
     */
    double getTempMax() const {return temp_max;}

    /**
     * @brief Return the longitude of the current weather
     */
    double getLon() const {return lon;}

    /**
     * @brief Return the latitude of the current weather
     */
    double getLat() const {return lat;}
    /**
     * @brief Set the description for the current weather
     * @param newDescription - description to set
     */
    void setDescription(const QString &newDescription);

    /**
     * @brief Set the temperature for the current weather
     * @param t - temperature to set
     */
    void setTemp(double newTemp);

    /**
     * @brief Set the minimal temperature for the current weather
     * @param t - minimal temperature to set
     */
    void setTemp_min(double newTemp_min);

    /**
     * @brief Set the maximal temperature for the current weather
     * @param t - maximal temperature to set
     */
    void setTemp_max(double newTemp_max);

    /**
     * @brief Set the longitude for the current weather
     * @param l - longitude to set
     */
    void setLon(double newLon);

    /**
     * @brief Set the latitude for the current weather
     * @param l - latitude to set
     */
    void setLat(double newLat);
};

#endif // WEATHERREPORT_H
