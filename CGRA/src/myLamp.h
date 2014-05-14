#ifndef MY_LAMP
#define MY_LAMP

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include <math.h>
#include <vector>

#define PI 3.14159265359

using namespace std;

class MyLamp : public CGFobject {
    int slices;
    int stacks;
    vector<float> x1, x2, x3, x4;
    vector<float> y1, y2, y3, y4;
    vector<float> z1, z2, z3, z4;
    float deltaPhi;
    float deltaTheta;
    vector<float> xBase;
    vector<float> yBase;
public:
    MyLamp(int slices, int stacks);
    void draw();
    
};

#endif
