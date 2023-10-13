#include <QDir>
#include <iostream>
#include "QImage"

int main()
{
    QString imagePath = "C:/Users/Petit Corto/Documents/2y/qualiDev/Image/picture/5217_star_wars.jpg";
    QImage darkVador;
    if (darkVador.load(imagePath))
        std::cout<<"load";
    else
        std::cout<<"error in load at "<< imagePath.toStdString();
    std::cout<<std::endl;

    QImage changeDarkVador(darkVador);
    QImage greyDarkVador(darkVador);

    QRgb rgb;
    int center=darkVador.width()/2;
    for (int i=0; i<darkVador.width();i++)
        for (int j=0; j<darkVador.height();j++){
            rgb=darkVador.pixel(i,j);
            changeDarkVador.setPixel(i,j,qRgba(qGreen(rgb),  qRed(rgb), qBlue(rgb), qAlpha(rgb)));
            if (i<center) {
                greyDarkVador.setPixel(i,j,qRgba(qGray(rgb),qGray(rgb),qGray(rgb),qAlpha(rgb)));
            }
        }

    QString changedImagePath = "C:/Users/Petit Corto/Documents/2y/qualiDev/Image/picture/5217_star_wars.png";
    if (changeDarkVador.save(changedImagePath))
        std::cout<<"save";
    else
        std::cout<<"error in save";
    std::cout<<std::endl;

    greyDarkVador.save(QString("C:/Users/Petit Corto/Documents/2y/qualiDev/Image/picture/half_grey_5217_star_wars.png"));


    return 0;
}
