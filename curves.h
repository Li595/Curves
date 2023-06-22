#define CURVES_H

#include <vector>

//���������� ������ 3D �����
class Point3D {
public:
    double x, y, z;
    Point3D();
    Point3D(double x_, double y_, double z_);
    //����� ���������� ���������� ������
    virtual void Populate();
    //������ ���������� ���������� ������
    virtual void Sorting();
};

//���������� ������ 3D ������
class Curve3D {
public:
    //����� �������� ����� �� t
    virtual Point3D getPoint(double t) = 0;
    //����� �������� ����������� �� t
    virtual Point3D getDerivative(double t) = 0;
};

//���������� ������ 3D �����������
class Circle3D : public Curve3D {
public:
    Point3D center;
    double radius;
    Circle3D();
    Circle3D(Point3D center_, double radius_);
    virtual Point3D getPoint(double t);
    virtual Point3D getDerivative(double t);
    //����� ���������� ���������� �����������
    virtual void populateCircles();
    //����� ���������� ���������� �����������
    virtual void sortingCircles();
    //����� ���������� ����� ��������
    virtual double computeTotalSumOfRadii();
};

//���������� ������ 3D ��������
class Ellipse3D : public Curve3D {
public:
    Point3D center;
    double a, b;
    Ellipse3D();
    Ellipse3D(Point3D center_, double a_, double b_);
    virtual Point3D getPoint(double t);
    virtual Point3D getDerivative(double t);
};

//���������� ������ 3D ��������
class Helix3D : public Curve3D {
public:
    Point3D center;
    double a, b, pitch;
    Helix3D();
    Helix3D(Point3D center_, double a_, double b_, double pitch_);
    virtual Point3D getPoint(double t);
    virtual Point3D getDerivative(double t);
};








