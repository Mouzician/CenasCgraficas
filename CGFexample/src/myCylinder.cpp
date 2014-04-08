#include "myCylinder.h"

myCylinder::myCylinder(int slices, int stacks, bool smooth) {

	this->slices=slices;
	this->stacks=stacks;
	this->smooth=smooth;
}


void myCylinder::draw()
{
	
	float angle = 360/slices; 		//angulo
	float it = 0 ;		//contador do angulo para cada rotacao
	float stc=stacks;	//nr de stacks
	float nr_stacks=0;		//contador de stacks
	
  
    float coss = cos(((angle/2) * 3.14)/180); 
    float sen = sin(((angle/2) * 3.14)/180); 
  
  
    glBegin(GL_POLYGON); 
        for(int i=0; i<slices;i++){ 
  
            float coss2 = cos(((angle*i) * 3.14)/180); 
            float sen2 = sin(((angle*i) * 3.14)/180); 
  
            glVertex3d(sen2,1,coss2);           
        } 
  
        glEnd(); 
  
        glPushMatrix(); 
  
        glRotatef(180, 1,0,0); 
        glBegin(GL_POLYGON); 
        for(int i=0; i<slices;i++)
		{ 
             float coss2 = cos(((angle*i) * 3.14)/180); 
            float sen2 = sin(((angle*i) * 3.14)/180); 
 
            glVertex3d(sen2,0,coss2);    
        } 
  
        glEnd(); 
  
        glPopMatrix(); 
  
  
    for(int s=0; s<stacks;s++)		// desenha cada andar do cilindro  
	{ 
          
        glPushMatrix(); 
        glTranslatef(0,nr_stacks,0);		// quando aumenta o s_it, desenha mais acima 
  
  
    for(int i=0; i < slices; i++)	// desenha cada face do cilindro 
    { 
        glPushMatrix(); 
          
        glRotatef(it,0,1,0);		// roda o angulo para a posiçao certa 
        glTranslatef(0,0,-coss);  
  
        if(smooth)		    // normais sao definidas como se se desenhasse um cilindro perfeito 
		{   
        glBegin(GL_POLYGON); 
        glNormal3f(-sen,0,-coss); 
        glVertex3d(-sen,0,0); 
        glNormal3f(-sen,0,-coss); 
        glVertex3d(-sen,1/stc,0); 
        glNormal3f(sen,0,-coss); 
        glVertex3d(sen,1/stc,0); 
        glNormal3f(sen,0,-coss); 
        glVertex3d(sen,0,0); 
          
        glEnd(); 
        glPopMatrix(); 
  
        }
		else		    // normais definidas para a visualizaçao de um paralelepipedo com varios lados 
		{ 
        glBegin(GL_POLYGON); 
        glNormal3f(0,0,-1); 
        glVertex3d(-sen,0,0); 
        glNormal3f(0,0,-1); 
        glVertex3d(-sen,1/stc,0); 
        glNormal3f(0,0,-1); 
        glVertex3d(sen,1/stc,0); 
        glNormal3f(0,0,-1); 
        glVertex3d(sen,0,0); 
          
        glEnd(); 
        glPopMatrix(); 
        } 
        it+=angle;     
} 
  
    glPopMatrix(); 
    nr_stacks+=1/stc; 

    } 
}