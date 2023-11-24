#include "shape.h"

int Shape::nextId = 0;

Shape::Shape(QString name, QPointF pos) : id(nextId++),
    name(name),
    pos(pos)
{}

Shape::~Shape()
{}
