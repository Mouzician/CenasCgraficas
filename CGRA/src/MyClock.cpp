#include "MyClock.h"

MyClock::MyClock() {
	clockP = new myCylinder(12, 1, true);

	hoursP = new MyClockHand(0.4);
	hoursP->setAngle(90);

	minutesP = new MyClockHand(0.6);
	minutesP->setAngle(180);

	secondsP = new MyClockHand(0.7);
	secondsP->setAngle(270);

	// Coef para o clock
	float amb[3] = { 0.2, 0.2, 0.2 };
	float dif[3] = { 0.6, 0.6, 0.6 };
	float spec[3] = { 0.2, 0.2, 0.2 };
	float shininess = 60.f;

	texture = new CGFappearance(amb, dif, spec, shininess);
	texture->setTexture("clock.png");
	texture->setTextureWrap(GL_REPEAT, GL_REPEAT);

	seconds = 0;
}

void MyClock::update(unsigned long sysTime) {
	if (sysTime / 1000 != seconds) {
		seconds = sysTime / 1000;
		secondsP->incAngle(360 / 60);

		if ((int) (secondsP->getAngle()) % 360 == 0) {
			minutesP->incAngle(360 / 60);

			if ((int) (minutesP->getAngle()) % 360 == 0)
				hoursP->incAngle(360 / 12);
		}
	}
}

void MyClock::draw() {
	glPushMatrix();
	texture->apply();
	clockP->draw();
	glTranslated(0, 0, 1);
	hoursP->draw();
	minutesP->draw();
	secondsP->draw();

	glPopMatrix();
}

MyClock::~MyClock() {
	delete (clockP);
	delete (hoursP);
	delete (minutesP);
	delete (secondsP);

	delete (texture);
}
