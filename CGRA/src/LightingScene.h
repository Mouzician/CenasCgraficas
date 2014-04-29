#ifndef LightingScene_H
#define LightingScene_H

#include "CGFscene.h"
#include "CGFappearance.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"
#include "MyClock.h"

class LightingScene : public CGFscene
{
public:
	void init();
	void display();
	void update(unsigned long sysTime);

	CGFlight* light0;
	CGFlight* light1;
	CGFlight* light2;
	CGFlight* light3;
	CGFlight* light4;

	MyClock* clock;
	myTable* table;
	Plane* wall;
	Plane* boardA;
	Plane* boardB;
	CGFappearance* materialA;
	CGFappearance* materialB;
	myCylinder* cylinder;
	myCylinder* cylinder2;
	CGFappearance* windowAppearance;
	CGFappearance* floorAppearance;
	CGFappearance* slidesAppearance;
	CGFappearance* boardAppearance;
	CGFappearance* clockAppearance;

	~LightingScene();
};

#endif