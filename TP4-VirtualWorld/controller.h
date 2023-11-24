#pragma once
#include "shapemanager.h"
#include <QRadioButton>
#include <QPointF>

class ControllerAdd
{
	ShapeManager* shapeManager;
    QRadioButton* circle;
    QRadioButton* square;
    QRadioButton* rectangle;
public:
    ControllerAdd(ShapeManager* = nullptr, QRadioButton* = nullptr, QRadioButton* = nullptr, QRadioButton* = nullptr);
	void control();
};

class ControllerMoveShape
{
	ShapeManager* shapeManager;
public:
	ControllerMoveShape(ShapeManager* = nullptr);
    void control(const QVector<QGraphicsItem *> &);
};
