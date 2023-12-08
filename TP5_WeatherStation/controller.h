#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <weatherreport.h>

class Controller
{
public:
    virtual ~Controller(){};
    virtual void control(const QJsonObject& list)=0;
};

class ControllerWeather : public Controller
{
private:
    WeatherReport* data;
public:
    ControllerWeather(WeatherReport* data):data(data){};
    void control(const QJsonObject& data){

    };
};

#endif // CONTROLLER_H
