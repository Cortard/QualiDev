#pragma once

#include "promotion.h"

#include <QListWidget>
#include "observer.h"

/**
 * @brief Class to manage the QListWidget
 * @author Adrien Peytavie
*/
class ViewList : public QObject, public Observer
{
    Q_OBJECT
private:
    Promotion* promotion;
    QListWidget* listView;

public:
    ViewList(Promotion *promotion, QListWidget *listView);
    void refresh() override;

public slots:
    void deleteEtu();
};

