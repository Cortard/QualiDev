#include "viewList.h"

#include <QStringListModel>
#include "controllerdelete.h"

ViewList::ViewList()
{
}


ViewList::ViewList(Promotion *promotion, QListWidget *listView) : promotion(promotion),
    listView(listView)
{
    refresh();
}

void ViewList::deleteEtu()
{
    ControllerDelete* controller = new ControllerDelete(promotion);
    QStringList list;
    for(auto item : listView->selectedItems())
        list<<item->text();

    controller->deleteEtu(list);
    delete controller;
}

void ViewList::refresh()
{
    listView->clear();
    for(Student* student : promotion->students)
        listView->addItem(student->toQstring());
}
