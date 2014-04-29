#include "myCylinder.h"
#define _USE_MATH_DEFINES
#include <cmath>

const double convert = M_PI / 180; // graus para rads

myCylinder::myCylinder(int slices, int stacks, bool smooth) {
	this->slices=slices;
	this->stacks=stacks;
	this->smooth=smooth;
}

void myCylinder::draw() {
	double alpha = 360.0 / slices;
	double x1, y1, x2, y2, z1, z2;
	double stackHeight;

	//base
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = cos(convert * alpha * i);
		y1 = sin(convert * alpha * i);

		glTexCoord2d(0.5 + x1 * 0.5, 0.5 + y1 * 0.5);
		glVertex3d(x1, y1, 1);
	}
	glEnd();

	// topo
	glPushMatrix();
	glRotated(180.0, 1, 0, 0);
	glNormal3d(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < slices; i++) {
		x1 = cos(convert * alpha * i);
		y1 = sin(convert * alpha * i);

		glVertex3d(x1, y1, 0);
	}
	glEnd();
	glPopMatrix();

	// corpo
	x2 = cos(0);
	y2 = sin(0);
	stackHeight = 1.0 / stacks;

	for (int i = 0; i < slices; i++) {
		x1 = x2;
		y1 = y2;
		x2 = cos(convert * alpha * (i + 1));
		y2 = sin(convert * alpha * (i + 1));
		z2 = 1;

		if (!smooth) {
			double ax, ay;
			ax = (x1 + x2) / 2;
			ay = (y1 + y2) / 2;

			double nx, ny, nc;
			nc = sqrt(ax * ax + ay * ay);
			nx = ax / nc;
			ny = ay / nc;

			glNormal3d(nx, ny, 0);
		}

		for (int j = 0; j < stacks; j++) {
			z1 = z2;
			z2 -= stackHeight;

			glBegin(GL_QUADS);

			if (smooth)
				glNormal3d(x1, y1, 0);
			glVertex3d(x1, y1, z1);
			glVertex3d(x1, y1, z2);

			if (smooth)
				glNormal3d(x2, y2, 0);
			glVertex3d(x2, y2, z2);
			glVertex3d(x2, y2, z1);

			glEnd();
		}
	}
}