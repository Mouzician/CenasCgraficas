#ifndef EXAMPLEOBJECT_H
#define EXAMPLEOBJECT_H

#include "CGFobject.h"
#include "CGFappearance.h"

class ExampleObject: public CGFobject {
	public:
		void draw();
};
class myUnitCube: public CGFobject {
	public:
		void draw();
};
class myTable: public CGFobject {
	myUnitCube cube;
	CGFappearance* materialT;
	CGFappearance* materialP1;
	CGFappearance* materialP2;

	public:
		void draw();
};
class myFloor: public CGFobject {
	myUnitCube cube;
	public:
		void draw();
};

#endif