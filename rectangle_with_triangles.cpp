#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>



void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Set fill color (R,G,B):
	glColor3f(1.0,1.0,1.0);
	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,1.0);
	//Just draw the triangles edges:
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 

	GLfloat vertices[8][3] = //Vector of vectors with vertices positions
	{
	/* 
	   1   2   3   4
	   *---*---*---*
	   | / | / | / |
	   *---*---*---*
	   0   5   6   7 
	*/
		{0,0,0}, //0-bottom-left
		{0,1,0}, //1-upper-left
		{1,1,0}, //2-upper-middle-left
		{2,1,0}, //3-upper-middle-right
		{3,1,0}, //4-upper-right
		{1,0,0}, //5-bottom-middle-left
		{2,0,0}, //6-bottom-middle-right
		{3,0,0}  //7-bottom-right
	};


	glBegin(GL_TRIANGLES); //triangle 1
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[2]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 2
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[0]);
	glEnd();	
	glBegin(GL_TRIANGLES); //triangle 3
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 4
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 5
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 6
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[7]);
		glVertex3fv(vertices[6]);
	glEnd();
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
	glutCreateWindow("OpenGL Cube");
	// Register display callback
	glutDisplayFunc(display);
	// Register keyboard callback
	glutKeyboardFunc(keyboard);
	// Enter main event loop
	glutMainLoop();

	return (EXIT_SUCCESS);
}
