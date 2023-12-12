#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TP5_WeatherStation.h"
#include "weatherreport.h"
#include "dbmanager.h"
#include "viewreport.h"
#include "viewpollution.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QUrl>
#include <QUrlQuery>

QT_BEGIN_NAMESPACE
namespace Ui { class TP5_WeatherStationClass; }
QT_END_NAMESPACE

/**
 * @brief The TP5_WeatherStation class
 * @author Fja
 */
class TP5_WeatherStation : public QMainWindow
{
    Q_OBJECT

public:
    TP5_WeatherStation(DbManager *dbm, QWidget* parent = nullptr);
    ~TP5_WeatherStation();

private:
    Ui::TP5_WeatherStationClass* ui;

    WeatherReport* weatherReport;
    DbManager* dbmanager;
    QNetworkAccessManager* netmanager;

    ViewReport *reportView;
    ViewPollution *pollutionView;

    double lat,lon;
    QString city;

    /**
     * @brief request make a request to the URL. reply is read by void TP5_WeatherStation::replyFinished(QNetworkReply* reply);
     * @param URL the url to ask
     */
    void request(QString URL);
    /**
     * @brief weatherReplyFinished read the result of a weather api request
     * @param data data to read
     */
    void weatherReplyFinished(QJsonObject* data);
    /**
     * @brief airReplyFinished read the result of a air api request
     * @param data data to read
     */
    void airReplyFinished(QJsonObject* data);
    /**
     * @brief cityReplyFinished read the result of a city api request
     * @param data data to read
     */
    void cityReplyFinished(QJsonDocument* data);

public slots:
    /**
     * @brief weatherRequest make a weather request
     */
    void weatherRequest();
    /**
     * @brief airRequest make an air request
     */
    void airRequest();
    /**
     * @brief replyFinished verify the respond of a api request and call the good data reader
     * @param reply the api reply
     */
    void replyFinished(QNetworkReply* reply);

    /**
     * @brief changeCity open the change city dialogue and make the api request for the new city lat & long
     */
    void changeCity();
};
