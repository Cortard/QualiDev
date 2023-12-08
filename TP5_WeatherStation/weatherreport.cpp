#include "weatherreport.h"
#include <QDateTime>
#include <QTimeZone>

WeatherReport::WeatherReport()
    : temp(0.0),temp_min(0.0),temp_max(0.0),
    lon(0.0),lat(0.0)
{ }

void WeatherReport::setDescription(const QString &newDescription)
{
    description = newDescription;
}

void WeatherReport::setTemp(double newTemp)
{
    temp = newTemp;
}

void WeatherReport::setTemp_min(double newTemp_min)
{
    temp_min = newTemp_min;
}

void WeatherReport::setTemp_max(double newTemp_max)
{
    temp_max = newTemp_max;
}

void WeatherReport::setLon(double newLon)
{
    lon = newLon;
}

void WeatherReport::setLat(double newLat)
{
    lat = newLat;
}
