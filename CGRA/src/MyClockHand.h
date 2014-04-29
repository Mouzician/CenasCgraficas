#ifndef MYCLOCKHAND_H_
#define MYCLOCKHAND_H_

#include "myCylinder.h"
#include "CGFappearance.h"

class MyClockHand {
private:
	myCylinder* Cil;
	float size;
	float angle;

	CGFappearance* texture;

public:
	MyClockHand(float size);
	void draw();
	virtual ~MyClockHand();

	float getAngle();
	void setAngle(float angle);
	void incAngle(float angle);
};

#endif /* MYCLOCKHAND_H_ */
