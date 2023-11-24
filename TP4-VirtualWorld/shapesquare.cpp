#include "shape.h"
#include <QGraphicsRectItem>

Square::Square() : Shape("Square", QPointF(-1, -1)),
    size(0.)
{}

Square::Square(QString name, QPointF p, double s) : Shape(name, p),
    size(s)
{}


QGraphicsItem* Square::getGraphicsItem() const
{
    QGraphicsItem* item = new QGraphicsRectItem(pos.x()-size/2.,pos.y()-size/2.,size,size);
    item->setData(0,id);
    return item;
}


QString Square::type() const
{
    return "Square";
}

Square::~Square()
{}
