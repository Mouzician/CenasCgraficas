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