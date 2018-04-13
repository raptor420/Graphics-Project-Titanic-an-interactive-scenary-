#include <iostream>
#include <stdlib.h>
#include <math.h>



#include <GL/glut.h>




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
	//gluLookAt(0.0,0.0,0.0,0.0,0.0,0.0,0.0,1.0,0.0);
}

float _angle = 0.0;
float _cameraAngle = 0.0;
float _ang_tri = 0.0;

//Draws the 3D scene

void drawmountain(){
    //1st three leftside mountains
    glColor3f(0.60,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-3,1.0,0);
glVertex3f(-3,0,0);
glEnd();
glColor3f(0.80,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-4,1.0,0);
glVertex3f(-3,0,0);
glEnd();
    glColor3f(0.60,0.40,0.12);

glPushMatrix();
glRotatef(30,1,0,0);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-4,1.0,0);
glVertex3f(-3,0,0);
glEnd();
glPopMatrix();
//left side mountain


glColor3f(0.60,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-3,1.0,0);
glVertex3f(-3,0,0);
glEnd();
glColor3f(0.80,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-4,1.0,0);
glVertex3f(-3,0,0);
glEnd();
    glColor3f(0.60,0.40,0.12);




//3more after them, using translate
glPushMatrix();
glTranslatef(2,0,0);
glColor3f(0.60,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-3,1.0,0);
glVertex3f(-3,0,0);
glEnd();
glColor3f(0.80,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-4,1.0,0);
glVertex3f(-3,0,0);
glEnd();
    glColor3f(0.60,0.40,0.12);

glPushMatrix();
glRotatef(30,1,0,0);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-4,1.0,0);
glVertex3f(-3,0,0);
glEnd();
//new boiis
glColor3f(0.64,0.60,0.52);
glBegin(GL_TRIANGLES);
glVertex3f(1,0,0);
glVertex3f(0,2,0);
glVertex3f(-1,0,0);
glEnd();
glColor3f(0.00,0.60,0.52);
glBegin(GL_POLYGON);
glVertex3f(1,0,0);
glVertex3f(0,2,0);
glVertex3f(-3,0,0);
glVertex3f(1,1,0);
glEnd();

glPopMatrix();


glColor3f(0.60,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-3,1.0,0);
glVertex3f(-3,0,0);
glEnd();
glColor3f(0.80,0.40,0.12);
glBegin(GL_TRIANGLES);
glVertex3f(-5.5,0,0);
glVertex3f(-4,1.0,0);
glVertex3f(-3,0,0);
glEnd();
glPopMatrix();

glBegin(GL_TRIANGLES);
glVertex3f(5.5,0,0);
glVertex3f(3,2.5,0);
glVertex3f(0,0,0);
glEnd();

glColor3f(0.20,0.40,0.52);
glBegin(GL_TRIANGLES);
glVertex3f(3,1.5,0);
glVertex3f(1,1.5,0);
glVertex3f(0,0,0);
glEnd();

glColor3f(0.64,0.60,0.52);
glBegin(GL_TRIANGLES);
glVertex3f(1,0,0);
glVertex3f(0,2,0);
glVertex3f(-1,0,0);
glEnd();
glColor3f(0.00,0.60,0.52);
glBegin(GL_POLYGON);
glVertex3f(1,0,0);
glVertex3f(0,2,0);
glVertex3f(-3,0,0);
glVertex3f(1,1,0);
glEnd();


glBegin(GL_POLYGON);
glVertex3f(3.5,1,0);
glVertex3f(5.5,2,0);
glVertex3f(5.5,0,0);
glVertex3f(1,0,0);
glEnd();

}
void drawScene() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glRotatef(-_cameraAngle, 0.0, 1.0, 0.0); //Rotate the camera
	glTranslatef(0.0, 0.0, -7.0); //Move forward 5 units
//enter code here
drawmountain();
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
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1920, 1080);

	glutInitWindowPosition(0,0);


	//Create the window
	glutCreateWindow("DEMO");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}


	/*glBegin(GL_TRIANGLES);

	//Pentagon
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, 0.0, 0.0);

	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.0, 0.0);

	glVertex3f(-0.5, 0.0, 0.0);
	glVertex3f(0.5, 0.0, 0.0);
	glVertex3f(0.0, 0.5, 0.0);

	glEnd();

*/






