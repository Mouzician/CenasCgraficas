#include "MyView.h"

#ifndef __APPLE__
#include "GL/glext.h"
#endif

MyView::MyView(){
   view = new CGFappearance("view.jpg", GL_CLAMP_TO_EDGE, GL_CLAMP_TO_EDGE);
}

void MyView::draw()
{
    glPushAttrib(GL_ENABLE_BIT);
    //glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    glDisable(GL_BLEND);
  
    
	//view
    view->apply();
	glPushMatrix();
	glRotated(-90,0,1,0);
	glTranslated(0,0.5,0.5);
	glNormal3d(0,0,-1);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-HALF_SIZE, -HALF_SIZE, 0.0f);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 1.0f); glVertex3f( HALF_SIZE,  HALF_SIZE, 0.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( HALF_SIZE, -HALF_SIZE, 0.0f);
    glEnd();
	glPopMatrix();
    
    glPopAttrib();
	
}