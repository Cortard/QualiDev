#include "shape.h"
#include <QGraphicsRectItem>

Rectangle::Rectangle() : Shape("Rectangle", QPointF(-1, -1)),
    width(0.),
    height(0.)
{}

Rectangle::Rectangle(QString name, QPointF p, double w, double h) : Shape(name,p),
    width(w),
    height(h)
{}


QGraphicsItem* Rectangle::getGraphicsItem() const
{
    QGraphicsItem* item = new QGraphicsRectItem(pos.x()-width/2.,pos.y()-height/2.,width,height);
    item->setData(0,id);
    return item;
}


QString Rectangle::type() const
{
    return "Rectangle";
}

Rectangle::~Rectangle()
{}
