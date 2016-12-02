#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14159265
using namespace std;






//initialize lighting
void init(void)
{
	GLfloat ambient[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { 0.0, 4, 2, 0.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };

	glClearColor(.05, 0.05, 0.05, 0.0);
	

	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);

	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.;
float _ang_tri = 0.0;
//Draws the 3D scene
void drawScene() 
{
	GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
	GLfloat mat_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
	GLfloat mat_ambient_color[] = { .23, .33, .23, 1.0 };
	GLfloat mat_diffuse[] = { .23, 1, .23, 1.0 };
	GLfloat mat_specular[] = { 0.7, 0.7, 0.7, 1.0 };
	GLfloat no_shininess[] = { 0.0 };
	GLfloat low_shininess[] = { 100.0 };
	GLfloat high_shininess[] = { 100.0 };
	GLfloat mat_emission[] = { 0.1, .8, 0.1, 1.0 };

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);		//Switch to the drawing perspective
	glLoadIdentity();				//Reset the drawing perspective
									//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -10.0);	//Move forward 5 units
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();


	glPushMatrix();
	glRotatef(_angle, 0, 1, 0);
	glEnable(GL_LIGHTING);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_color);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, low_shininess);
	glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	glPushMatrix();
	
	

	

	glRotatef(45,1,0,0);
	glRotatef(45, 0, 1, 0);
	glutSolidCube(1.5);
	
	
	glPopMatrix();
	
	//glDisable(GL_LIGHTING);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(1, 0, 0);
	glRotatef(_angle, 0, 1, 0);

	glPushMatrix();
	
	//glRotatef(40, 1,0, 0);
	glutWireTorus(.5, 2, 40, 40);
	glPopMatrix();

	glPopMatrix();
	glutSwapBuffers();
}

void update(int value) {

		_angle += 2.0f;
		if (_angle > 360) {
			_angle -= 360;
		}
		_ang_tri += 2.0f;
		if (_ang_tri > 360) {
			_ang_tri -= 360;
		}
	
	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(30, update, 0);
}
int main(int argc, char** argv)
{
	cout << "Press s to start and s to off\n 1, 2 , 3,4,5 range of speed" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	//Create the window
	glutCreateWindow("Transformations");
	//initRendering();
	init();
	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
	
	glutTimerFunc(30, update, 0); //Add a timer
									 //glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}