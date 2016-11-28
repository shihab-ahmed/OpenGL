#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14159265
using namespace std;

bool LeftFan, RightFan, LeftFanOff, RightFanOff, Increase, Decrease;
int  Speed = 40;
bool isStart;
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
float leftangle = -30;
float rightangle= 30;
bool angleMax = false;
float headangle = -20;
bool headmax = false;
//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);		//Switch to the drawing perspective
	glLoadIdentity();				//Reset the drawing perspective
									//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -10.0);	//Move forward 5 units
	GLUquadricObj *quadratic;
	quadratic = gluNewQuadric();

	glColor3f(.8,.8,.8);
	glPushMatrix();
	glRotatef(_angle,0,0,1);

		glPushMatrix();
			//glRotatef(90,1,0,0);
			glPushMatrix();
				glScalef(.7, .7, .3);
				glutSolidSphere(1,20,20);
			glPopMatrix();
			glColor3f(.6, .6, .6);
			glPushMatrix();
				glScalef(.7,5,.1);
				glutSolidCube(1);
			glPopMatrix();

			glPushMatrix();
			glRotatef(90, 0, 0, 1);
				glScalef(.7, 5, .1);
				glutSolidCube(1);
			glPopMatrix();
		glPopMatrix();

	glPopMatrix();


	glutSwapBuffers();
}

void update(int value) {
	

	if (isStart)
	{
		_angle += 2.0f;
		if (_angle > 360) {
			_angle -= 360;
		}
		_ang_tri += 2.0f;
		if (_ang_tri > 360) {
			_ang_tri -= 360;
		}
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(Speed, update, 0);
}
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		Speed = 40;
		break;
	case '2':
		Speed = 30;
		break;
	case '3':
		Speed = 20;
		break;
	case '4':
		Speed = 10;
		break;
	case '5':
		Speed = 5;
		break;
	case 's':
		isStart = !isStart;
	break;
	case 'd':
	break;
	case 'x':
	break;
	default:
	cout << "Pressed key : " << (char)key
	<< " at position : ("
	<< x << "," << y << ")" << endl;
	break;
	}
}
int main(int argc, char** argv)
{
	cout << "Press s to start and s to off\n 1, 2 , 3,4,5 range of speed" << endl;
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);
	glutKeyboardFunc(keyboard);
	glutTimerFunc(Speed, update, 0); //Add a timer
					 //glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}