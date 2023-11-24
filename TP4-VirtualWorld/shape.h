#pragma once
#include <QGraphicsItem>
#include <QPointF>

class Shape
{
private:
    static int nextId;
public:
    int id;
    QString name;
    QPointF pos;
    Shape(QString name, QPointF pos);
    virtual QGraphicsItem* getGraphicsItem() const =0;
    virtual QString type() const =0;
    virtual ~Shape();
};

class Group : public Shape
{
private:
    QVector<Shape*> shapes;
public:
    Group();
    Group(QString, QPointF);
    void addShape(Shape*);
    void deleteShape(Shape*);
    ~Group();

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;
};

class Circle : public Shape
{
private:
	double radius;
public:
    Circle();
    Circle(QString, QPointF, double);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;

    ~Circle();
};

class Rectangle : public Shape
{
private:
    double width, height;
public:
    Rectangle();
    Rectangle(QString, QPointF, double, double);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;

    ~Rectangle();
};

class Square : public Shape
{
private:
    double size;
public:
    Square();
    Square(QString, QPointF, double);

    QGraphicsItem* getGraphicsItem() const;
    QString type() const;

    ~Square();
};
