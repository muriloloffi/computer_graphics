#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Set fill color (R,G,B):
	glColor3f(1.0,1.0,1.0);
	glOrtho(-10.0,10.0,-10.0,10.0,-10.0,1.0);
	//Just draw the triangles edges:
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 

	GLfloat vertices[19][3] = //Vector of vectors with vertices positions
	{
	/*	
	   *				  *---*                  *
	   |			  ´    \ /    `              |
	   *		   *´ ------*-------`*           *
	   |		 /    '   .   .   '    \         |
	   *--------*3 -------- *  -------  *--------*
	   |		|  2   \  3 |     /     |        |
	   *        *1  ----   2*  -------  *        *
	   |        |  1   /    |     \     |        |
	   *--------*0 -------- * --------- *--------*
	   |         \     .  ´    `  .    /         |
	   *		   * ------ * ------ *           *
	   |             `     /  \    ´             |
	   *                ` *----* ´               *
	                     
	*/

		//core
		{3,2,0},		//0
		{3,2.5,0}, 		//1
		{4.5,2.5,0},	//2
		{3,3,0}, 		//3
		{4.5,3,0}, 		//4
		{3.5,3.5,0},    //5
		{4.5,3.5,0},	//6
		{4,4,0},  		//7
		{5,4,0},		//8
		{5.5,3.5,0},	//9
		{6,3,0},		//10
		{6,2.5,0},				//11
		{6,2,0},				//12
		{4.5,2,0},				//13
		{5.5,1.5,0},			//14
		{4.5,1.5,0},			//15
		{5,1,0},				//16
		{4,1,0},				//17
		{3.5,1.5,0}				//18
};

	glBegin(GL_TRIANGLES); //triangle 1
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[2]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 2
		glVertex3fv(vertices[1]);
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[2]);
	glEnd();	
	glBegin(GL_TRIANGLES); //triangle 3
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[4]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 4
		glVertex3fv(vertices[3]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 5
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 6
		glVertex3fv(vertices[5]);
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 7
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[7]);
		glVertex3fv(vertices[8]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 8
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[8]);
		glVertex3fv(vertices[9]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 9
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[6]);
		glVertex3fv(vertices[9]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 10
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[9]);
		glVertex3fv(vertices[10]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 11
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[4]);
		glVertex3fv(vertices[10]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 12
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[10]);
		glVertex3fv(vertices[11]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 13
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[11]);
		glVertex3fv(vertices[12]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 14
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[12]);
		glVertex3fv(vertices[13]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 15
		glVertex3fv(vertices[12]);
		glVertex3fv(vertices[14]);
		glVertex3fv(vertices[13]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 16
		glVertex3fv(vertices[13]);
		glVertex3fv(vertices[14]);
		glVertex3fv(vertices[15]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 17
		glVertex3fv(vertices[14]);
		glVertex3fv(vertices[16]);
		glVertex3fv(vertices[15]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 18
		glVertex3fv(vertices[15]);
		glVertex3fv(vertices[16]);
		glVertex3fv(vertices[17]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 19
		glVertex3fv(vertices[15]);
		glVertex3fv(vertices[17]);
		glVertex3fv(vertices[18]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 20
		glVertex3fv(vertices[13]);
		glVertex3fv(vertices[15]);
		glVertex3fv(vertices[18]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 21
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[13]);
		glVertex3fv(vertices[18]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 22
		glVertex3fv(vertices[0]);
		glVertex3fv(vertices[2]);
		glVertex3fv(vertices[13]);
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
