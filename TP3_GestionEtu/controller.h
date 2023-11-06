#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "promotion.h"

class Controller
{
protected:
    Promotion* data;
public:
    Controller();
    Controller(Promotion *data);

    bool exist(int etudiant);
    bool exist(QString etudiant);
};

#endif // CONTROLLER_H
