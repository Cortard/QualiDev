#pragma once

#include "observer.h"
#include "promotion.h"

#include <QGroupBox>

class ViewHistogram   : public Observer
{
private:
    Promotion* promotion;
    QGroupBox *box;

public:
    ViewHistogram(Promotion *promotion, QGroupBox *box);
    void refresh() override;
};

