#include "MyClockHand.h"

MyClockHand::MyClockHand(float size) {
	Cil = new myCylinder(12, 1, true);
	this->size = size;
	angle = 0;

	float amb[3] = { 0.2, 0.2, 0.2 };
	float dif[3] = { 0.1, 0.1, 0.1 };
	float spec[3] = { 0.2, 0.2, 0.2 };
	float shininess = 60.f;

	texture = new CGFappearance(amb, dif, spec, shininess);
}

void MyClockHand::draw() {
	glPushMatrix();

	texture->apply();

	glRotated(-angle, 0, 0, 1);
	glRotated(-90, 1, 0, 0);
	glScaled(0.02, 0.02, size);
	Cil->draw();

	glPopMatrix();
}

MyClockHand::~MyClockHand() {
	delete (Cil);
	delete (texture);
}

float MyClockHand::getAngle() {
	return angle;
}

void MyClockHand::setAngle(float angle) {
	this->angle = angle;
}

void MyClockHand::incAngle(float angle) {
	this->angle += angle;
}
