#include "controller.h"
#include "shapemanager.h"

#include <cstdlib>
#include <iostream>
#include <ctime>
#include "shapefactory.h"

ControllerAdd::ControllerAdd(ShapeManager* sm, QRadioButton* circle, QRadioButton* rectangle, QRadioButton* square) : shapeManager(sm),
    circle(circle),
    square(square),
    rectangle(rectangle)
{}

void ControllerAdd::control()
{
	if (shapeManager == nullptr) return;

    shapeManager->add(ShapeFactory::CreateForm(circle,rectangle,square));
}

ControllerMoveShape::ControllerMoveShape(ShapeManager* sm) : shapeManager(sm)
{}

void ControllerMoveShape::control(const QVector<QGraphicsItem*>& items)
{
	if (shapeManager == nullptr) return;

	// Move Shape
	for (QGraphicsItem* item : items)
	{
		QVariant variant = item->data(0);
		int id = variant.toInt();

		bool selected = shapeManager->selectShape(id);
		if (selected)
		{
			QRectF rect = item->boundingRect();
			shapeManager->moveShape(item->scenePos() + rect.center());
		}
	}

	shapeManager->notifyObserver();
}
