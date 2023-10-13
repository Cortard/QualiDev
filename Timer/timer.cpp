#include "timer.h"
#include "ui_timer.h"

Timer::Timer(QWidget *parent) : QWidget(parent), ui(new Ui::Timer) {
    ui->setupUi(this);
    this->timer = new QTimer();
    ui->spinBox->setMaximum(999999);
    timer->setInterval(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(mafonction()));// connexion du slot
    timer->start();

    connect(ui->radioButtonLent, SIGNAL(clicked()), this, SLOT(on_changeVitesse()));
    connect(ui->radioButtonMoyen, SIGNAL(clicked()), this, SLOT(on_changeVitesse()));
    connect(ui->radioButtonRapide, SIGNAL(clicked()), this, SLOT(on_changeVitesse()));

}

Timer::~Timer() {
    delete timer;
    delete ui;
}

void Timer::mafonction()
{
    int valeur = ui->spinBox->value(); // on récupère la valeur courante de la spinbox
    ++valeur; // on l'incrémente
    ui->spinBox->setValue(valeur); // on la remet dans la spinBox
    ui->progressBar->setValue(valeur%100); // on ajuste la progressbar en conséquence
}

void Timer::on_changeVitesse(){
    if (ui->radioButtonLent->isChecked()) timer->setInterval(2000);
    else if (ui->radioButtonMoyen->isChecked()) timer->setInterval(1000);
    else if (ui->radioButtonRapide->isChecked()) timer->setInterval(100);
}
