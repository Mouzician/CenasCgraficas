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


struct Vertice {

    Point coord;
    Point normalFinal;

};
class MyRobot : public CGFobject {

	private:
		double rotation;
		double x, y, z;
		int stacks;
		vector< vector< Vertice > > figura;
		vector< Point > pontos_circulo;
		vector< Point > pontos_base;

	public:
		int mode;
		int texture;
		Point surfacenormal(Point point1,Point point2, Point point3);
		Point newellsNormal(vector<Point> points);
		MyRobot(int Stacks = 10);
		void draw();
		vector< Vertice > calculateReta(Point point1, Point point2);
		void rotateLeft();
		void rotateRight();
		void moveForward();
		void moveBackward();
		void ModeChange();
		void ApllyText(CGFappearance* texture);
};
#endif