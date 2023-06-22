#define _USE_MATH_DEFINES
#include "curves.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>
#include <algorithm>
#include <time.h>

using namespace std;
//Объявление контейнеров
vector<Curve3D*> curves;
vector<Circle3D*> circles;

//Внедрение класса Point3D 
Point3D::Point3D() : x(0.0), y(0.0), z(0.0) {}
Point3D::Point3D(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

//Внедрение класса Circle3D 
Circle3D::Circle3D() : center(Point3D()), radius(0.0) {}
Circle3D::Circle3D(Point3D center_, double radius_) : center(center_), radius(radius_) {}

Point3D Circle3D::getPoint(double t) {
    double x = center.x + radius * cos(t);
    double y = center.y + radius * sin(t);
    double z = center.z;
    return Point3D(x, y, z);
}

Point3D Circle3D::getDerivative(double t) {
    double x = -radius * sin(t);
    double y = radius * cos(t);
    double z = 0.0;
    return Point3D(x, y, z);
}

//Внедрение класса Ellipse3D
Ellipse3D::Ellipse3D() : center(Point3D()), a(0.0), b(0.0) {}

Ellipse3D::Ellipse3D(Point3D center_, double a_, double b_) : center(center_), a(a_), b(b_) {}

Point3D Ellipse3D::getPoint(double t) {
    double x = center.x + a * cos(t);
    double y = center.y + b * sin(t);
    double z = center.z;
    return Point3D(x, y, z);
}

Point3D Ellipse3D::getDerivative(double t) {
    double x = -a * sin(t);
    double y = b * cos(t);
    double z = 0.0;
    return Point3D(x, y, z);
}

//Внедрение класса Helix3D 
Helix3D::Helix3D() : center(Point3D()), a(0.0), b(0.0), pitch(0.0) {}
Helix3D::Helix3D(Point3D center_, double a_, double b_, double pitch_) : center(center_), a(a_), b(b_), pitch(pitch_) {}

Point3D Helix3D::getPoint(double t) {
    double x = center.x + a * cos(t);
    double y = center.y + b * sin(t);
    double z = center.z + pitch * t;
    return Point3D(x, y, z);
}
Point3D Helix3D::getDerivative(double t) {
    double x = -a * sin(t);
    double y = b * cos(t);
    double z = pitch;
    return Point3D(x, y, z);
}

//Заполнение контейнеров кривыми со случайными значениями
void Point3D::Populate() {
    srand(time(NULL));
    int rand = std::rand()%10 + 1;
    for (int i = 0; i < rand; i++) {
        double randX = std::rand() % 5 + 1;
        double randY = std::rand() % 5 + 1;
        double randZ = std::rand() % 5 + 1;
        double rand1 = std::rand() % 5 + 1;
        double rand2 = std::rand() % 5 + 1;
        double rand3 = std::rand() % 5 + 1;
        curves.push_back(new Circle3D(Point3D(randX, randY, randZ), rand1));
        curves.push_back(new Ellipse3D(Point3D(randX, randY, randZ), rand1, rand2));
        curves.push_back(new Helix3D(Point3D(randX, randY, randZ), rand1, rand2, rand3));
    }
    return;
}


//Сортировка кривых по t=PI/4 и вывод значений точек и производных
void Point3D:: Sorting() {
    double t = M_PI / 4;
    for (Curve3D* curve : curves) {
        Point3D point = curve->getPoint(t);
        Point3D derivative = curve->getDerivative(t);
        cout << "Point: (" << point.x << ", " << point.y << ", " << point.z << ")" << endl;
        cout << "Derivative: (" << derivative.x << ", " << derivative.y << ", " << derivative.z << ")" << endl;
    }
    return;
}

//Заполнение контейнера только с окружностями
void Circle3D::populateCircles(){
    for (Curve3D* curve : curves) {
        if (dynamic_cast<Circle3D*>(curve)) {
            circles.push_back(static_cast<Circle3D*>(curve));
        }
    }
}

//Сортировка контейнера с окружностями
void Circle3D::sortingCircles() {
    sort(circles.begin(), circles.end(), [](const Circle3D* c1, const Circle3D* c2) {return c1->radius < c2->radius;});
    return;
}

//Вычисление суммы радиусов
double Circle3D:: computeTotalSumOfRadii() {
    double sum_radii = 0.0;
    for (Circle3D* circle : circles) {
        sum_radii += circle->radius;
    }
    cout << "Sum of all circle radii: " << sum_radii << endl;
    return sum_radii;
}


int main() {
    Point3D* curve = new Point3D();
    curve->Populate();
    curve->Sorting();

    Circle3D* circle = new Circle3D();
    circle->populateCircles();
    circle->sortingCircles();
    circle->computeTotalSumOfRadii();

    delete circle;
    delete curve;
    system("pause");
    return 0;
}