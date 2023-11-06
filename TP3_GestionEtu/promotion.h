#include <QList>
#include "student.h"
#include "observable.h"

#pragma once


class Promotion : public Observable
{
public:
    QList<Student*> students;

	Promotion();
    ~Promotion();
    bool loadFileCSV();
};

