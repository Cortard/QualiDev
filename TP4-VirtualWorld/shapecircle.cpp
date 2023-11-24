#include "shape.h"
#include <QGraphicsEllipseItem>

Circle::Circle() : Shape("Circle", QPointF(-1, -1)),
    radius(0.)
{}

Circle::Circle(QString name, QPointF p, double r) : Shape(name, p),
    radius(r)
{}


QGraphicsItem* Circle::getGraphicsItem() const
{
	QGraphicsItem* item = new QGraphicsEllipseItem(pos.x()-radius, pos.y()-radius, radius*2., radius*2.);
	item->setData(0,id);
	return item;
}


QString Circle::type() const
{
	return "Circle";
}

Circle::~Circle()
{}
