#include "myTable.h"

void ExampleObject::draw() 
{
	glBegin(GL_QUADS);
		glVertex3d(0,0,0);
		glVertex3d(4,0,0);
		glVertex3d(4,3,0);
		glVertex3d(0,3,0);
	glEnd();

	glBegin(GL_TRIANGLES);
        glVertex3f(-1, 3, 0);
        glVertex3f(5, 3, 0);
        glVertex3f(2, 4, 0);
        glEnd();
}

void myrect(){
	glBegin(GL_QUADS);
		glTexCoord2f(-0.5,-0.5); glVertex3d(-0.5,-0.5,0);
		glTexCoord2f(0.5,-0.5);  glVertex3d(0.5,-0.5,0);
		glTexCoord2f(0.5,0.5);   glVertex3d(0.5,0.5,0);
		glTexCoord2f(-0.5,0.5); glVertex3d(-0.5,0.5,0);
		glEnd();
}


void myUnitCube::draw()
{

	//frente
	glPushMatrix();
	glTranslated(0,0,0.5);
	glNormal3f(0,0,1);
	myrect();
	glPopMatrix();

	//direita
	glPushMatrix();
	glTranslated(0.5,0,0);
	glRotated(-90,0, -1,0);
	glNormal3f(1,0,0);
	myrect();
	glPopMatrix();

	//esquerda
	glPushMatrix();
	glTranslated(-0.5,0,0);
	glRotated(-90,0, 1,0);
	glNormal3f(-1,0,0);
	myrect();
	glPopMatrix();

	//trás
	glPushMatrix();
	glTranslated(0,0,-0.5);
	glRotated(180,0, 1,0);
	glNormal3f(0,0,-1);
	myrect();
	glPopMatrix();

	//cima
	glPushMatrix();
	glTranslated(0,0.5,0);
	glRotated(-90,1, 0,0);
	glNormal3f(0,1,0);
	myrect();
	glPopMatrix();

	//baixo
	glPushMatrix();
	glTranslated(0,-0.5,0);
	glRotated(90,1, 0,0);
	glNormal3f(0,-1,0);
	myrect();
  glPopMatrix();		
}

// Coefficients for material T

float ambT[3] = {0.05375, 0.05, 0.06625};
float difT[3] = {0.18275, 0.17, 0.22525};
float specT[3] = {0.1, 0.1, 0.1};//{0.8,0.8,0.8}
float shininessT = 38.f;
// Coefficients for material P1
float ambP1[3] = {0.329412, 0.223529, 0.027451};
float difP1[3] = {0.780392, 0.568627, 0.113725};
float specP1[3] = {0.992157	, 0.941176	, 0.807843	};//{0.8,0.8,0.8}
float shininessP1 = 28.f;

// Coefficients for material P2
float ambP2[3] = {0.0, 0.0, 0.0};
float difP2[3] = {0.1, 0.35, 0.1};
float specP2[3] = {0.45, 0.55, 0.45};//{0.8,0.8,0.8}
float shininessP2 = 32.f;

//Coef for texture
float ambTx[3] = {0.2, 0.2, 0.2};
float difTx[3] = {10, 10, 10};
float specTx[3] = {0.8, 0.8, 0.8};
float shininessTx = 10.f;




void myTable :: draw(){

	materialT = new CGFappearance(ambT,difT,specT,shininessT);
	materialP1 = new CGFappearance(ambP1,difP1,specP1,shininessP1);
	
	
	CGFappearance* tableAppearance = new CGFappearance(ambTx,difTx,specTx,shininessTx);
	tableAppearance->setTexture("table.png");
	tableAppearance ->setTextureWrap(GL_REPEAT, GL_REPEAT);




	//Tampo
	myUnitCube top;
	glPushMatrix();
	tableAppearance->apply();
	glTranslated(0,3.65,0);
	glScaled(5,0.3,3);
	//materialT->apply();
	top.draw();
	glPopMatrix();

	//pernas
	glPushMatrix();
	glTranslated(-2.35,1.75,1.35);
	glScaled(0.3,3.5,0.3);
	materialP1->apply();
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(-2.35,1.75,-1.35);
	glScaled(0.3,3.5,0.3);
	materialP1->apply();
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.35,1.75,1.35);
	glScaled(0.3,3.5,0.3);
	materialP1->apply();
	cube.draw();
	glPopMatrix();

	glPushMatrix();
	glTranslated(2.35,1.75,-1.35);
	glScaled(0.3,3.5,0.3);
	materialP1->apply();
	cube.draw();
	glPopMatrix();
	
}



void myFloor :: draw(){
	glPushMatrix();
	glTranslated(0,0.05,0);
	glScaled(8,0.1,6);
	cube.draw();
	glPopMatrix();
}