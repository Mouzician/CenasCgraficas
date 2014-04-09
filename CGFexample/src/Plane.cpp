#include "Plane.h"
#include <GL/GLU.h>


Plane::Plane(void)
{
	_numDivisions = 1;
}

Plane::Plane(int n)
{
	_numDivisions = n;
}


Plane::~Plane(void)
{
}

void Plane::draw()
{
	glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				glVertex3f(bx, 0, 0);
				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glVertex3f(bx + 1, 0, bz);
					glVertex3f(bx, 0, bz + 1);
				}
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}


void Plane::draw (int divisions,int si, int ti, int sf, int tf)
{
	    _numDivisions = divisions;
		glPushMatrix();
		glRotatef(180.0,1,0,0);
		glTranslatef(-0.5,0.0,-0.5);
		glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
		glNormal3f(0,-1,0);
		double div = 1/(float)_numDivisions;

		for (int bx = 0; bx<_numDivisions; bx++)
		{
			glBegin(GL_TRIANGLE_STRIP);
				glTexCoord2f(si+abs(sf-si)*(bx/(double)_numDivisions), 0);
				glVertex3f(bx, 0, 0);

				for (int bz = 0; bz<_numDivisions; bz++)
				{
					glTexCoord2f(si+abs(sf-si)*((bx+1)/(double)_numDivisions),ti+abs(tf-ti)*(bz/(double)_numDivisions));
					glVertex3f(bx + 1, 0, bz);
					glTexCoord2f(si+abs(sf-si)*(bx/(double)_numDivisions),ti+abs(tf-ti)*((bz+1)/(double)_numDivisions));
					glVertex3f(bx, 0, bz + 1);
				}
				glTexCoord2f(si+abs(sf-si)*((bx+1)/(double)_numDivisions),ti+abs(tf-ti));
				glVertex3d(bx+ 1, 0, _numDivisions);

			glEnd();
		}
	glPopMatrix();

}