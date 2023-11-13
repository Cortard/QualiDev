#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "promotion.h"

class Controller
{
protected:
    Promotion* data;
    QStringList* input;
public:
    Controller(Promotion *data, QStringList* input);
    virtual int action()=0;
    virtual ~Controller(){};
};

#endif // CONTROLLER_H
