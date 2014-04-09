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

void Plane::drawT(int height, int width)
{
	glPushMatrix();
	glRotatef(180.0,1,0,0);
	glTranslatef(-0.5,0.0,-0.5);
	glScalef(1.0/(double) _numDivisions, 1 ,1.0/(double) _numDivisions);
	glNormal3f(0,-1,0);



	//getting texture width
	int texW;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0 , GL_TEXTURE_WIDTH, &texW );

	//getting texture height
	int texH;
	glGetTexLevelParameteriv(GL_TEXTURE_2D, 0 , GL_TEXTURE_WIDTH, &texH);

	double inc = ((texW*height/width)/texH)/2;

	for (int bx = 0; bx<_numDivisions; bx++)
	{
		glBegin(GL_TRIANGLE_STRIP);
		glTexCoord2d(0-inc ,0);
		glVertex3f(bx, 0, 0);
		for (int bz = 0; bz<_numDivisions; bz++)
		{
			glTexCoord2d((bx+1)/(_numDivisions*1.0)  ,bz/(_numDivisions*1.0));
			glVertex3f(bx + 1, 0, bz);
			glTexCoord2d(bx/(_numDivisions*1.0)  ,(bz+1)/(_numDivisions*1.0));
			glVertex3f(bx, 0, bz + 1);
		}
		glTexCoord2d(1+inc  , 1);
		glVertex3d(bx+ 1, 0, _numDivisions);

		glEnd();
	}
	glPopMatrix();

}