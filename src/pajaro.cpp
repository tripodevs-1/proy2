#include "pajaro.h"


//Constructor
Pajaro::Pajaro(){
}

//Destructor
Pajaro::~Pajaro(){
}

void Pajaro::dibujar( void ){

	glPushMatrix();

		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glColor3f(1.0, 1.0,0.0);
		glutSolidSphere(0.25,20,20);

		glColor3f(0.0, 0.8 , 0.0);
		glTranslatef(0.0, 0.0, -0.25);
		glutSolidSphere(0.05, 20, 20);

		glTranslatef(0.0, 0.0, 0.25);

		glColor3f(0.8, 0.0, 0.0);
		glTranslatef(0.25, 0.0, 0.0);
		glutSolidSphere(0.1, 30, 30);
		glTranslatef(-0.5, 0.0, 0.0);
		glutSolidSphere(0.1, 30, 30);
		glColor3f(0.0,0.0,0.0);
		glTranslatef(0.30, 0.10, 0.18);
		glutSolidSphere(0.05,10,10);
		glTranslatef(-0.1, 0.0, 0.0);
		glutSolidSphere(0.05,10,10);
		glColor3f(1.0, 0.5 , 0.5);
		glRotatef(0.0,1.0, 0.0, 0.0);
		glTranslatef(0.05, -0.1, 0.0);
		glutSolidCone(0.08,0.2,10,2);
	
	glPopMatrix();
}

float Pajaro::getX(){ return x;}
float Pajaro::getY(){ return y;}
float Pajaro::getZ(){ return z;}
void Pajaro::setX(float xx){
	x = xx;
}
void Pajaro::setY(float yy){
	y = yy;
}
void Pajaro::setZ(float zz){
	z = zz;
}

void Pajaro::setPosition(float xx, float yy, float zz){
	x = xx;
	y = yy;
	z = zz;
}
