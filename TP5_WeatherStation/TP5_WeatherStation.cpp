#include <QtNetwork/QNetworkAccessManager>
#include <QByteArray>

#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QMessageBox>

#include "TP5_WeatherStation.h"
#include "ui_TP5_WeatherStation.h"

#include "weatherreport.h"

TP5_WeatherStation::TP5_WeatherStation(DbManager *dbm, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::TP5_WeatherStationClass)
    , weatherReport (new WeatherReport) // Weather Data class
    , dbmanager (dbm)                   // DB Manager, for Pollution Data
    , netmanager (nullptr)              // NetWork Manager, for http requests
{
    ui->setupUi(this);

    // Weather report View
    reportView = new ViewReport(weatherReport,ui);
    weatherReport->addObserver(reportView);
    // Pollution Forecast View
    pollutionView = new ViewPollution(dbmanager, ui->groupBox_pollution);
    dbmanager->addObserver(pollutionView);

    // netmanager here (or better in initialisation list)  + callback to replyFinished
    netmanager= new QNetworkAccessManager(this);
    connect(netmanager, &QNetworkAccessManager::finished, this, &TP5_WeatherStation::replyFinished);


    weatherRequest();
    airRequest();
    // uncomment once observable implemented
    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::weatherRequest);
    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::airRequest);

}

TP5_WeatherStation::~TP5_WeatherStation()
{
    delete ui;
    delete dbmanager;
    if (netmanager != nullptr)
        netmanager->deleteLater();
}


void TP5_WeatherStation::request(QString URL){
    QUrl url(URL);
    QNetworkRequest request;
    request.setUrl(url);
    //--header ’Accept: application/json’
    request.setRawHeader("Accept", "application/json");
    qDebug() << Q_FUNC_INFO << request.url();
    netmanager->get(request);
}

void TP5_WeatherStation::weatherRequest()
{
    // Pour tester les entêtes HTTP
    QString URL = "https://api.openweathermap.org/data/2.5/weather?q=bourg-en-bresse,fr&units=metric&lang=fr&appid=25a11b3df66f2b388079b21253919952";
    request(URL);
}

void TP5_WeatherStation::airRequest(){
    // Pour tester les entêtes HTTP
    QString URL = "https://api.openweathermap.org/data/2.5/air_pollution/forecast?lat=46.0398&lon=5.4133&units=metric&lang=fr&appid=25a11b3df66f2b388079b21253919952";
    request(URL);
}

void TP5_WeatherStation::replyFinished(QNetworkReply* reply){
    if (reply->error() != QNetworkReply::NoError)
    {
        QMessageBox messageBox;
        messageBox.critical(0,"Error",reply->errorString());
        messageBox.setFixedSize(500,200);
        qDebug() << reply->error() << "=>" << reply->errorString();
    }
    else if ( reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200)
    {
        QByteArray datas = reply->readAll();
        QJsonDocument jsonResponse = QJsonDocument::fromJson(datas);
        QJsonObject jsonObj = jsonResponse.object();

        if(jsonObj.contains("id"))
            weatherReplyFinished(&jsonObj);
        else
            airReplyFinished(&jsonObj);
    } else {
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Failed to connect to API !");
        messageBox.setFixedSize(500,200);
    }

    reply->deleteLater();
}

void TP5_WeatherStation::weatherReplyFinished(QJsonObject* data)
{
    QJsonObject coordArray = (*data)["coord"].toObject();
    weatherReport->setLat(coordArray["lat"].toDouble());
    weatherReport->setLon(coordArray["lon"].toDouble());

    QJsonObject mainArray = (*data)["main"].toObject();
    weatherReport->setTemp(mainArray["temp"].toDouble());
    weatherReport->setTemp_min(mainArray["temp_min"].toDouble());
    weatherReport->setTemp_max(mainArray["temp_max"].toDouble());

    weatherReport->setDescription((*data)["name"].toString());
    weatherReport->notifyObserver();
}

void TP5_WeatherStation::airReplyFinished(QJsonObject* data)
{
    if(!dbmanager->isOpen()) return;
    QJsonArray listArray = (*data)["list"].toArray();
    for(int i=0; i<listArray.size(); ++i){
        QJsonObject day=listArray[i].toObject();
        if(!dbmanager->entryExists(day["dt"].toInt()))
            dbmanager->addData(day["dt"].toInt(),(day["main"].toObject())["aqi"].toInt());
    }
}
