#pragma once

#include "observer.h"
#include "promotion.h"

#include <QGroupBox>

/**
 * @brief Class to manage the PieChart View
 * @author Adrien Peytavie
*/
class ViewPieChart   : public Observer
{
private:
    Promotion* promotion;
    QGroupBox *box;

public:
    ViewPieChart(Promotion *promotion, QGroupBox *box);
    void refresh() override;
};

