#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14159265


Matrix Wing, Wing2, Wing3, Wing4, Wing5, Wing6, Wing7, Wing8;
bool LeftFan, RightFan, LeftFanOff, RightFanOff, Increase, Decrease;
int  Speed = 35;
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

	glColor3f(.5, .5, .5);
	glPushMatrix();
	glRotatef(-60, 1, 0, 0);
	glRotatef(-30, 0, 1, 0);
		//Orbits
		glBegin(GL_LINES);
		for (int i = 0; i<200; i++)
		{
			float pi = 3.1416;
			float A = (i * 2 * pi) / 100;
			float r = 0.70;
			float x = r * cos(A);
			float y = r * sin(A);
			glVertex2f(x, y);
		}
		glEnd();
	
		glBegin(GL_LINES);
		for (int i = 0; i<200; i++)
		{
			float pi = 3.1416;
			float A = (i * 2 * pi) / 100;
			float r = 1.2;
			float x = r * cos(A);
			float y = r * sin(A);
			glVertex2f(x, y);
		}
		glEnd();

		glBegin(GL_LINES);
		for (int i = 0; i<200; i++)
		{
			float pi = 3.1416;
			float A = (i * 2 * pi) / 100;
			float r = 1.70;
			float x = r * cos(A);
			float y = r * sin(A);
			glVertex2f(x, y);
		}
		glEnd();

		glBegin(GL_LINES);
		for (int i = 0; i<200; i++)
		{
			float pi = 3.1416;
			float A = (i * 2 * pi) / 100;
			float r = 2.40;
			float x = r * cos(A);
			float y = r * sin(A);
			glVertex2f(x, y);
		}
		glEnd();
		//orbits end

		//Sun
		glColor3f(1,1,0);
		glPushMatrix();
			glPushMatrix();
			glRotatef(_angle, 0, 0, 1);
			glutWireSphere(.5, 20, 20);
			glPopMatrix();		
		glPopMatrix();
		//Sun end

		//Planet
		glColor3f(1, 0, 0);
		glPushMatrix();
		glRotatef(_angle-20, 0, 0, 1);
		glTranslatef(.7, 0, 0);
			glPushMatrix();
			glRotatef(_angle, 0, 0, 1);
				glutWireSphere(.1, 15, 15);
			glPopMatrix();
		glPopMatrix();

		glColor3f(0, 1, 0);
		glPushMatrix();
		glRotatef(_angle-120, 0, 0, 1);
		glTranslatef(1.2, 0, 0);
			glPushMatrix();
			glRotatef(_angle, 0, 0, 1);
			glutWireSphere(.15, 15, 15);
			glPopMatrix();	
		glPopMatrix();

		glColor3f(0, 0, 1);
		glPushMatrix();
		glRotatef(_angle-70, 0, 0, 1);
		glTranslatef(1.70, 0, 0);
			glPushMatrix();
			glRotatef(_angle, 0, 0, 1);
			glutWireSphere(.2, 15, 15);
			glPopMatrix();		
		glPopMatrix();

		glColor3f(0, 1, 1);
		glPushMatrix();
		glRotatef(_angle-200, 0, 0, 1);
		glTranslatef(2.40, 0, 0);
			glPushMatrix();
			glRotatef(_angle, 0, 0, 1);
			glutWireSphere(.25, 15, 15);
			glPopMatrix();		
		glPopMatrix();
		//planet end
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
	glutTimerFunc(Speed, update, 0);
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

	Wing = DrawQuad(0,0,.5,-.5,3.5,-.40,3.49,0);
	Wing2 = Roation(Wing, 90);
	Wing3 = Roation(Wing2, 90);
	Wing4 = Roation(Wing3, 90);

	Wing5 = DrawQuad(0, 0, 3.5, 0, 3.5, .40, .5,.5);
	Wing6 = Roation(Wing5, 90);
	Wing7 = Roation(Wing6, 90);
	Wing8 = Roation(Wing7, 90);

	cout << "Press 1 to select left fan.2 to select right fan:"<<endl;
	cout << "Press + or - to (increase,decrease) Fan speed:" << endl;
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








