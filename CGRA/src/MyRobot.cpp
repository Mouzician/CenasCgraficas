#include "myRobot.h"

MyRobot::MyRobot(int Stacks)
{
	this->mode = 1;
	this->texture = 1;
    rotation = x = y = z = 0;
	stacks = Stacks;

	double pi = acos(-1);

	double tmp = 5*pi/4;

	Point ponto(0,0,0);	

	// Base posicao 0

	for(double i = 0; i < 3; i++) {
		ponto.x = -0.5;
		ponto.y = 0;
		ponto.z = -0.5 + (i/3);
		pontos_base.push_back(ponto);
	}

	for(double i = 0; i < 3; i++) {
		ponto.x = -0.5 + (i/3);
		ponto.y = 0;
		ponto.z = 0.5;
		pontos_base.push_back(ponto);
	}

	for(double i = 0; i < 3; i++) {
		ponto.x = 0.5;
		ponto.y = 0;
		ponto.z = 0.5 - (i/3);
		pontos_base.push_back(ponto);
	}

	for(double i = 0; i < 3; i++) {
		ponto.x = 0.5 - (i/3);
		ponto.y = 0;
		ponto.z = -0.5;
		pontos_base.push_back(ponto);
	}


	//TOPO posicao 1
	
	ponto.x = 0.25*cos(tmp);
	ponto.y = 1;
	ponto.z = 0.25*sin(tmp);
	pontos_circulo.push_back(ponto);
	
	for(unsigned int i = 1; i < 12; i++) {
		tmp -= pi/6;
		ponto.x = 0.25*cos(tmp);
		ponto.y = 1;
		ponto.z = 0.25*sin(tmp);
		pontos_circulo.push_back(ponto);
	}
	
	// STACKS

	for(unsigned int i=0;i<pontos_base.size();i++)
		figura.push_back(calculateReta(pontos_base[i],pontos_circulo[i]));

	//  NORMAIS
	
	for(unsigned int i = 0; i < figura.size(); i++) {

		// Base 

		vector<Point> points;

		if(i == 0)
			points.push_back(figura[figura.size()-1][0].coord);
		else
			points.push_back(figura[(i-1)][0].coord);

		points.push_back(figura[(i+1)%figura.size()][0].coord);

		if(figura.size() > 1) {
			points.push_back(figura[(i+1)%figura.size()][1].coord);
			if(i == 0)
				points.push_back(figura[figura.size()-1][1].coord);
			else
				points.push_back(figura[(i-1)][0].coord);
		}

		figura[i][0].normalFinal = newellsNormal(points);


		// Topo
		
		points.clear();

		if(figura.size() > 1) {
			if(i == 0) {
				points.push_back(figura[figura.size()-1][figura[i].size()-1].coord);
				points.push_back(figura[figura.size()-1][figura[i].size()-2].coord);
			} else {
				points.push_back(figura[(i-1)][figura[i].size()-1].coord);
				points.push_back(figura[(i-1)][figura[i].size()-2].coord);

			}

			points.push_back(figura[(i+1)%figura.size()][figura[i].size()-2].coord);
			points.push_back(figura[(i+1)%figura.size()][figura[i].size()-1].coord);

			figura[i][figura[i].size()-1].normalFinal = newellsNormal(points);
		}
		
		
		// Restantes

		for(unsigned int j = 1; j < figura[i].size()-1; j++) {

			points.clear();

			// 1
			if(i == 0)
				points.push_back(figura[figura.size()-1][j].coord);
			else
				points.push_back(figura[(i-1)][j].coord);

			// 6 e 5
			points.push_back(figura[i][j-1].coord);
			points.push_back(figura[(i+1)%figura.size()][j-1].coord);

			// 4
			points.push_back(figura[(i+1)%figura.size()][j].coord);

			// 3 e 2
			if(j < (figura[i].size()-1)) {
				points.push_back(figura[i][j+1].coord);
				if(i == 0)
					points.push_back(figura[figura.size()-1][j+1].coord);
				else
					points.push_back(figura[(i-1)][j+1].coord);
			}

			figura[i][j].normalFinal = newellsNormal(points);

		}
	}
	


}

vector< Vertice > MyRobot::calculateReta(Point point1, Point point2)
{
	Point scales(0,0,0);	
	vector< Vertice > res;

	scales.x = point2.x - point1.x;
	scales.y = point2.y - point1.y;
	scales.z = point2.z - point1.z;

	for(double i=0;i<=stacks;i++)
	{
		Vertice resultado;
		double t = ( i/stacks - point1.y ) / scales.y; 

		resultado.coord.x = t*scales.x + point1.x;
		resultado.coord.y = t*scales.y + point1.y;
		resultado.coord.z = t*scales.z + point1.z;

		//std::cout << "x: " << resultado.coord.x << " | y: " << resultado.coord.y << " | z: " << resultado.coord.z << std::endl;

		res.push_back(resultado);
	}
	//std::cout << std::endl;
	return res;
}

void MyRobot::draw()
{
	glPushMatrix();
	if(mode==0)
		glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );

	glTranslated(x,y,z);
	glRotated(rotation,0,1,0);

	for(unsigned int j = 0; j < figura.size(); j++) {
		glBegin(GL_TRIANGLE_STRIP);
		for(unsigned int i = 0; i < figura[j].size(); i++) {

			glTexCoord2f(figura[j][i].coord.x + 0.5  ,-figura[j][i].coord.z + 0.5);

			glNormal3d(figura[j][i].normalFinal.x,figura[j][i].normalFinal.y,figura[j][i].normalFinal.z);
			glVertex3d(figura[j][i].coord.x, figura[j][i].coord.y, figura[j][i].coord.z);

			if(j == figura.size()-1) {
				glTexCoord2f(figura[0][i].coord.x + 0.5, -figura[0][i].coord.z + 0.5);

				glNormal3d(figura[0][i].normalFinal.x,figura[0][i].normalFinal.y,figura[0][i].normalFinal.z);
				glVertex3d(figura[0][i].coord.x, figura[0][i].coord.y, figura[0][i].coord.z);
			} else {
				glTexCoord2f(figura[j+1][i].coord.x + 0.5, -figura[j+1][i].coord.z + 0.5);

				glNormal3d(figura[j+1][i].normalFinal.x,figura[j+1][i].normalFinal.y,figura[j+1][i].normalFinal.z);
				glVertex3d(figura[j+1][i].coord.x, figura[j+1][i].coord.y, figura[j+1][i].coord.z);
			}
		}
		glEnd();
	}


	glBegin(GL_POLYGON);
	glNormal3d(0,1,0);


	for(unsigned int i = 0; i < figura.size(); i++) {
		glTexCoord2f(figura[i][figura[i].size()-1].coord.x + 0.5, -figura[i][figura[i].size()-1].coord.z + 0.5);
		glVertex3d(figura[i][figura[i].size()-1].coord.x, figura[i][figura[i].size()-1].coord.y, figura[i][figura[i].size()-1].coord.z);
	}
	glEnd();

	glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );

	glPopMatrix();

}

Point MyRobot::surfacenormal(Point point1, Point point2, Point point3)
{

	Point resultado(0,0,0);	
	Point vector1(0,0,0);	
	Point vector2(0,0,0);	

	vector1 = point2 - point1;
	vector2 = point3 - point1;
	resultado = vector1 - vector2;

	double norma = sqrt( resultado.x * resultado.x + resultado.y * resultado.y + resultado.z * resultado.z);

	if(norma != 0) {
		resultado.x /= norma;
		resultado.y /= norma;
		resultado.z /= norma;
	}

	return resultado;
}

Point MyRobot::newellsNormal(vector<Point> points) {

	Point normal(0,0,0);

	for(unsigned int i = 0; i < points.size(); i++) {

		Point current = points[i];
		Point next = points[(i+1)%points.size()];

		normal.x += (current.y - next.y) * (current.z + next.z);
		normal.y += (current.z - next.z) * (current.x + next.x);
		normal.z += (current.x - next.x) * (current.y + next.y);
	}

	double norma = sqrt( normal.x * normal.x + normal.y * normal.y + normal.z * normal.z);

	if(norma != 0) {
		normal.x /= norma;
		normal.y /= norma;
		normal.z /= norma;
	}

	return normal;
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

	else if (this->texture == 5)
	texture->setTexture("robot5.jpg");

	texture->apply();
}
