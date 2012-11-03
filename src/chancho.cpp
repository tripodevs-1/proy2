#include "chancho.h"


//Constructor
Chancho::Chancho(){
}

//Destructor
Chancho::~Chancho(){
}

void Chancho::dibujar( void ){
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	//cuerpo
	glColor3f(0.45, 0.72, 0.42);
	glutSolidSphere(0.25,20,20);

	//orejas
	glTranslatef(-0.20, 0.25, 0.0);
	glColor3f(0.12, 0.34, 0.09);
	glutSolidSphere(0.10,20,20);
	glTranslatef(0.40, 0.0, 0.0);
	glutSolidSphere(0.10,20,20);

	//vuelve al origen
	glTranslatef(-0.2, -0.25, 0.0);

	//ojos
	glColor3f(0.56,0.3,0.0);
	glTranslatef(0.05, 0.10, 0.18);
	glutSolidSphere(0.05,10,10);
	glTranslatef(-0.1, 0.0, 0.0);
	glutSolidSphere(0.05,10,10);

	//boca
	glColor3f(0.0,0.0,0.0);
	glTranslatef(0.05, -0.15, 0.0);
	glutSolidSphere(0.08,10,10);

	glPopMatrix();
}

