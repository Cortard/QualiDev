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

    virtual void refresh();
public:
    ViewList();
    ViewList(Promotion *promotion, QListWidget *listView);
public slots:
    void deleteEtu();
};

