#include "viewformsdelete.h"

#include "controllercreator.h"

ViewFormsDelete::ViewFormsDelete(Promotion *promotion, QLineEdit *numero) : promotion(promotion),
    numero(numero)
{
}

void ViewFormsDelete::deleteEtu()
{
    QStringList input={};
    input<<numero->text();
    Controller* controller = ControllerCreator::Controller(promotion, &input);
    controller->action();
    delete controller;
}

void ViewFormsDelete::refresh()
{
    numero->clear();
}
