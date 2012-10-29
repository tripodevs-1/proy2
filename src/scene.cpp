//EJEMPLO DE UNA ESCENA COMPUESTA POR PRIMITIVAS OpenGL
#include <windows.h>  //suitable when using Windows 95/98/NT
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/glut.h>
#include "camera.h"

CCamera Camera;
void DrawNet(GLfloat size, GLint LinesX, GLint LinesZ)
{
	glBegin(GL_LINES);
	for (int xc = 0; xc < LinesX; xc++)
	{
		glVertex3f(	-size / 2.0 + xc / (GLfloat)(LinesX-1)*size,
					0.0,
					size / 2.0);
		glVertex3f(	-size / 2.0 + xc / (GLfloat)(LinesX-1)*size,
					0.0,
					size / -2.0);
	}
	for (int zc = 0; zc < LinesX; zc++)
	{
		glVertex3f(	size / 2.0,
					0.0,
					-size / 2.0 + zc / (GLfloat)(LinesZ-1)*size);
		glVertex3f(	size / -2.0,
					0.0,
					-size / 2.0 + zc / (GLfloat)(LinesZ-1)*size);
	}
	glEnd();
}

//<<<<<<<<<<<<<<<<<<< axis >>>>>>>>>>>>>>
void axis(double length)
{ // draw a z-axis, with cone at end
	glPushMatrix();
	glBegin(GL_LINES);
	   glVertex3d(0, 0, 0); glVertex3d(0,0,length); // along the z-axis
	glEnd();
	glTranslated(0, 0,length -0.2); 
	glutWireCone(0.04, 0.2, 12, 9);
	glPopMatrix();
}
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<< displayWire >>>>>>>>>>>>>>>>>>>>>>
void displayWire(void)
{
	glMatrixMode(GL_PROJECTION); // set the view volume shape
	glLoadIdentity();
	glOrtho(-2.0*64/48.0, 2.0*64/48.0, -2.0, 2.0, 0.1, 100);
	glMatrixMode(GL_MODELVIEW); // position and aim the camera
	glLoadIdentity();
	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen
			glColor3d(0,0,0); // draw black lines
			axis(0.5); // z-axis
	glPushMatrix(); 
	glRotated(90, 0,1.0, 0);
	axis(0.5); // y-axis
	glRotated(-90.0, 1, 0, 0);
	axis(0.5); // z-axis
	glPopMatrix();
	glPushMatrix();
	glTranslated(0.5, 0.5, 0.5); // big cube at (0.5, 0.5, 0.5)
	glutWireCube(1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.0,1.0,0); // sphere at (1,1,0)
	glutWireSphere(0.25, 10, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.0,0,1.0); // cone at (1,0,1)
	glutWireCone(0.2, 0.5, 10, 8);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1,1,1);
	glutWireTeapot(0.2); // teapot at (1,1,1)
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.0 ,0); // torus at (0,1,0)
	glRotated(90.0, 1,0,0);
	glutWireTorus(0.1, 0.3, 10,10);
	glPopMatrix();
	glPushMatrix();
	glTranslated(1.0, 0 ,0); // dodecahedron at (1,0,0)
	glScaled(0.15, 0.15, 0.15);
	glutWireDodecahedron();
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 1.0 ,1.0); // small cube at (0,1,1)
	glutWireCube(0.25);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0, 0 ,1.0); // cylinder at (0,0,1)
	GLUquadricObj * qobj;
	qobj = gluNewQuadric();
	gluQuadricDrawStyle(qobj,GLU_LINE);
	gluCylinder(qobj, 0.2, 0.2, 0.4, 8,8);
	glPopMatrix();
	glFlush();
}
void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	Camera.Render();
	glTranslatef(0.0,0.8,0.0);

	glScalef(3.0,1.0,3.0);
	
	GLfloat size = 2.0;
	GLint LinesX = 30;
	GLint LinesZ = 30;
	
	GLfloat halfsize = size / 2.0;
	glColor3f(1.0,1.0,1.0);
	glPushMatrix();
		glTranslatef(0.0,-halfsize ,0.0);
		DrawNet(size,LinesX,LinesZ);
		glTranslatef(0.0,size,0.0);
		DrawNet(size,LinesX,LinesZ);
	glPopMatrix();
	glColor3f(0.0,0.0,1.0);
	glPushMatrix();
		glTranslatef(-halfsize,0.0,0.0);	
		glRotatef(90.0,0.0,0.0,halfsize);
		DrawNet(size,LinesX,LinesZ);
		glTranslatef(0.0,-size,0.0);
		DrawNet(size,LinesX,LinesZ);
	glPopMatrix();
	glColor3f(1.0,0.0,0.0);
	glPushMatrix();
		glTranslatef(0.0,0.0,-halfsize);	
		glRotatef(90.0,halfsize,0.0,0.0);
		DrawNet(size,LinesX,LinesZ);
		glTranslatef(0.0,size,0.0);
		DrawNet(size,LinesX,LinesZ);
	glPopMatrix();
	
	glFlush();  
	glutSwapBuffers();

}
void KeyDown(unsigned char key, int x, int y)
{
	switch (key) 
	{
	case 27:		//ESC
		PostQuitMessage(0);
		break;
	case 'a':		
		Camera.RotateY(5.0);
		Display();
		break;
	case 'd':		
		Camera.RotateY(-5.0);
		Display();
		break;
	case 'w':		
		Camera.MoveForwards( -0.1 ) ;
		Display();
		break;
	case 's':		
		Camera.MoveForwards( 0.1 ) ;
		Display();
		break;
	case 'x':		
		Camera.RotateX(5.0);
		Display();
		break;
	case 'y':		
		Camera.RotateX(-5.0);
		Display();
		break;
	case 'c':		
		Camera.StrafeRight(-0.1);
		Display();
		break;
	case 'v':		
		Camera.StrafeRight(0.1);
		Display();
		break;
	case 'f':
		Camera.Move(F3dVector(0.0,-0.3,0.0));
		Display();
		break;
	case 'r':
		Camera.Move(F3dVector(0.0,0.3,0.0));
		Display();
		break;

	}
}


//<<<<<<<<<<<<<<<<<<<<<< main >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB );
	glutInitWindowSize(640,480);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Transformation testbed - wireframes");
	glutDisplayFunc(displayWire);
	glClearColor(1.0f, 1.0f, 1.0f,0.0f);  // background is white
	glViewport(0, 0, 640, 480);
	Camera.Move( F3dVector(0.0, 0.0, 3.0 ));
	Camera.MoveForwards( 1.0 );
	glutDisplayFunc(Display);
	glutKeyboardFunc(KeyDown);

	glutMainLoop();
}