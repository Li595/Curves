#define CURVES_H

#include <vector>

//ќбъ€вление класса 3D точек
class Point3D {
public:
    double x, y, z;
    Point3D();
    Point3D(double x_, double y_, double z_);
    //ћетод заполнени€ контейнера кривых
    virtual void Populate();
    //ћетода сортировки контейнера кривых
    virtual void Sorting();
};

//ќбъ€вление класса 3D кривых
class Curve3D {
public:
    //ћетод получни€ точки по t
    virtual Point3D getPoint(double t) = 0;
    //ћетод получни€ производной по t
    virtual Point3D getDerivative(double t) = 0;
};

//ќбъ€вление класса 3D окружностей
class Circle3D : public Curve3D {
public:
    Point3D center;
    double radius;
    Circle3D();
    Circle3D(Point3D center_, double radius_);
    virtual Point3D getPoint(double t);
    virtual Point3D getDerivative(double t);
    //ћетод заполнени€ контейнера окружностей
    virtual void populateCircles();
    //ћетод сортировки контейнера окружностей
    virtual void sortingCircles();
    //ћетод вычислени€ суммы радиусов
    virtual double computeTotalSumOfRadii();
};

//ќбъ€вление класса 3D эллипсов
class Ellipse3D : public Curve3D {
public:
    Point3D center;
    double a, b;
    Ellipse3D();
    Ellipse3D(Point3D center_, double a_, double b_);
    virtual Point3D getPoint(double t);
    virtual Point3D getDerivative(double t);
};

//ќбъ€вление класса 3D спиралей
class Helix3D : public Curve3D {
public:
    Point3D center;
    double a, b, pitch;
    Helix3D();
    Helix3D(Point3D center_, double a_, double b_, double pitch_);
    virtual Point3D getPoint(double t);
    virtual Point3D getDerivative(double t);
};








