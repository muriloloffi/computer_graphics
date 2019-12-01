#include <cstdlib>
#include <GL/glut.h>
#include <GL/glut.h>


void display()
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	//Set fill color (R,G,B):
	glColor3f(0.5,0.5,0.5);
	glMatrixMode(GL_PROJECTION);
		glLoadIdentity(); // Load the Identity Matrix to reset our drawing locations
		// gluPerspective(60.0,1.0,0.0,21.5);
		glFrustum(-1.0f, 1.0f, -1.0f, 1.0f, 0.0f, 20.0f);
	glMatrixMode(GL_MODELVIEW);
	// glViewport(0, 0, 700, 700);

	GLUquadricObj *leftWingArm, *leftWing, *rightWingArm, *rightWing, *fighterCore;

	leftWingArm = gluNewQuadric();
	leftWing = gluNewQuadric();
	rightWingArm = gluNewQuadric();
	rightWing = gluNewQuadric();
	fighterCore = gluNewQuadric();


	glRotatef(27.0f,1.0f,1.0f,0.0f);
	glScalef(0.5,0.5,0.5);

	glPushMatrix();
		glTranslatef    (0.95, 0.0, 0.0);
		glRotatef	(90.0f, 0.0f, 1.0f, 0.0f);
		glRotatef 	(-30.0f, 0.0f, 0.0f, 1.0f); //Rotate disk edge to match original model
		gluDisk(leftWing,0.0f,1.0f,6.0f,16); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef    (0.45, 0.0, 0.0);
		glRotatef	(90.0f, 0.0f, 1.0f, 0.0f);
		gluCylinder(leftWingArm,0.1f,0.1f,0.5f,32,1); //Cylinder for 'wing' arms
	glPopMatrix();

	glPushMatrix ();
       glTranslatef    (0, 0.0, 0.0);
	   glRotatef	(90.0f,1.0f,0.0f,0.0f);
       gluSphere 	(fighterCore,0.5, 32, 32);
    glPopMatrix ();

	glPushMatrix();
		glTranslatef    (-0.45, 0.0, 0.0);
		glRotatef	(-90.0f, 0.0f, 1.0f, 0.0f);
		gluCylinder(rightWingArm,0.1f,0.1f,0.5f,32,1); 
	glPopMatrix();

	glPushMatrix();
		glTranslatef    (-0.95, 0.0, 0.0);
		glRotatef	(-90.0f, 0.0f, 1.0f, 0.0f);
		glRotatef 	(-30.0f, 0.0f, 0.0f, 1.0f);
		gluDisk(rightWing,0.0f,1.0f,6.0f,16); 
	glPopMatrix();	


	//Draw a floor
	glPushMatrix();
	for(float i = -50; i <= 50; i += 0.5)
	{
		glBegin(GL_POLYGON);
			glColor3ub(150, 190, 150);						
			glVertex3f(-50, -1.8, i);					
			glVertex3f(50, -1.8, i);
			glVertex3f(i, -1.8,-50);							
			glVertex3f(i, -1.8, 50);
		glEnd();
	}
	glPopMatrix();

	//Draw some stars
	glPointSize(2);
	glPushMatrix();
		glBegin(GL_POINTS);
			glColor3f(1.0,1.0,1.0);
			glVertex3f(0.0,-1.0,0.1);
			glVertex3f(1.5,-0.9,0.4);
			glVertex3f(-0.5,2.0,0.3);
			glVertex3f(-1.0,1.8,0.2);
			glVertex3f(1.0,2.0,0.6);
			glVertex3f(-0.3,2.0,0.7);
			glVertex3f(-1.4,1.7,1.5);
			glVertex3f(-1.6,1.5,0.9);
			glVertex3f(-0.9,1.6,0.9);
			glVertex3f(-1.8,1.33,0.9);
		glEnd();
	glPopMatrix();

	glFlush();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 0.0f, 0.0f, 0.0f }; 
 
const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f }; 

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

	glEnable(GL_LIGHT0);
	    glEnable(GL_NORMALIZE);
	    glEnable(GL_COLOR_MATERIAL);
	    glEnable(GL_LIGHTING); 
	 
	    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
	    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
	    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	    glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
	 
	    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
	    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
	    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
	    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);
	// Register keyboard callback
	glutKeyboardFunc(keyboard);
	// Enter main event loop
	glutMainLoop();

	return (EXIT_SUCCESS);
}
