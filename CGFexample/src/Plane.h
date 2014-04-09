#pragma once

#include "CGF\CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void drawT(int height, int width);
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};

