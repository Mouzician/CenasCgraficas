#ifndef _POINT_H
#define _POINT_H

#include <vector>
#include <math.h>

using namespace std;

class Point {

public:
    Point(double x, double y, double z);
    Point(double s, double t);
double x;
double y;
double z;
    double length();
    Point & operator+(const Point &p);

};

Point calculateSurfaceNormal(vector<Point> polygon);

Point calculateSurfaceNormalTriangle(vector<Point> triangle);

#endif
