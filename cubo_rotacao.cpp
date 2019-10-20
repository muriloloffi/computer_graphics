#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>
#define PI 3.1415926535898


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,1.0);
	//GLfloat parametro = 1;
	//glRotatef(45,1,1,0);
	/*glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1, 1, -1, 1, 0.0, 40.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glRotatef(45.0, 1.0, 1.0, 1.0);*/
	GLfloat vertices[8][3] = {{0,0,0},{1,0,0},{1,1,0},{0,1,0},{0,0,1},{1,0,1},{1,1,1},{0,1,1}};
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[2]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[0]);
	glEnd();
	/*glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
		glVertex3fv(vertices[i]);
	glEnd();
	*/			
		
				
	/*
		for (GLfloat i = 0; i < parametro; i+=0.01)
		{
			glColor3f(1.0,0.0,0.0);
			GLfloat x = 0+i*(1-0);
			GLfloat y = 0+i*(0-0);
			//GLfloat angle = 2*PI*i/circle_points;
			glVertex2f(x,y);
		}
		glBegin(GL_POINTS);
		for (GLfloat i = 0; i < parametro; i+=0.01)
		{
			glColor3f(0.0,1.0,0.0);
			GLfloat x = 0+i*(0-0);
			GLfloat y = 0+i*(1-0);
			//GLfloat angle = 2*PI*i/circle_points;
			glVertex2f(x,y);
		}
		glBegin(GL_POINTS);
		for (GLfloat i = 0; i < parametro; i+=0.01)
		{
			glColor3f(0.0,0.0,1.0);
			GLfloat x = 0+i*(1-0);
			GLfloat y = 0+i*(1-0);
			//GLfloat angle = 2*PI*i/circle_points;
			glVertex2f(x,y);
		}
	*/
	//glEnd();
	glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
	if (key == 'q' || key == 'Q')
	exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[])
{
	// Initialize GLUT
	glutInit(&argc, argv);
	// Create a window
	glutCreateWindow("OpenGL example");
	// Register display callback
	glutDisplayFunc(display);
	// Register keyboard callback
	glutKeyboardFunc(keyboard);
	// Enter main event loop
	glutMainLoop();

	return (EXIT_SUCCESS);
}
