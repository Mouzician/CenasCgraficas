#include "myLamp.h"

MyLamp::MyLamp(int slices, int stacks): slices(slices), stacks(stacks){
    deltaTheta = (2.0 * PI / slices);
    deltaPhi = (PI / 2 / stacks);
    
    for(double angle = 0.0; angle <= 360.0; angle += (360.0 / slices)) {
        double rad = angle * PI / 180; // degrees to radians
        xBase.push_back(cos(rad));
        yBase.push_back(sin(rad));
    }
    
    float r = 1.0;
    
    for(float theta = 0; theta <= 2 * PI ; theta += deltaTheta)
	{
		for(float phi = 0; phi <= PI/2; phi += deltaPhi)
		{
            // we have to draw polygons with 4 vertexes
            // this way we are duplicating vertexes
            // but it is alot easier to understand and makes the code readable
            
			x1.push_back( r * sin(phi + deltaPhi) * cos(theta + deltaTheta) );
			y1.push_back( r * sin(phi + deltaPhi) * sin(theta + deltaTheta) );
			z1.push_back( r * cos(phi + deltaPhi) );
            
			x2.push_back( r * sin(phi) * cos(theta + deltaTheta) );
		 	y2.push_back( r * sin(phi) * sin(theta + deltaTheta) );
			z2.push_back( r * cos(phi) );
            
            x3.push_back( r * sin(phi) * cos(theta) );
			y3.push_back( r * sin(phi) * sin(theta) );
			z3.push_back( r * cos(phi) );
            
			x4.push_back( r * sin(phi + deltaPhi) * cos(theta) );
			y4.push_back( r * sin(phi + deltaPhi) * sin(theta) );
            z4.push_back( r * cos(phi + deltaPhi) );
		}
	}
}

void MyLamp::draw(){
    
    // the base
    glBegin(GL_POLYGON);
    for(int i = xBase.size()-1; i >= 0 ; i--) {
        glNormal3d( xBase.at(i), yBase.at(i), -1.0);
        glVertex3d( xBase.at(i), yBase.at(i), 0.0);
    }
    glEnd();
    
    // the semi sphere
	for(int i = 0; i < x1.size(); i++)
	{
        glBegin(GL_QUADS);

            glNormal3f( x4.at(i), y4.at(i), z4.at(i) );
            glTexCoord2d(0, 0);
			glVertex3f( x4.at(i), y4.at(i), z4.at(i) );
            
            glNormal3f( x1.at(i), y1.at(i), z1.at(i) );
            glTexCoord2d(1, 0);
			glVertex3f( x1.at(i), y1.at(i), z1.at(i) );
            
            glNormal3f( x2.at(i), y2.at(i), z2.at(i) );
            glTexCoord2d(1, 1);
			glVertex3f( x2.at(i), y2.at(i), z2.at(i) );
            
            glNormal3f( x3.at(i), y3.at(i), z3.at(i) );
            glTexCoord2d(0, 1);
            glVertex3f( x3.at(i), y3.at(i), z3.at(i) );
        glEnd();

	}
    
	return;
}