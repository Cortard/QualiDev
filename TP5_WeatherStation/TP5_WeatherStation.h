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
    void weatherReplyFinished(QJsonObject* data);
    void airReplyFinished(QJsonObject* data);
    void cityReplyFinished(QJsonDocument* data);

public slots:
    void weatherRequest();
    void airRequest();
    void replyFinished(QNetworkReply* reply);

    void changeCity();
};
