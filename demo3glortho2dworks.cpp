#include <GL/gl.h>
#include <GL/glut.h>




int h = 1920;
int w =  1080;

void DrawMountain(){
    float TriangleY = 3;
float TriangleX1 = -5;
float TriangleX2 = -4.5;
float TriangleX3 =-4;

while (TriangleX1<5) {

glBegin(GL_TRIANGLES);
glVertex2f(TriangleX1,0);
glVertex2f(TriangleX2 ,TriangleY);
glVertex2f(TriangleX3,0);
glEnd();

TriangleX1= TriangleX1 +1.5;
TriangleX2 = TriangleX2 + 1.5;
TriangleX3 =  TriangleX3 + 1.5;

}
}

//TriangleX = TriangleX + .5;

void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);

//(R,G,B)
glPushMatrix();

glScalef(1,2,0);
DrawMountain();
glPopMatrix();
//Draw a triangle using line.







glFlush();
}
void init(void)
{
/* select clearing (background) color */
glClearColor(0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
gluOrtho2D(-(w/2)/100,(w/2)/100,(-h/2)/100,(h/2)/100);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(h, w);
glutInitWindowPosition(400, 100);
glutCreateWindow("hello");
init();
glutDisplayFunc(display);
//glutFullScreen();
glutMainLoop();
return 0; /* ISO C requires main to return int. */
}

