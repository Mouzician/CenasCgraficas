#include "MyPoint.h"


Point :: Point(){
this->x =   this->y =  this->z = 0;
}
Point::Point(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(double s, double t){
    this->x = s;
    this->y = t;
    this->z = 0;
}

inline double Point::length(){
    return sqrt( (this->x * this->x) + (this->y * this->y) + (this->z * this->z) );
}


Point & Point::operator+(const Point &p){
    this->x = (this->x + p.x) / 2;
    this->y = (this->y + p.y) / 2;
    this->z = (this->z + p.z) / 2;
    return *this;
}

Point & Point::operator-(const Point &p){
    this->x = (this->x - p.x);
    this->y = (this->y - p.y);
    this->z = (this->z - p.z);
    return *this;
}


Point calculateSurfaceNormal(vector<Point> polygon){
    Point normal(0,0,0);
    for (unsigned int i = 0; i < polygon.size(); ++i) {
        Point current = polygon.at(i);
        Point next = polygon.at( (i+1) % polygon.size() );
        
        normal.x = normal.x + ( (current.y - next.y) * (current.z + next.z) );
        normal.y = normal.y + ( (current.z - next.z) * (current.x + next.x) );
        normal.z = normal.z + ( (current.x - next.x) * (current.y + next.y) );
    }
    
    double length = normal.length();
    normal.x = normal.x / length;
    normal.y = normal.y / length;
    normal.z = normal.z / length;
    return normal;
}