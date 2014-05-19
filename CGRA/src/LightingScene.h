#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "MyClock.h"
#include "MyRobot.h"
#include "MyView.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long sysTime);
	void toggleSomething();

	int sceneVar;
	int ClockStop;

	CGFlight* light0; int light0On;
	CGFlight* light1; int light1On;
	CGFlight* light2; int light2On;
	CGFlight* light3; int light3On;
	CGFlight* light4; int light4On;

	MyClock* clock;
	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;
	myCylinder* cylinder;
	myCylinder* cylinder2;
	MyRobot* Robot;
	MyView* view;
	
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* clockAppearance;
	CGFappearance* robotAppearance;

	~LightingScene();
};

#endif