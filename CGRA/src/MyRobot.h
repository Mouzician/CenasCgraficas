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


class MyRobot : public CGFobject {

	private:
		double rotation;
		double x, y, z;
		int stacks;
		  vector<Point> side;
    vector<Point> normals;
    deque<deque<Point> > texels;
		 int deltaSide;
		 int slices;

	public:
		int mode;
		int texture;
		MyRobot(int Stacks = 10);
		void draw();
		void rotateLeft();
		void rotateRight();
		void moveForward();
		void moveBackward();
		void ApllyText(CGFappearance* texture);
};
#endif