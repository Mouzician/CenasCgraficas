#include "myRobot.h"
#include <iostream>
using namespace std;





MyRobot::MyRobot(int stacks){
	this->mode = 1;
	this->texture = 1;
	this->stacks = stacks;
    rotation = x = y = z = 0;

    slices = 12;
    double r = 0.25;
    
    vector<Point> base;
    vector<Point> top;
    
    for(double ang = 45.0; ang < 405.0; ang += (360.0 / slices)) {
        double rad = ang * PI / 180; // degrees to radians
        top.push_back( Point(r * cos(rad), 1.0, r * sin(rad)) );
    } // criar os vertices no topo
    
    double delta = 1.0/3.0; // distancia num lado do quadrado a cada vertice
    deltaSide = stacks+1; // numero de pontos numa aresta vertical


	// Criar os vertices na base
    base.push_back(Point(0.5, 0.01, 0.5)); // top right
    
    // (top) right to left
    base.push_back(Point(0.5-delta, 0.01, 0.5));
    base.push_back(Point(0.5-2*delta, 0.01, 0.5));
   
    base.push_back(Point(-0.5, 0.01, 0.5)); // top left
    
    // (left) top to bottom
    base.push_back(Point(-0.5, 0.01, 0.5-delta));
    base.push_back(Point(-0.5, 0.01, 0.5-2*delta));

    base.push_back(Point(-0.5, 0.01, -0.5)); // bottom left
    
    // (bottom) left to right
    base.push_back(Point(-0.5+delta, 0.01, -0.5));
    base.push_back(Point(-0.5+2*delta, 0.01, -0.5));
    
    base.push_back(Point(0.5, 0.01, -0.5)); // bottom right
    
    // (right) bottom to top
    base.push_back(Point(0.5, 0.01, -0.5+delta));
    base.push_back(Point(0.5, 0.01, -0.5+2*delta));
    


	// passar vertices da base para a deque
    for (unsigned int i = 0; i < base.size(); ++i){
        texels.push_back(vector<Point>());
    }

    
    for(unsigned int i = 0; i < base.size(); ++i){
        // 2 vertices correspondentes da base e topo
		Point P(base.at(i).x, base.at(i).y, base.at(i).z);
        Point Q(top.at(i).x, top.at(i).y, top.at(i).z);

		// vetor P->Q
        Point delta(Q.x - P.x, Q.y - P.y, Q.z - P.z);

        for(double t = 0.0; t <= 1.0; t += (1.0/stacks)){
            // recta -> P + (Q-P)*t
			// ir adicionando os vertices desta reta no vetor Side
            side.push_back(Point(P.x + delta.x * t,
                                 P.y + delta.y * t,
                                 P.z + delta.z * t));
			// guardar pontos para as texturas
            texels.at(i).push_back(Point( ((P.x + delta.x * t)+0.5),
                                        1-((P.z + delta.z * t)+0.5)) );
            
        }
    }
    int multiplier;
    int i; int j; int k;
    vector<Point> polygon;
    Point normal(0,0,0);
	

	// NORMAIS
    for(multiplier = 0; multiplier < 12; multiplier++){
        i = (multiplier*(deltaSide)) % (side.size());
        j = (multiplier+11)*(deltaSide) % (side.size());
        k = ((multiplier+1)*(deltaSide)) % (side.size());
        /*
		cout << "I : " << i << endl;
		cout << "I.x "<<side.at(i).x << endl;
		cout << "I.y" << side.at(i).y << endl;
		cout << "I.z" << side.at(i).z << endl;

		cout << "J : " << j << endl;
		cout << "J.x "<<side.at(j).x << endl;
		cout << "J.y" << side.at(j).y << endl;
		cout << "J.z" << side.at(j).z << endl;


		cout << "K : " << k << endl;
		cout << "k.x "<<side.at(k).x << endl;
		cout << "k.y" << side.at(k).y << endl;
		cout << "k.z" << side.at(k).z << endl;

		cout << "I + 1 : " << k << endl;
		cout << ".x "<<side.at(k).x << endl;
		cout << "k.y" << side.at(k).y << endl;
		cout << "k.z" << side.at(k).z << endl;

		cout << "K : " << k << endl;
		cout << "k.x "<<side.at(k).x << endl;
		cout << "k.y" << side.at(k).y << endl;
		cout << "k.z" << side.at(k).z << endl;

		*/
		
        // primeiras normais
        Point points[] = {side.at(j), side.at(i+1), side.at(k+1), side.at(k), side.at(i)};
		vector<Point> polygon (points, points + sizeof(points) / sizeof(Point) );
        normal = calculateSurfaceNormal(polygon);
        normals.push_back(normal);
        

		
        // intermedias
        for(int stack = 1; stack < stacks; stack++){
            i++; j++; k++;
            Point points[] = {side.at(i-1), side.at(j-1), side.at(j), side.at(i+1), side.at(k+1), side.at(k)};
            vector<Point> polygon (points, points + sizeof(points) / sizeof(Point) );
            normal = calculateSurfaceNormal(polygon);
            normals.push_back(normal);

			//system("pause");
        }

        // finais
        Point points2[] = {side.at(i), side.at(j), side.at(j+1), side.at(i+1), side.at(k+1)};
        vector<Point> polygon2 (points2, points2 + sizeof(points2) / sizeof(Point) );
        normal = calculateSurfaceNormal(polygon2);
        normals.push_back(normal);

		

    }
    
    x = 0.0;
    y = 0.0;
    z = 0.0;
}


void MyRobot::draw_1(){

	glPushMatrix();
	glTranslated( x, y, z );
    glRotated(rotation, 0, 1, 0);
	glBegin(GL_TRIANGLES);
		glVertex3f(0.5, 0.3, 0);
		glVertex3f(-0.5, 0.3, 0);
		glVertex3f(0, 0.3, 2);
	glEnd();
	glPopMatrix();

}


void MyRobot::draw(){
    
    glPushMatrix();

	if (mode == 0) glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glTranslated( x, y, z );
    glRotated(rotation, 0, 1, 0);
    
    // the top circle
    glBegin(GL_POLYGON);
    for (int i = side.size()-1; i >= 0; i -= deltaSide) {
        glNormal3d(0, 1, 0);
        glTexCoord2d(texels.at(i/deltaSide).at(i%deltaSide).x,
                     texels.at(i/deltaSide).at(i%deltaSide).y);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
    }
    glEnd();
    
    
    glBegin(GL_POLYGON);
    for (unsigned int i = 0; i < side.size(); i += deltaSide) {
        glNormal3d(0, -1, 0);
        glTexCoord2d(texels.at(i/deltaSide).at(i%deltaSide).x,
                     texels.at(i/deltaSide).at(i%deltaSide).y);
        glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
    }
    glEnd();
    
    int multiplier;
    int i; int j;
    for(multiplier = 1; multiplier < 13; multiplier++){
        i = (multiplier*(stacks + 1)) % (side.size());
        j = (multiplier-1)*(stacks+1);
        glBegin(GL_TRIANGLE_STRIP);

        for(int stack = 0; stack <= stacks; stack++){
            
            glTexCoord2d(texels.at(i/deltaSide).at(i%deltaSide).x,
                         texels.at(i/deltaSide).at(i%deltaSide).y);
           glNormal3d(normals.at(i).x, normals.at(i).y, normals.at(i).z);
            glVertex3d(side.at(i).x, side.at(i).y, side.at(i).z);
            i++;
            
            glTexCoord2d(texels.at(j/deltaSide).at(j%deltaSide).x,
                         texels.at(j/deltaSide).at(j%deltaSide).y);
            glNormal3d(normals.at(j).x, normals.at(j).y, normals.at(j).z);
            glVertex3d(side.at(j).x, side.at(j).y, side.at(j).z);
            j++;
        }
        
        glEnd();
    }
    
    if (mode == 0) glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

    glPopMatrix();
}

void MyRobot::rotateLeft(){
	rotation += 5;
}
void MyRobot::rotateRight(){
	rotation -= 5;
}
void MyRobot::moveForward(){
	x = x+sin(rotation*PI/180.0);
	z = z +cos(rotation*PI/180.0);
}
void MyRobot::moveBackward(){
	x = x - sin(rotation*PI/180.0);
	z = z - cos(rotation*PI/180.0);
}


void MyRobot::ApllyText(CGFappearance* texture){

	if(this->texture == 1)
	texture->setTexture("robot1.jpg");

	else if (this->texture == 2)
	texture->setTexture("robot2.jpg");

	else if (this->texture == 3)
	texture->setTexture("robot3.jpg");

	else if (this->texture == 4)
	texture->setTexture("robot4.jpg");

	texture->apply();
}
