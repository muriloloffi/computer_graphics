#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>
#include <unistd.h>


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Set fill color (R,G,B):
	glColor3f(1.0,1.0,1.0);
	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,1.0);
	//(angle of rotation, (x, y, z) of a vector) 
	glRotatef(45,1,0.5,1);
	//Just draw the triangles edges:
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 

	GLfloat vertices[8][3] = //Vector of vectors with cube vertices positions
	{
		{0,0,0}, //0-front-bottom-left
		{0,1,0}, //1-front-upper-left
		{1,1,0}, //2-front-upper-right
		{1,0,0}, //3-front-bottom-right
		{0,0,1}, //4-rear-bottom-left
		{0,1,1}, //5-rear-upper-left
		{1,1,1}, //6-rear-upper-right
		{1,0,1}  //7-rear-bottom-right
	};

	glBegin(GL_TRIANGLES); //front face - triangle 1
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[2]);
	glEnd();
	glBegin(GL_TRIANGLES); //front face - triangle 2
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[0]);
	glEnd();	
	glBegin(GL_TRIANGLES); //top face - triangle 3
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); //top face - triangle 4
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[1]);
	glEnd();
	glBegin(GL_TRIANGLES); //left face - triangle 5
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //left face - triangle 6
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[0]);
	glEnd();
	glBegin(GL_TRIANGLES); //right face - triangle 7
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[7]);
		glVertex3fv(vertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); //right face - triangle 8
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[3]);
	glEnd();
	glBegin(GL_TRIANGLES); //rear face - triangle 9
		glVertex3fv(vertices[7]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //rear face - triangle 10
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); //bottom face - triangle 11
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); //bottom face - triangle 12
		glVertex3fv(vertices[7]);
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[0]);
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
