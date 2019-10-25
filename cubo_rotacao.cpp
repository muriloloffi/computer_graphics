#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);
	glOrtho(-2.0,2.0,-2.0,2.0,-2.0,1.0);
	glRotatef(30,0.5,0.5,0.5);

	GLfloat vertices[8][3] = 
	{
		{0,0,0}, //0-front-bottom-left
		{0,1,0}, //1-front-upper-left
		{1,1,0}, //2-front-upper-right
		{1,0,0}, //3-front-bottom-right
		{0,0,1}, //4-back-bottom-left
		{0,1,1}, //5-back-upper-left
		{1,1,1}, //6-back-upper-right
		{1,0,1}  //7-back-bottom-right
	};
	glBegin(GL_TRIANGLES); //face frente - triangulo 1
		//glColor3f(1.0,0,0);
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[2]);
	glEnd();
	glBegin(GL_TRIANGLES); //face frente - triangulo 2
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[0]);
	glEnd();	
	glBegin(GL_TRIANGLES); //face topo - triangulo 3
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); // face topo - triangulo 4
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[1]);
	glEnd();
	glBegin(GL_TRIANGLES); // face esquerda - triangulo 5
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); // face esquerda - triangulo 6
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[0]);
	glEnd();
	glBegin(GL_TRIANGLES); // face direita - triangulo 7
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[7]);
		glVertex3fv(vertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); // face direita - triangulo 8
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[3]);
	glEnd();
	glBegin(GL_TRIANGLES); // face trazeira - triangulo 9
		glVertex3fv(vertices[7]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); // face trazeira - triangulo 10
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); // face base - triangulo 11
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); // face base - triangulo 12
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
	glutCreateWindow("OpenGL example");
	// Register display callback
	glutDisplayFunc(display);
	// Register keyboard callback
	glutKeyboardFunc(keyboard);
	// Enter main event loop
	glutMainLoop();

	return (EXIT_SUCCESS);
}
