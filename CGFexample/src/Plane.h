#pragma once

#include "CGF\CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void draw(int divisions,int si, int ti, int sf, int tf);
private:
	int _numDivisions; // Number of triangles that constitute rows/columns
};

