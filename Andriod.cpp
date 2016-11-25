#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#define PI 3.14159265


bool LeftFan, RightFan, LeftFanOff, RightFanOff, Increase, Decrease;
int  Speed = 35;
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

	//head
	

	//full body start

	glPushMatrix();
	
	glScalef(.5,.5,.5);
	glTranslated(0, 5, 0);
		glPushMatrix();
		glRotatef(25, 0, 1, 0);

		//........................................................................
		glPushMatrix();
		glTranslatef(0, -.4, 0);
			glPushMatrix();
				glRotatef(rightangle, 1, 0, 0);
				//left hand
				glColor3f(.5, .85, .2);
					glPushMatrix();
						glScalef(.4,.4,.4);
						glTranslatef(-4.5, 0, 0);
						//Capsul start
						glPushMatrix();
							glTranslatef(0, 0, 0);
							glRotatef(90, 1, 0, 0);
							glutSolidSphere(1, 20, 20);
						glPopMatrix();

						glPushMatrix();
							glRotatef(90, 1, 0, 0);
							gluCylinder(quadratic, 1, 1, 3.5, 32, 32);
							glScalef(1, 1, 4);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0, -3.4, 0);
							glRotatef(90, 1, 0, 0);
							glutSolidSphere(1, 20, 20);
						glPopMatrix();
					//Capsul end
					glPopMatrix();
			glPopMatrix();
			//left hand end

			glPushMatrix();
				glRotatef(leftangle, 1, 0, 0);
					//right hand start
					glPushMatrix();
						glScalef(.4, .4, .4);
						glTranslatef(4.5, 0, 0);
						//Capsul start
						glPushMatrix();
							glTranslatef(0, 0, 0);
							glRotatef(90, 1, 0, 0);
							glutSolidSphere(1, 20, 20);
						glPopMatrix();

						glPushMatrix();
							glRotatef(90, 1, 0, 0);
							gluCylinder(quadratic, 1, 1, 3.5, 32, 32);
							glScalef(1, 1, 4);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0, -3.4, 0);
							glRotatef(90, 1, 0, 0);
							glutSolidSphere(1, 20, 20);
						glPopMatrix();
						//Capsul end
					glPopMatrix();
			glPopMatrix();
		glPopMatrix();
		//right hand end
		//........................................................................

		//........................................................................
		//left leg
		glPushMatrix();
			glTranslatef(0,-2.5,0);

				glPushMatrix();
					//glRotatef(_angle, 1, 0, 0);
					glScalef(.4, .4, .4);
					glTranslatef(-1.5, 0, 0);
					glRotatef(leftangle,1,0,0);
					//Capsul start
					glPushMatrix();
						glTranslatef(0, 0, 0);
						glRotatef(90, 1, 0, 0);
						glutSolidSphere(1, 20, 20);
					glPopMatrix();

					glPushMatrix();
						glRotatef(90, 1, 0, 0);
						gluCylinder(quadratic, 1, 1, 2.5, 32, 32);
						glScalef(1, 1, 4);
					glPopMatrix();

					glPushMatrix();
						glTranslatef(0, -2.4, 0);
						glRotatef(90, 1, 0, 0);
						glutSolidSphere(1, 20, 20);
					glPopMatrix();
					//Capsul end
				glPopMatrix();
					//left leg end

					//right leg start
					glPushMatrix();
						//glRotatef(_angle, 1, 0, 0);
						glScalef(.4, .4, .4);
						glTranslatef(1.5, 0, 0);
						glRotatef(rightangle, 1, 0, 0);
						//Capsul start
						glPushMatrix();
							glTranslatef(0, 0, 0);
							glRotatef(90, 1, 0, 0);
							glutSolidSphere(1, 20, 20);
						glPopMatrix();

						glPushMatrix();
							glRotatef(90, 1, 0, 0);
							gluCylinder(quadratic, 1, 1, 2.5, 32, 32);
							glScalef(1, 1, 4);
						glPopMatrix();

						glPushMatrix();
							glTranslatef(0, -2.4, 0);
							glRotatef(90, 1, 0, 0);
							glutSolidSphere(1, 20, 20);
						glPopMatrix();
						//Capsul end
				glPopMatrix();
		glPopMatrix();
		//right leg end

		//...................................................................................

		glColor3f(.4, .8, .2);
	
		//...................................................................................
		//head start
		glPushMatrix();
		glTranslatef(0, -.1, 0);
		glutSolidSphere(1.2, 20, 20);
		glPopMatrix();
		//head end

		//body
		glPushMatrix();
		glRotatef(90, 1, 0, 0);
		gluCylinder(quadratic, 1.2, 1.2, 2, 32, 32);	
		glPopMatrix();
		//body end

		//lowerbody
		glPushMatrix();
		glTranslatef(0, -2, 0);
		glRotatef(90, 1, 0, 0);
		glutSolidTorus(.6, .6, 20, 20);
		glPopMatrix();
		//lowerbody end
		//full body end

		//eye
		glPushMatrix();
		glTranslatef(0,.5,.9);
			//left eye
			glPushMatrix();
				glTranslatef(-.5, 0, 0);
				glColor3f(0, 0, 0);
				glutSolidSphere(.1,10,10);
			glPopMatrix();
			//left end

			//right eye
			glPushMatrix();
				glTranslatef(.5, 0, 0);
				glColor3f(0, 0, 0);
				glutSolidSphere(.1, 10, 10);
			glPopMatrix();
		glPopMatrix();
		//eye end

		glColor3f(.4, .85, .2);
		//left antena
		glPushMatrix();
			glScalef(.1,.1,.1);		
			glTranslatef(-7,14,0);
			glRotatef(30, 0, 0, 1);
			glPushMatrix();
				glTranslatef(0, 0, 0);
				glRotatef(90, 1, 0, 0);
				glutSolidSphere(1, 20, 20);
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				gluCylinder(quadratic, 1, 1, 4.5, 32, 32);
				glScalef(1, 1, 4);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0, -4.4, 0);
				glRotatef(90, 1, 0, 0);
				glutSolidSphere(1, 20, 20);
			glPopMatrix();
		glPopMatrix();
		//left antena end

		//right antena
		glPushMatrix();
			glScalef(.1,.1,.1);
			glTranslatef(7,14,0);
			glRotatef(-30, 0, 0, 1);
			glPushMatrix();
				glTranslatef(0, 0, 0);
				glRotatef(90, 1, 0, 0);
				glutSolidSphere(1, 20, 20);
			glPopMatrix();

			glPushMatrix();
				glRotatef(90, 1, 0, 0);
				gluCylinder(quadratic, 1, 1, 4.5, 32, 32);
				glScalef(1, 1, 4);
			glPopMatrix();

			glPushMatrix();
				glTranslatef(0, -4.4, 0);
				glRotatef(90, 1, 0, 0);
				glutSolidSphere(1, 20, 20);
			glPopMatrix();
		glPopMatrix();
		//right antena end
		//...................................................................................
		glPopMatrix();
	glPopMatrix();


	//2nd andriod

	glPushMatrix();

	glScalef(.5, .5, .5);
	glTranslated(3, -3, 0);
	glPushMatrix();
	glRotatef(_angle, 0, 1, 0);

	//........................................................................
	glPushMatrix();
	glTranslatef(0, -.4, 0);
	glPushMatrix();
	///glRotatef(rightangle, 1, 0, 0);
	//left hand
	glColor3f(.5, .85, .2);
	glPushMatrix();
	glScalef(.4, .4, .4);
	glTranslatef(-4.5, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 3.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	glPopMatrix();
	//left hand end

	glPushMatrix();
	///glRotatef(leftangle, 1, 0, 0);
	//right hand start
	glPushMatrix();
	glScalef(.4, .4, .4);
	glTranslatef(4.5, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 3.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//right hand end
	//........................................................................

	//........................................................................
	//left leg
	glPushMatrix();
	glTranslatef(0, -2.5, 0);

	glPushMatrix();
	//glRotatef(_angle, 1, 0, 0);
	glScalef(.4, .4, .4);
	glTranslatef(-1.5, 0, 0);
	///glRotatef(leftangle, 1, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 2.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	//left leg end

	//right leg start
	glPushMatrix();
	//glRotatef(_angle, 1, 0, 0);
	glScalef(.4, .4, .4);
	glTranslatef(1.5, 0, 0);
	///glRotatef(rightangle, 1, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 2.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	glPopMatrix();
	//right leg end

	//...................................................................................

	glColor3f(.4, .8, .2);

	//...................................................................................
	//head start
	glPushMatrix();
	glTranslatef(0, -.1, 0);
	glutSolidSphere(1.2, 20, 20);
	glPopMatrix();
	//head end

	//body
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1.2, 1.2, 2, 32, 32);
	glPopMatrix();
	//body end

	//lowerbody
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(.6, .6, 20, 20);
	glPopMatrix();
	//lowerbody end
	//full body end

	//eye
	glPushMatrix();
	glTranslatef(0, .5, .9);
	//left eye
	glPushMatrix();
	glTranslatef(-.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(.1, 10, 10);
	glPopMatrix();
	//left end

	//right eye
	glPushMatrix();
	glTranslatef(.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(.1, 10, 10);
	glPopMatrix();
	glPopMatrix();
	//eye end

	glColor3f(.4, .85, .2);
	//left antena
	glPushMatrix();
	glScalef(.1, .1, .1);
	glTranslatef(-7, 14, 0);
	glRotatef(30, 0, 0, 1);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 4.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -4.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//left antena end

	//right antena
	glPushMatrix();
	glScalef(.1, .1, .1);
	glTranslatef(7, 14, 0);
	glRotatef(-30, 0, 0, 1);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 4.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -4.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//right antena end
	//...................................................................................
	glPopMatrix();
	glPopMatrix();


	//3rd andriod
	glPushMatrix();

	glScalef(.5, .5, .5);
	glTranslated(-3, -3, 0);
	glPushMatrix();
	//glRotatef(_angle, 0, 1, 0);

	//........................................................................
	glPushMatrix();
	glTranslatef(0, -.4, 0);
	glPushMatrix();
///	glRotatef(rightangle, 1, 0, 0);
	//left hand
	glColor3f(.5, .85, .2);
	glPushMatrix();
	glScalef(.4, .4, .4);
	glTranslatef(-4.5, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 3.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	glPopMatrix();
	//left hand end

	glPushMatrix();
	///glRotatef(leftangle, 1, 0, 0);
	//right hand start
	glPushMatrix();
	glScalef(.4, .4, .4);
	glTranslatef(4.5, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 3.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -3.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	//right hand end
	//........................................................................

	//........................................................................
	//left leg
	glPushMatrix();
	glTranslatef(0, -2.5, 0);

	glPushMatrix();
	//glRotatef(_angle, 1, 0, 0);
	glScalef(.4, .4, .4);
	glTranslatef(-1.5, 0, 0);
///	glRotatef(leftangle, 1, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 2.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	//left leg end

	//right leg start
	glPushMatrix();
	//glRotatef(_angle, 1, 0, 0);
	glScalef(.4, .4, .4);
	glTranslatef(1.5, 0, 0);
///	glRotatef(rightangle, 1, 0, 0);
	//Capsul start
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 2.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -2.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	//Capsul end
	glPopMatrix();
	glPopMatrix();
	//right leg end

	//...................................................................................

	glColor3f(.4, .8, .2);

	//body
	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1.2, 1.2, 2, 32, 32);
	glPopMatrix();
	//body end

	//lowerbody
	glPushMatrix();
	glTranslatef(0, -2, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(.6, .6, 20, 20);
	glPopMatrix();


	glPushMatrix();

	glRotatef(headangle, 1, 0, 0);

	//...................................................................................
	//head start
	glPushMatrix();
	glTranslatef(0, -.1, 0);
	glutSolidSphere(1.2, 20, 20);
	glPopMatrix();
	//head end

	
	//lowerbody end
	//full body end

	//eye
	glPushMatrix();
	glTranslatef(0, .5, .9);
	//left eye
	glPushMatrix();
	glTranslatef(-.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(.1, 10, 10);
	glPopMatrix();
	//left end

	//right eye
	glPushMatrix();
	glTranslatef(.5, 0, 0);
	glColor3f(0, 0, 0);
	glutSolidSphere(.1, 10, 10);
	glPopMatrix();
	glPopMatrix();
	//eye end

	glColor3f(.4, .85, .2);
	//left antena
	glPushMatrix();
	glScalef(.1, .1, .1);
	glTranslatef(-7, 14, 0);
	glRotatef(30, 0, 0, 1);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 4.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -4.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//left antena end

	//right antena
	glPushMatrix();
	glScalef(.1, .1, .1);
	glTranslatef(7, 14, 0);
	glRotatef(-30, 0, 0, 1);
	glPushMatrix();
	glTranslatef(0, 0, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	gluCylinder(quadratic, 1, 1, 4.5, 32, 32);
	glScalef(1, 1, 4);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -4.4, 0);
	glRotatef(90, 1, 0, 0);
	glutSolidSphere(1, 20, 20);
	glPopMatrix();
	glPopMatrix();
	//right antena end
	//...................................................................................
	glPopMatrix();
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

	if (angleMax)
	{
		leftangle -= 2.0f;
		rightangle += 2.0f;
		if (leftangle < -30)
		{
			angleMax = false;
		}
	}
	else
	{
		leftangle += 2.0f;
		rightangle -= 2.0f;
		if (leftangle > 30)
		{
			angleMax = true;
		}
	}
	if (headmax)
	{
		headangle -= 1.0f;
		if (headangle < -10)
		{
			headmax = false;
		}
	}
	else
	{
		headangle += 1.0f;
		if (headangle > 10)
		{
			headmax = true;
		}
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