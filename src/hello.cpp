//#include <GL/glut.h>
//#include <GL/GL.h>
//#include <GL/GLU.h>
// 
//GLfloat anguloCuboX = 0.0f;
//GLfloat anguloCuboY = 0.0f;
//GLfloat anguloEsfera = 0.0f;
// 
//GLint ancho=400;
//GLint alto=400;
// 
//int hazPerspectiva = 0;
// 
//void reshape(int width, int height)
//{
//    glViewport(0, 0, width, height);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    
//    if(hazPerspectiva)
//     gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f);
//    else
//
//      glOrtho(-4,4, -4, 4, 1, 10);
//
//    glMatrixMode(GL_MODELVIEW);
// 
//    ancho = width;
//    alto = height;
//}
// 
//void drawCube(void)
//{
//    glColor3f(1.0f, 0.0f, 0.0f);
//    glBegin(GL_QUADS);       //cara frontal
//		glVertex3f(-1.0f, -1.0f,  1.0f);
//		glVertex3f( 1.0f, -1.0f,  1.0f);
//		glVertex3f( 1.0f,  1.0f,  1.0f);
//		glVertex3f(-1.0f,  1.0f,  1.0f);
//
//    glEnd();
//
//    glColor3f(0.0f, 1.0f, 0.0f);
//
//    glBegin(GL_QUADS);       //cara trasera
//		glVertex3f( 1.0f, -1.0f, -1.0f);
//		glVertex3f(-1.0f, -1.0f, -1.0f);
//		glVertex3f(-1.0f,  1.0f, -1.0f);
//		glVertex3f( 1.0f,  1.0f, -1.0f);
//
//    glEnd();
//
//    glColor3f(0.0f, 0.0f, 1.0f);
//    glBegin(GL_QUADS);       //cara lateral izq
//		glVertex3f(-1.0f,-1.0f, -1.0f);
//		glVertex3f(-1.0f,-1.0f,  1.0f);
//		glVertex3f(-1.0f, 1.0f,  1.0f);
//		glVertex3f(-1.0f, 1.0f, -1.0f);
//    glEnd();
//
//    glColor3f(1.0f, 1.0f, 0.0f);
//    glBegin(GL_QUADS);       //cara lateral dcha
//		glVertex3f(1.0f, -1.0f,  1.0f);
//		glVertex3f(1.0f, -1.0f, -1.0f);
//		glVertex3f(1.0f,  1.0f, -1.0f);
//		glVertex3f(1.0f,  1.0f,  1.0f);
//    glEnd(); 
//    glColor3f(0.0f,      1.0f, 1.0f);
//    glBegin(GL_QUADS);       //cara arriba
//		glVertex3f(-1.0f, 1.0f,  1.0f);
//		glVertex3f( 1.0f, 1.0f,  1.0f);
//		glVertex3f( 1.0f, 1.0f, -1.0f);
//		glVertex3f(-1.0f, 1.0f, -1.0f);
//    glEnd();
// 
//    glColor3f(1.0f, 0.0f, 1.0f);
//    glBegin(GL_QUADS);       //cara abajo
//		glVertex3f( 1.0f,-1.0f, -1.0f);
//		glVertex3f( 1.0f,-1.0f,  1.0f);
//		glVertex3f(-1.0f,-1.0f,  1.0f);
//		glVertex3f(-1.0f,-1.0f, -1.0f);
//    glEnd();
//}
//
//void display()
//{
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
// 
//    glLoadIdentity();
// 
//    glTranslatef(0.0f, 0.0f, -5.0f);
// 
//    glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f);
//    glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f);
// 
//    drawCube();
// 
//    glLoadIdentity();
// 
//    glTranslatef(0.0f, 0.0f, -5.0f);
//    glRotatef(anguloEsfera, 0.0f, 1.0f, 0.0f);
//    glTranslatef(3.0f, 0.0f, 0.0f);
// 
//    glColor3f(1.0f, 1.0f, 1.0f);
//    glutWireSphere(0.5f, 8, 8);
// 
//    glFlush();
//    glutSwapBuffers();
// 
//    anguloCuboX+=0.1f;
//    anguloCuboY+=0.1f;
//    anguloEsfera+=0.2f;
//}
//
//void init()
//{
//    glClearColor(0,0,0,0);
//    glEnable(GL_DEPTH_TEST);
//    ancho = 400;
//    alto = 400;
//}
// 
//
//void idle()
//{
//    display();
//}
// 
//void keyboard(unsigned char key, int x, int y)
//{
//    switch(key)
//    {
//    case 'p':
//    case 'P':
//      hazPerspectiva=1;
//      reshape(ancho,alto);
//      break;
// 
//    case 'o':
//    case 'O':
//      hazPerspectiva=0;
//      reshape(ancho,alto);
//      break;
// 
//    case 27:   // escape
//      exit(0);
//      break;
//    }
//}
 
//int main(int argc, char **argv)
//{
//	//negocia con el sistema de ventanas para abrir una
//    glutInit(&argc, argv);
//	//modo en que se dibujara las ventanas (flags)
//    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
//	//posicion de la ventana que se abrira con respecto a la pantalla
//    glutInitWindowPosition(100, 100);
//    glutInitWindowSize(ancho, alto);
//    glutCreateWindow("Camera 1");
//    init();
//    glutDisplayFunc(display);
//    glutReshapeFunc(reshape);
//    glutIdleFunc(idle);
//    glutKeyboardFunc(keyboard);
//	//cede el flujo del programa a glut
//    glutMainLoop();
//    return 0;
//}