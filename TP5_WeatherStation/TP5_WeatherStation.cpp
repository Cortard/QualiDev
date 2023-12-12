#include <QtNetwork/QNetworkAccessManager>
#include <QByteArray>

#include <QJsonValue>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QJsonArray>
#include <QMessageBox>
#include <QDateTime>
#include <QInputDialog>

#include "TP5_WeatherStation.h"
#include "ui_TP5_WeatherStation.h"

#include "weatherreport.h"

TP5_WeatherStation::TP5_WeatherStation(DbManager *dbm, QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::TP5_WeatherStationClass)
    , weatherReport (new WeatherReport) // Weather Data class
    , dbmanager (dbm)                   // DB Manager, for Pollution Data
    , netmanager (nullptr)              // NetWork Manager, for http requests
    , lat(46.0398)
    , lon(5.4133)
    , city("Bourg-en-Bresse")
{
    ui->setupUi(this);

    // Weather report View
    reportView = new ViewReport(weatherReport,ui,&city);
    weatherReport->addObserver(reportView);
    // Pollution Forecast View
    pollutionView = new ViewPollution(dbmanager, ui->groupBox_pollution,&city);
    dbmanager->addObserver(pollutionView);

    // netmanager here (or better in initialisation list)  + callback to replyFinished
    netmanager= new QNetworkAccessManager(this);
    connect(netmanager, &QNetworkAccessManager::finished, this, &TP5_WeatherStation::replyFinished);


    weatherRequest();
    airRequest();
    // uncomment once observable implemented
    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::weatherRequest);
    connect(ui->pushButton_weather_request, &QPushButton::pressed, this, &TP5_WeatherStation::airRequest);

    connect(ui->pushButton_city, &QPushButton::pressed, this, &TP5_WeatherStation::changeCity);
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
    QString URL = "https://api.openweathermap.org/data/2.5/weather?q="+city+",fr&units=metric&lang=fr&appid=25a11b3df66f2b388079b21253919952";
    request(URL);
}

void TP5_WeatherStation::airRequest(){
    // Pour tester les entêtes HTTP
    QString URL= "http://api.openweathermap.org/data/2.5/air_pollution/history?lat="+QString::number(lat)+"&lon="+QString::number(lon)+"&start="+QString::number(QDateTime::currentDateTimeUtc().addDays(-1).toSecsSinceEpoch())+"&end="+QString::number(QDateTime::currentDateTimeUtc().toSecsSinceEpoch())+"&units=metric&lang=fr&appid=25a11b3df66f2b388079b21253919952";
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
        else if (jsonObj.contains("list"))
            airReplyFinished(&jsonObj);
        else
            cityReplyFinished(&jsonResponse);

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

    weatherReport->setDescription((*data)["weather"].toArray().at(0)["description"].toString());
    weatherReport->notifyObserver();
}

void TP5_WeatherStation::airReplyFinished(QJsonObject* data)
{
    if(!dbmanager->isOpen()) return;
    dbmanager->createTable(city);
    QJsonArray listArray = (*data)["list"].toArray();
    for(int i=0; i<listArray.size(); ++i){
        QJsonObject day=listArray[i].toObject();
        if(!dbmanager->entryExists(day["dt"].toInt(),city))
            dbmanager->addData(day["dt"].toInt(),(day["main"].toObject())["aqi"].toInt(),city);
    }
    dbmanager->notifyObserver();
}

void TP5_WeatherStation::cityReplyFinished(QJsonDocument* data){
    QJsonArray jsonArray = data->array();

    QJsonObject jsonObj = jsonArray[0].toObject();
    this->lat = jsonObj["lat"].toDouble();
    this->lon = jsonObj["lon"].toDouble();
    this->city = jsonObj["name"].toString();

    weatherRequest();
    airRequest();
}

void TP5_WeatherStation::changeCity(){
    bool ok;
    QString ville = QInputDialog::getText(this, "Changer la ville", "Nouvelle ville :", QLineEdit::Normal, "", &ok);

    if(ok && !ville.isEmpty()) {
        QString URL ="http://api.openweathermap.org/geo/1.0/direct?q=" + ville +"&limit=5&appid=25a11b3df66f2b388079b21253919952";
        request(URL);
    }
}
