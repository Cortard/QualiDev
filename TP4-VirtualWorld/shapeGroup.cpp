#include "shape.h"
#include <QGraphicsItemGroup>

Group::Group() : Shape("",QPointF(0,0))
{}

Group::Group(QString name, QPointF pos) : Shape(name, pos)
{}

void Group::addShape(Shape* shape)
{
    shapes.append(shape);
}

void Group::deleteShape(Shape* shape)
{
    shapes.removeOne(shape);
    delete shape;
}


QGraphicsItem* Group::getGraphicsItem() const{
    QGraphicsItemGroup* item = new QGraphicsItemGroup();
    for(Shape* shape : shapes)
        item->addToGroup(shape->getGraphicsItem());
    item->setData(0,id);

    return item;
}

QString Group::type() const{
    return "Group";
}

Group::~Group(){
    for(Shape* shape : shapes)
        delete shape;
    shapes.clear();
}

