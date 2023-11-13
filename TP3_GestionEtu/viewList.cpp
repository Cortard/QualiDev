#include "viewList.h"

#include <QStringListModel>
#include "controllercreator.h"

ViewList::ViewList(Promotion *promotion, QListWidget *listView) : promotion(promotion),
    listView(listView)
{
}

void ViewList::deleteEtu()
{

    QStringList list;
    for(auto item : listView->selectedItems())
        list<<item->text();
    Controller* controller = ControllerCreator::Controller(promotion, &list);

    controller->action();
    delete controller;
}

void ViewList::refresh()
{
    listView->clear();
    for(Student* student : promotion->students)
        listView->addItem(student->toQstring());
}
