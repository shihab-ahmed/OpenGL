#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
using namespace std;
#define PI 3.14159265

bool LeftFan, RightFan, LeftFanOff, RightFanOff, Increase, Decrease;
float  Speed = -5.0f;
//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}

//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle = 0.0;
float _cameraAngle = 0.;
float _ang_tri = 0.0;

//Draws the 3D scene
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);		//Switch to the drawing perspective
	glLoadIdentity();				//Reset the drawing perspective
									//glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0);	//Move forward 5 units

	glColor3f(.7,.7,.7);
	glPushMatrix();
	glRotatef(30, 0, 1, 0);


		glColor3f(.3, 0,0);
		glPushMatrix();
			glTranslatef(Speed,0,0);
			glPushMatrix();
				glScalef(2, 1, .6);
				//body
				glTranslatef(0, .5, 0);
					glutSolidCube(1);
					//body end
			glPopMatrix();

			//wheel begin
			glColor3f(.2, .2, .2);
			glPushMatrix();
				glScalef(.3, .3, .3);
				glTranslatef(1.7, 0, 1);
				glRotatef(_angle, 0, 0, 1);
					glutWireTorus(.3, .7, 25, 25);
			glPopMatrix();

			glPushMatrix();
				glScalef(.3, .3, .3);
				glTranslatef(-1.7, 0, 1);
				glRotatef(_angle, 0, 0, 1);
					glutWireTorus(.3, .7, 25, 25);
			glPopMatrix();

			glPushMatrix();
			glScalef(.3, .3, .3);
			glTranslatef(1.7, 0, -1);
			glRotatef(_angle, 0, 0, 1);
			glutWireTorus(.3, .7, 25, 25);
			glPopMatrix();

			glPushMatrix();
			glScalef(.3, .3, .3);
			glTranslatef(-1.7, 0, -1);
			glRotatef(_angle, 0, 0, 1);
			glutWireTorus(.3, .7, 25, 25);
			glPopMatrix();
			//wheeel end
		glPopMatrix();
	glPopMatrix();
	//glPushMatrix();
	//glutWireTorus(.3, .7, 25, 25);
	//glPopMatrix();

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
	Speed+=.1f;
	if (Speed > 11)
	{
		Speed = -5.0f;
	}
	glutPostRedisplay(); //Tell GLUT that the display has changed

						 //Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(50, update, 0);
}
/*void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		// Backspace
	case 48:
		if (LeftFan)
		{
			LeftFan = false;
			LeftFanOff = false;
			cout << "Left Fan off:" << endl;
		 }
		if (RightFan)
		{
			RightFan = false;
			RightFanOff = false;
			cout << "Right Fan off:" << endl;
		}
		break;

		// Enter
	case 49:
		cout << "Left fan selected.Press 0,S(off,On)" << endl;
		LeftFan = true;
		RightFan = false;
		break;

		// Escape
	case 50:
		cout << "Right fan selected.Press 0,S(off,On)" << endl;
		LeftFan = false;
		RightFan = true;
		break;

		// Delete
	case 43:
		Speed-=5;
		if (Speed <= 1)
		{
			Speed = 1;
			cout << "Max speed reached" << endl;
		}
		cout << "speed increased" << endl;
		break;
	case 45:
		Speed+=5;
		if (Speed >= 45)
		{
			Speed = 45;
			cout << "min speed reached" << endl;
		}
		cout << "speed deccreased" << endl;
		break;

	case 's':
		if (LeftFan)
		{
			LeftFan = false;
			LeftFanOff = true;
			cout << "Left Fan On:" << endl;
		}
		if (RightFan)
		{
			RightFan = false;
			RightFanOff = true;
			cout << "Right Fan On:" << endl;
		}
		break;
	case 'd':

		break;
	case 'x':

		break;
	default:
		/*cout << "Pressed key : " << (char)key
			<< " at position : ("
			<< x << "," << y << ")" << endl;
		break;
}

}*/
int main(int argc, char** argv)
{


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);

	//Create the window
	glutCreateWindow("Transformations");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(Speed, update, 0); //Add a timer
	//glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}








