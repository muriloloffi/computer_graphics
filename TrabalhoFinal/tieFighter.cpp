#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Set fill color (R,G,B):
	glColor3f(1.0,1.0,1.0);
	glOrtho(-8.0,16.0,-8.0,16.0,-10.0,8.0);
	glFrustum(-4.0, 4.0, -4.0, 4.0, 1.5, 20.0);
 

	GLUquadricObj *leftWingArm, *leftWing, *rightWingArm, *rightWing;

	leftWingArm = gluNewQuadric();
	leftWing = gluNewQuadric();
	rightWingArm = gluNewQuadric();
	rightWing = gluNewQuadric();

	glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations

	glRotatef(45.0f,1.0f,1.0f,0.0f);

	glPushMatrix();
		glTranslatef    (0.95, 0.0, 0.0);
		glRotatef	(90.0f, 0.0f, 1.0f, 0.0f);
		// here *render* your cylinder (create and delete it in the other place. Not while rendering)
		gluDisk(leftWing,0.0f,1.0f,16.0f,16); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef    (0.45, 0.0, 0.0);
		glRotatef	(90.0f, 0.0f, 1.0f, 0.0f);
		// here *render* your cylinder (create and delete it in the other place. Not while rendering)
		gluCylinder(leftWingArm,0.1f,0.1f,0.5f,16,7); 
	glPopMatrix();

	glPushMatrix ();
       glTranslatef    (0, 0.0, 0.0);
	   glRotatef	(90.0f,1.0f,0.0f,0.0f);
       glutSolidSphere 	(0.5, 20, 20);
    glPopMatrix ();

	glPushMatrix();
		glTranslatef    (-0.45, 0.0, 0.0);
		glRotatef	(-90.0f, 0.0f, 1.0f, 0.0f);
		// here *render* your cylinder (create and delete it in the other place. Not while rendering)
		gluCylinder(rightWingArm,0.1f,0.1f,0.5f,16,7); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef    (-0.95, 0.0, 0.0);
		glRotatef	(-90.0f, 0.0f, 1.0f, 0.0f);
		// here *render* your cylinder (create and delete it in the other place. Not while rendering)
		gluDisk(rightWing,0.0f,1.0f,16.0f,16); 
	glPopMatrix();
	

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
	// Set window size
	glutInitWindowSize(700, 700);
	// Create a window
	glutCreateWindow("OpenGL Tie Fighter");
	// Just draw the triangles edges:
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	// Register display callback
	glutDisplayFunc(display);
	// Register keyboard callback
	glutKeyboardFunc(keyboard);
	// Enter main event loop
	glutMainLoop();

	return (EXIT_SUCCESS);
}
