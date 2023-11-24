#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "shape.h"

#include <QRadioButton>

class ShapeFactory
{
public :
    static Shape* CreateForm(QRadioButton* circle, QRadioButton* rectangle, QRadioButton* square){
        if (circle->isChecked())
            return new Circle("Circle", QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 100);
        else if(rectangle->isChecked())
            return new Rectangle("Rectangle", QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 200, std::rand() % 200);
        else if (square->isChecked())
            return new Square("Square", QPointF(std::rand() % 400 - 200, std::rand() % 400 - 200), std::rand() % 200);
        return nullptr;
    }
};

#endif // SHAPEFACTORY_H
