#include "LightingScene.h"
#include "CGFaxis.h"
#include "CGFapplication.h"
#include "myTable.h"
#include "Plane.h"
#include "myCylinder.h"

#include <math.h>

/*float pi = acos(-1.0);
float deg2rad=pi/180.0;*/

#define BOARD_HEIGHT 6.0
#define BOARD_WIDTH 6.4

// Positions for two lights
float light0_pos[4] = {4, 6.0, 1.0, 1.0};
float light1_pos[4] = {10.5, 6.0, 1.0, 1.0};

float light2_pos[4] = {10.5, 6.0, 5.0, 1.0};
float light3_pos[4] = {4, 6.0, 5.0, 1.0};

float light4_pos[4] = {0.20, 4.0, 7.5, 1.0};


// Global ambient light (do not confuse with ambient component of individual lights)
float globalAmbientLight[4]= {0,0,0,1.0};

// number of divisions
#define BOARD_A_DIVISIONS 30 
#define BOARD_B_DIVISIONS 100

// Coefficients for material A
float ambA[3] = {0.2, 0.2, 0.2};
float difA[3] = {0.6, 0.6, 0.6};
float specA[3] = {0, 0, 0.8}; //{0.8, 0.8, 0.8}; //{0.2, 0.2, 0.2};
float shininessA = 120.f; //10.f;

// Coefficients for material B
float ambB[3] = {0.2, 0.2, 0.2};
float difB[3] = {0.6, 0.6, 0.6};
float specB[3] = {0.8, 0.8, 0.8};
float shininessB = 120.f;

//Coef for Board
float ambBoard[3] = {0.2, 0.2, 0.2};
float difBoard[3] = {0.3, 0.3, 0.3};
float specBoard[3] = {0.4, 0.4, 0.4};
float shininessBoard = 120.f;


//Coef for Slide
float ambSl[3] = {0.2, 0.2, 0.2};
float difSl[3] = {0.8, 0.8, 0.8};
float specSl[3] = {0.2, 0.2, 0.2};
float shininessSl = 10.f;

//Coef for floor
float ambF[3] = {0.2, 0.2, 0.2};
float difF[3] = {0.6, 0.6, 0.6};
float specF[3] = {0, 0, 0.8}; 
float shininessF = 120.f; //10.f;

//Coef for LeftWall
float ambW[3] = {0.2, 0.2, 0.2};
float difW[3] = {0.6, 0.6, 0.6};
float specW[3] = {0, 0, 0.8}; 
float shininessW = 120.f; //10.f;





float ambientNull[4]={0,0,0,1};
float yellow[4]={1,1,0,1};
float green[4]={0,1,0,1};

void LightingScene :: toggleSomething(){

}

void LightingScene::init() 
{
	sceneVar = 0;

	// Enables lighting computations
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);


	// Sets up some lighting parameters
	// Computes lighting only using the front face normals and materials
	glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);  
	
	// Define ambient light (do not confuse with ambient component of individual lights)
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, globalAmbientLight);  
	
	// Declares and enables two lights, with null ambient component
		glLightfv(GL_LIGHT0, GL_SPECULAR, yellow);

	light0 = new CGFlight(GL_LIGHT0, light0_pos);
	light0->setAmbient(ambientNull);


	light0->disable();
	light0->enable();

	light1 = new CGFlight(GL_LIGHT1, light1_pos);
	light1->setAmbient(ambientNull);
	
	light1->disable();
	light1->enable();
	

	//light2
	light2 = new CGFlight(GL_LIGHT2, light2_pos);
	light2->setAmbient(ambientNull);
	light2->setKc(0);
	//light2->setKl(0.2);
	light2->setKl(1);
	light2->setKq(0);
	
	light2->disable();
	light2->enable();

	//light3
	light3 = new CGFlight(GL_LIGHT3, light3_pos);
	light3->setAmbient(ambientNull);
	light3->setKc(0);
	light3->setKl(0);
	light3->setKq(0.2);
	
	light3->disable();
	light3->enable();

	//light4
	light4 = new CGFlight(GL_LIGHT4, light4_pos);
	light4->setAmbient(ambientNull);
	light4->setSpecular(green);
	light4->setKc(0.0);
	light4->setKl(0.0);
	light4->setKq(1.0);

	light4->disable();
	light4->enable();




	// Uncomment below to enable normalization of lighting normal vectors
	glEnable (GL_NORMALIZE);

	//Declares scene elements
	table = new myTable();
	wall = new Plane();
	boardA = new Plane(BOARD_A_DIVISIONS);
	boardB = new Plane(BOARD_B_DIVISIONS);
	cylinder = new myCylinder(30, 50, true);
	cylinder2 = new myCylinder(30, 50, false);
	
	//Declares materials
	materialA = new CGFappearance(ambA,difA,specA,shininessA);
	materialB = new CGFappearance(ambB,difB,specB,shininessB);


	//Declares Textures
	slidesAppearance = new CGFappearance(ambSl,difSl,specSl,shininessSl);
	slidesAppearance->setTexture("slides.png");
	slidesAppearance ->setTextureWrap(GL_CLAMP, GL_CLAMP);

	boardAppearance = new CGFappearance(ambBoard,difBoard,specBoard,shininessBoard);
	boardAppearance->setTexture("board.png");
	boardAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	floorAppearance = new CGFappearance(ambF,difF,specF,shininessF);
	floorAppearance->setTexture("floor.png");
	floorAppearance->setTextureWrap(GL_REPEAT, GL_REPEAT);

	windowAppearance = new CGFappearance(ambW,difW,specW,shininessW);
	windowAppearance->setTexture("window.png");
	windowAppearance->setTextureWrap(GL_CLAMP, GL_CLAMP);

	clockAppearance = new CGFappearance(ambW,difW,specW,shininessW);
	clockAppearance->setTexture("clock.png");
	clockAppearance->setTextureWrap(GL_CLAMP,GL_CLAMP);

}

void LightingScene::display() 
{
	

	// ---- BEGIN Background, camera and axis setup
	
	// Clear image and depth buffer everytime we update the scene
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Initialize Model-View matrix as identity (no transformation
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Apply transformations corresponding to the camera position relative to the origin
	CGFscene::activeCamera->applyView();

	light0->draw();
	light1->draw();
	light2->draw();
	light3->draw();
	light4->draw();

	// Draw axis
	axis.draw();

	// ---- END Background, camera and axis setup

	// ---- BEGIN Primitive drawing section

	//cylinder 1
	glPushMatrix();
	glTranslatef(1,0,14); 
    glScalef(1,8,1); 
	cylinder->draw();
	glPopMatrix();

	//cylinder 2
	glPushMatrix();
	glTranslatef(14,0,1); 
    glScalef(1,8,1); 
	cylinder2->draw();
	glPopMatrix();

	//First Table
	glPushMatrix();
		glTranslated(5,0,8);
		table->draw();
	glPopMatrix();

	//Second Table
	glPushMatrix();
		glTranslated(12,0,8);
		table->draw();
	glPopMatrix();

	//Floor
	glPushMatrix();
		glTranslated(7.5,0,7.5);
		glScaled(15,0.2,15);
		floorAppearance->apply();
		wall->draw(120,0, 0, 10, 12);
	glPopMatrix();

	//LeftWall
	glPushMatrix();
		glTranslated(0,4,7.5);
		glRotated(-90,0,0,1);
		glScaled(8,0.2,15);
		glRotated(90, 0, 1, 0);
		windowAppearance->apply();
		wall->draw(10, -1, -1, 2, 2);
	glPopMatrix();

	//PlaneWall
	glPushMatrix();
		glTranslated(7.5,4,0);
		glRotated(90.0,1,0,0);
		glScaled(15,0.2,8);
		wall->draw();
	glPopMatrix();


	// Board A
	glPushMatrix();
		glTranslated(4,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		//materialA->apply();
		slidesAppearance->apply();
		boardA->draw(BOARD_A_DIVISIONS, 0, 0, 1, 1);
	glPopMatrix();
	
	//PlaneB
	glPushMatrix();
		glTranslated(10.5,4,0.2);
		glScaled(BOARD_WIDTH,BOARD_HEIGHT,1);
		glRotated(90.0,1,0,0);
		//materialB->apply();
		boardAppearance->apply();
		boardB->draw(BOARD_B_DIVISIONS, 0, -0.14, 1, 1.14);

	glPopMatrix();


	
	
	// ---- END Primitive drawing section
	

	// We have been drawing in a memory area that is not visible - the back buffer, 
	// while the graphics card is showing the contents of another buffer - the front buffer
	// glutSwapBuffers() will swap pointers so that the back buffer becomes the front buffer and vice-versa
	glutSwapBuffers();
}

LightingScene::~LightingScene() 
{
	delete(light0);
	delete(light1);
	delete(light2);
	delete(light3);
	delete(light4);
	delete(table);
	delete(wall);
	delete(boardA);
	delete(boardB);
	delete(materialA);
	delete(materialB);
	delete(cylinder);
	delete(cylinder2);

}