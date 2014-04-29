#ifndef MYCLOCK_H_
#define MYCLOCK_H_

#include "myCylinder.h"
#include "MyClockHand.h"
#include "CGFappearance.h"

class MyClock {
private:
	myCylinder* clockP;
	MyClockHand* hoursP;
	MyClockHand* minutesP;
	MyClockHand* secondsP;

	CGFappearance* texture;

	unsigned long seconds;

public:
	MyClock();
	void update(unsigned long sysTime);
	void draw();
	virtual ~MyClock();
};

#endif /* MYCLOCK_H_ */
