#ifndef MY_ROBOT
#define MY_ROBOT

#ifdef __APPLE__
#include "CGFobject.h"
#else
#include "CGF/CGFobject.h"
#endif

#include "CGFappearance.h"
#include "myTable.h"
#include <math.h>

#define PI 3.14159265359

#include "myLamp.h"
#include "myCylinder.h"
#include "MyPoint.h"
#include <deque>

#define UPDATE_TEXTURE 10
#define ANIMATION_OFF 0
#define ANIMATION_DOWN 1
#define ANIMATION_RIGHT 2

class MyRobot{
    double angle;
    double startingAngle;
    double x;
    double y;
    double z;
    double speed;
    double rotationSpeed;
    double deg2rad;
    
    int stacks;
    int deltaSide;
    int slices;
    vector<Point> side;
    vector<Point> normals;
    deque<deque<Point> > texels;
    
    CGFappearance * texture1;
    CGFappearance * texture2;
    CGFappearance * texture3;
    CGFappearance * texture4;
    CGFappearance * texture5;
    
    long time;
    int textureAnimationCounter;
    int textureAnimation;
public:
    int isWireframe;
    int texture;

    MyRobot(int stacks);
    void draw();
    void update(long miliseconds);
    void moveForward();
    void moveBackward();
    void rotateLeft();
    void rotateRight();
    void updateTexture();
    void translateTexture();
    void resetTexture();
};


#endif 