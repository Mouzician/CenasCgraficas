#pragma once

#include "CGF\CGFobject.h"
class Plane
{
public:
	Plane(void);
	Plane(int);
	~Plane(void);
	void draw();
	void draw(int divisions,double si, double ti, double sf, double tf);
	void setWindow(bool b);
private:
	int _numDivisions;
	bool _isWindow;
	// Number of triangles that constitute rows/columns
};

