#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Set fill color (R,G,B):
	glColor3f(1.0,1.0,1.0);
	glOrtho(-4.0,12.0,-4.0,12.0,-4.0,1.0);
	//Just draw the triangles edges:
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); 

	GLfloat coreVertices[19][3] = //Vector of vectors with coreVertices positions
	{
	/*	
	   *				  *---*                  *
	   |			  ´    \ /    `              |
	   *		   *´ ------*-------`*           *
	   |	  45'/    '   .   .   '    \45'      |
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

		//core vertexes
		{3,2,-1},				//0
		{3,2.5,-1}, 				//1
		{4.5,2.5,-1},			//2
		{3,3,-1}, 				//3
		{4.5,3,-1}, 				//4
		{3.292893219,3.5,-1},    //5    ----> 1 - sen 45' = 0.292893219
		{4.5,3.5,-1},			//6
		{4,4,-1},  				//7
		{5,4,-1},				//8
		{5.70710678118,3.5,-1},	//9    ----> sen 45' = 0.70710678118
		{6,3,-1},				//10
		{6,2.5,-1},				//11
		{6,2,-1},				//12
		{4.5,2,-1},				//13
		{5.70710678118,1.5,-1},	//14
		{4.5,1.5,-1},			//15
		{5,1,-1},				//16
		{4,1,-1},				//17
		{3.292893219,1.5,-1}		//18
	};

		GLfloat wingVertices[10][3] = //Vector of vectors with wingVertices positions
	{
	/*	
	   *9				  *---*                  *
	   |			  ´    \ /    `              |
	   *8		   *´ ------*-------`*           *
	   |		 /    '   .   .   '    \         |
	   *4-------*5 -------- *  -------  *--------*
	   |	/	|      \    |     /     |        |
	   *3-- ----*6  ----    *  -------  *        *
	   |    \   |      /    |     \     |        |
	   *2-------*7 -------- * --------- *--------*
	   |         \     .  ´    `  .    /         |
	   *1		   * ------ * ------ *           *
	   |             `     /  \    ´             |
	   *0               ` *----* ´               *
	                     
	*/

		//wing vertexes
		{0,-2,-1},				//0
		{0,1,-1}, 				//1
		{0,2,-1}, 				//2
		{0,2.5,-1}, 				//3
		{0,3,-1},			    //4
		{3,3,-1},				//5
		{3,2.5,-1},  			//6
		{3,2,-1},				//7
		{0,4,-1},				//8
		{0,7,-1}					//9
	};

			GLfloat rightWingVertices[10][3] = //Vector of vectors with wingVertices positions
	{
	/*	
	   * 				  *---*                  *9
	   |			  ´    \ /    `              |
	   * 		   *´ ------*-------`*           *8
	   |		 /    '   .   .   '    \         |
	   * -------*  -------- *  -------  *5-------*4
	   |	 	|      \    |     /     |    \   |
	   *		*   ----    *  -------  *6 ------*3
	   |        |      /    |     \     |    /   |
	   * -------*  -------- * --------- *7-------*2
	   |         \     .  ´    `  .    /         |
	   * 		   * ------ * ------ *           *1
	   |             `     /  \    ´             |
	   *                ` *----* ´               *0
	                     
	*/

		//right wing vertexes
		{9,-2,-1},				//0
		{9,1,-1}, 				//1
		{9,2,-1}, 				//2
		{9,2.5,-1}, 				//3
		{9,3,-1},			    //4
		{6,3,-1},				//5
		{6,2.5,-1},  			//6
		{6,2,-1},				//7
		{9,4,-1},				//8
		{9,7,-1}					//9
	};

	//core
	glBegin(GL_TRIANGLES); //triangle 1
		glVertex3fv(coreVertices[0]);
		glVertex3fv(coreVertices[1]);
		glVertex3fv(coreVertices[2]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 2
		glVertex3fv(coreVertices[1]);
		glVertex3fv(coreVertices[3]);
		glVertex3fv(coreVertices[2]);
	glEnd();	
	glBegin(GL_TRIANGLES); //triangle 3
		glVertex3fv(coreVertices[2]);
		glVertex3fv(coreVertices[3]);
		glVertex3fv(coreVertices[4]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 4
		glVertex3fv(coreVertices[3]);
		glVertex3fv(coreVertices[4]);
		glVertex3fv(coreVertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 5
		glVertex3fv(coreVertices[4]);
		glVertex3fv(coreVertices[5]);
		glVertex3fv(coreVertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 6
		glVertex3fv(coreVertices[5]);
		glVertex3fv(coreVertices[6]);
		glVertex3fv(coreVertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 7
		glVertex3fv(coreVertices[6]);
		glVertex3fv(coreVertices[7]);
		glVertex3fv(coreVertices[8]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 8
		glVertex3fv(coreVertices[6]);
		glVertex3fv(coreVertices[8]);
		glVertex3fv(coreVertices[9]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 9
		glVertex3fv(coreVertices[4]);
		glVertex3fv(coreVertices[6]);
		glVertex3fv(coreVertices[9]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 10
		glVertex3fv(coreVertices[4]);
		glVertex3fv(coreVertices[9]);
		glVertex3fv(coreVertices[10]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 11
		glVertex3fv(coreVertices[2]);
		glVertex3fv(coreVertices[4]);
		glVertex3fv(coreVertices[10]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 12
		glVertex3fv(coreVertices[2]);
		glVertex3fv(coreVertices[10]);
		glVertex3fv(coreVertices[11]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 13
		glVertex3fv(coreVertices[2]);
		glVertex3fv(coreVertices[11]);
		glVertex3fv(coreVertices[12]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 14
		glVertex3fv(coreVertices[2]);
		glVertex3fv(coreVertices[12]);
		glVertex3fv(coreVertices[13]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 15
		glVertex3fv(coreVertices[12]);
		glVertex3fv(coreVertices[14]);
		glVertex3fv(coreVertices[13]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 16
		glVertex3fv(coreVertices[13]);
		glVertex3fv(coreVertices[14]);
		glVertex3fv(coreVertices[15]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 17
		glVertex3fv(coreVertices[14]);
		glVertex3fv(coreVertices[16]);
		glVertex3fv(coreVertices[15]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 18
		glVertex3fv(coreVertices[15]);
		glVertex3fv(coreVertices[16]);
		glVertex3fv(coreVertices[17]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 19
		glVertex3fv(coreVertices[15]);
		glVertex3fv(coreVertices[17]);
		glVertex3fv(coreVertices[18]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 20
		glVertex3fv(coreVertices[13]);
		glVertex3fv(coreVertices[15]);
		glVertex3fv(coreVertices[18]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 21
		glVertex3fv(coreVertices[0]);
		glVertex3fv(coreVertices[13]);
		glVertex3fv(coreVertices[18]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 22
		glVertex3fv(coreVertices[0]);
		glVertex3fv(coreVertices[2]);
		glVertex3fv(coreVertices[13]);
	glEnd();

	//leftWing
	glBegin(GL_LINE_STRIP); //wing disc
		glVertex3fv(wingVertices[0]);
		glVertex3fv(wingVertices[1]);
		glVertex3fv(wingVertices[2]);
		glVertex3fv(wingVertices[3]);
		glVertex3fv(wingVertices[4]);
		glVertex3fv(wingVertices[8]);
		glVertex3fv(wingVertices[9]);
	glEnd();

	//wing arm
	glBegin(GL_TRIANGLES); //triangle 1
		glVertex3fv(wingVertices[2]);
		glVertex3fv(wingVertices[3]);
		glVertex3fv(wingVertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 2
		glVertex3fv(wingVertices[3]);
		glVertex3fv(wingVertices[4]);
		glVertex3fv(wingVertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 3
		glVertex3fv(wingVertices[3]);
		glVertex3fv(wingVertices[5]);
		glVertex3fv(wingVertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 4
		glVertex3fv(wingVertices[3]);
		glVertex3fv(wingVertices[6]);
		glVertex3fv(wingVertices[7]);
	glEnd();

	//rightWing
	glBegin(GL_LINE_STRIP); //wing disc
		glVertex3fv(rightWingVertices[0]);
		glVertex3fv(rightWingVertices[1]);
		glVertex3fv(rightWingVertices[2]);
		glVertex3fv(rightWingVertices[3]);
		glVertex3fv(rightWingVertices[4]);
		glVertex3fv(rightWingVertices[8]);
		glVertex3fv(rightWingVertices[9]);
	glEnd();

	//wing arm
	glBegin(GL_TRIANGLES); //triangle 1
		glVertex3fv(rightWingVertices[2]);
		glVertex3fv(rightWingVertices[3]);
		glVertex3fv(rightWingVertices[7]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 2
		glVertex3fv(rightWingVertices[3]);
		glVertex3fv(rightWingVertices[4]);
		glVertex3fv(rightWingVertices[5]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 3
		glVertex3fv(rightWingVertices[3]);
		glVertex3fv(rightWingVertices[5]);
		glVertex3fv(rightWingVertices[6]);
	glEnd();
	glBegin(GL_TRIANGLES); //triangle 4
		glVertex3fv(rightWingVertices[3]);
		glVertex3fv(rightWingVertices[6]);
		glVertex3fv(rightWingVertices[7]);
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
	glutCreateWindow("OpenGL Tie Fighter");
	// Register display callback
	glutDisplayFunc(display);
	// Register keyboard callback
	glutKeyboardFunc(keyboard);
	// Enter main event loop
	glutMainLoop();

	return (EXIT_SUCCESS);
}
