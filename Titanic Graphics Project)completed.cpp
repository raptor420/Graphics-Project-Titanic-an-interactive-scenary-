#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>

using namespace std;


int h = 1280;
int w =  1000;
int flag=0;

float lightX=4;

float SceneX = 0;
float IceX = 5;
float IceY =0;
float CloudX = 0;
float _angle = 0.0;
float ShipY = 1.5;
bool collide= false;
bool ice1=true;
bool ice2 =false;
bool ship1 = true;
bool ship2 = false;
bool End = false;
bool Day = true;
bool start = false;
int skyR = 42;
int SkyG = 237;
int SkyB  =204;
int sunR=252;
int sunG=212;
int sunB = 64;
int sunX = 3;
int oceanR=40;
int oceanG=95;
int oceanB =183;
int lightz=5;

int slghtR = 40;
int slghtG = 95;
int slghtB = 183;
bool pressu =false;
bool pressd =false;


bool CheckCollision(){

if(IceX<= -3.25 && IceX >=-5 && End == false && start== true ){
//        if (ice1&&ship1){
//
//collide = true;
//        }
//        if(ship2 && ice2){
//            collide = true;
//        }


// if the ship chooses to move being near the ice while they are in the same lane they will not collide
if(ship1 == ice1 || ship2 == ice2)  {
if(ShipY-.5>IceY)
    collide =true;
}
}
return collide;
}

void frontscreen(void)
{

glPushMatrix();
glTranslatef(-4.5,0,0);
glScalef(.02,.02,0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'T');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'I');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'T');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'A');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'N');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'I');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'C');
		glPopMatrix();
 glFlush();
}


void keyboardown(int key, int x, int y)
{
	switch (key){

	case GLUT_KEY_UP:
		//ShipY = 1.5;
		ship1 = true;
		ship2 = false;
		pressu =true;
		pressd =false;
		glutPostRedisplay();

		break;

	case GLUT_KEY_DOWN:
		//ShipY = -1;
		ship1 =false;
		ship2=true;
		glutPostRedisplay();
		pressd = true;
		pressu =false;
		break;





	default:
		break;


	}

}


void ice(){
glColor3ub(176,252,244);
glBegin(GL_POLYGON);
glVertex2f(0,1.5);
glVertex2f(0,3);
glVertex2f(1,4);
glVertex2f(1,1.5);

glEnd();

glBegin(GL_POLYGON);
glVertex2f(1,1.5);
glVertex2f(1,4);
glVertex2f(1.5,5);
glVertex2f(1.6,4.5);
glVertex2f(2,4.3);
glVertex2f(2,1.5);
glEnd();

glBegin(GL_POLYGON);
glVertex2f(2,1.5);
glVertex2f(2.2,1.5);
glVertex2f(2,1.8);
glEnd();
}

void DrawMountain(){
    float TriangleY = 3;
float TriangleX1 = -5;
float TriangleX2 = -4.5;
float TriangleX3 =-4;
float triangleground =.8;
while (TriangleX1<9) {

glBegin(GL_TRIANGLES);
glVertex2f(TriangleX1,triangleground);
glVertex2f(TriangleX2 ,TriangleY);
glVertex2f(TriangleX3,triangleground);
glEnd();

TriangleX1= TriangleX1 +1.5;
TriangleX2 = TriangleX2 + 1.5;
TriangleX3 =  TriangleX3 + 1.5;

}
}

//TriangleX = TriangleX + .5;
void Mountainscene(){
glPushMatrix();
glColor4ub(44,107,78,255); //dark green behind mountain
glScalef(2,.8,0);
glTranslatef(-.2,1.2,0);
DrawMountain();
glPopMatrix();



//(R,G,B)

glPushMatrix();  //yellow mountain
glColor4ub(22,142,34,255);
glScalef(2,.8,0);
glTranslatef(-1,1.2,0);
DrawMountain();
glPopMatrix();

glPushMatrix(); //white mountain
glColor4ub(102,193,119,255);
glScalef(1.5,2,0);
DrawMountain();
glPopMatrix();

glPushMatrix();  //blue mountain
glColor4ub(51,114,14,255);
glScalef(2,1.2,0);
glTranslatef(-1.3,.5,0);
DrawMountain();
glPopMatrix();




}

void ocean(){
    int y =2;
glColor3ub(oceanR,oceanG,oceanB);
glBegin(GL_POLYGON);
glVertex2f(-w/(2*100),-y);
glVertex2f(-w/(2*100),y);
glVertex2f(w/(2*100),y);
glVertex2f(w/(2*100),-y);
glEnd();

}


void sky(){
    int y =2;
glColor3ub(skyR,SkyG,SkyB);
glBegin(GL_POLYGON);
glVertex2f(-w/(2*100),y);
glVertex2f(-w/(2*100),h/2*100); //was 6.4 before
glVertex2f(w/(2*100),h/2*100);
glVertex2f(w/(2*100),y);
glEnd();

}




void drawship(){

glColor3ub(38,31,31);//base black
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(.2,-.6);
glVertex2f(1.6,-.6);
glVertex2f(1.7,-.1);

glColor3ub(255,255,255);//white up
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(.07,-.2);
glVertex2f(1.68,-.2);
glVertex2f(1.72,0);


glColor3ub(slghtR, slghtG, slghtB);//ship light
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(-.05,.1);
glVertex2f(-1,.3);
glVertex2f(-1,-.3);

glColor3ub(0,0,0);//left edge
glBegin(GL_POLYGON);
glVertex2f(0,0);
glVertex2f(-.05,.1);
glVertex2f(.3,.1);
glVertex2f(.3,0);

glColor3ub(0,0,0);//right edge
glBegin(GL_QUADS);
glVertex2f(1.72,0);
glVertex2f(1.75,.1);
glVertex2f(1.5,.1);
glVertex2f(1.5,0);

glColor3ub(0,0,0);//1st block
glBegin(GL_QUADS);
glVertex2f(.5,0);
glVertex2f(.5,.3);
glVertex2f(1.3,.3);
glVertex2f(1.3,0);

glColor3ub(255,255,255);//lights
glBegin(GL_QUADS);
glVertex2f(.6,.1);
glVertex2f(.63,.1);
glVertex2f(.63,.13);
glVertex2f(.6,.13);

glBegin(GL_QUADS);
glVertex2f(.7,.1);
glVertex2f(.73,.1);
glVertex2f(.73,.13);
glVertex2f(.7,.13);

glBegin(GL_QUADS);
glVertex2f(.8,.1);
glVertex2f(.83,.1);
glVertex2f(.83,.13);
glVertex2f(.8,.13);

glBegin(GL_QUADS);
glVertex2f(.9,.1);
glVertex2f(.93,.1);
glVertex2f(.93,.13);
glVertex2f(.9,.13);

glBegin(GL_QUADS);
glVertex2f(1,.1);
glVertex2f(1.03,.1);
glVertex2f(1.03,.13);
glVertex2f(1,.13);

glBegin(GL_QUADS);
glVertex2f(1.1,.1);
glVertex2f(1.13,.1);
glVertex2f(1.13,.13);
glVertex2f(1.1,.13);


glColor3ub(255,255,255);//chimney1
glBegin(GL_QUADS);
glVertex2f(1,.3);
glVertex2f(1,.5);
glVertex2f(1.1,.5);
glVertex2f(1.1,.3);
glColor3ub(0,0,0);//chimney1 extend
glBegin(GL_QUADS);
glVertex2f(1,.5);
glVertex2f(1,.6);
glVertex2f(1.1,.6);
glVertex2f(1.1,.5);

glColor3ub(215, 219, 226);//chimney1 extend part
glBegin(GL_QUADS);
glVertex2f(1,.7);
glVertex2f(1.2,.9);
glVertex2f(1.03,.6);
glVertex2f(1.03,.5);

glColor3ub(255,255,255);//chimney2
glBegin(GL_QUADS);
glVertex2f(.7,.3);
glVertex2f(.7,.5);
glVertex2f(.8,.5);
glVertex2f(.8,.3);
glColor3ub(0,0,0);//chimney2 extend
glBegin(GL_QUADS);
glVertex2f(.7,.5);
glVertex2f(.7,.6);
glVertex2f(.8,.6);
glVertex2f(.8,.5);

glColor3ub(215, 219, 226);//chimney2 extend part
glBegin(GL_QUADS);
glVertex2f(.7,.7);
glVertex2f(.9,.9);
glVertex2f(.75,.6);
glVertex2f(.75,.5);




glEnd();






}


void drawsun(){


glColor3ub(sunR, sunG, sunB);
glPushMatrix();
glutSolidSphere(.40,40,40);
glPopMatrix();
glEnd();
}
void drawcloud(){
glPushMatrix();
glColor4ub(255,255,255,175);

glTranslatef(.5,5,0);

glutSolidSphere(.30,30,30);
glPopMatrix();
glPushMatrix();

glTranslatef(1,5,0);
glColor4ub(255,255,255,230);

glutSolidSphere(.40,40,40);
glPopMatrix();
glPushMatrix();

glTranslatef(1.5,5,0);
glColor4ub(255,255,255,175);

glutSolidSphere(.30,30,30);
glPopMatrix();

glEnd();
}
void drawCloudScene()
{

    glPushMatrix();
    glTranslatef(-4,-.5,0);
drawcloud();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(4,-.5,0);
drawcloud();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0,.4,0);
drawcloud();
    glPopMatrix();

}
void shoretop(){


glColor3ub(209, 252, 255);
glBegin(GL_POLYGON);
glVertex2f(-w/(2*100),-2.2);
glVertex2f(-w/(2*100),-2);
glVertex2f(w/(2*100),-2);
glVertex2f(w/(2*100),-2.2);
glEnd();

glColor3ub(190, 251, 255);
glBegin( GL_POLYGON);

glVertex2f(0,-2.2);
glVertex2f(1,-2.2);
glVertex2f(0,-2.3);
glEnd();
glBegin( GL_POLYGON);

glVertex2f(-4,-2.2);
glVertex2f(-3,-2.2);
glVertex2f(-4,-2.3);
glEnd();
glBegin( GL_POLYGON);

glVertex2f(4,-2.2);
glVertex2f(3,-2.2);
glVertex2f(4,-2.3);
glEnd();

}

void shoremid(){

glColor3ub(91, 90, 83);

glBegin(GL_POLYGON);
glVertex2f(-w/(2*100),-2.8);
glVertex2f(-w/(2*100),-2.2);
glVertex2f(w/(2*100),-2.2);
glVertex2f(w/(2*100),-2.8);
glEnd();




}




void shore() {
glColor3ub(66, 62, 55);

glBegin(GL_POLYGON);
glVertex2f(-w/(2*100),-6.4);
glVertex2f(-w/(2*100),-2.4);
glVertex2f(w/(2*100),-2.4);
glVertex2f(w/(2*100),-6.4);
glEnd();



}



void lighthouse(){

//lower portion
glColor3ub(250,255,255);
glBegin(GL_POLYGON);
glVertex2f(-.5,1);
glVertex2f(.5,1);
glVertex2f(1,-1.5);
glVertex2f(-1,-1.5);
glEnd();

glColor3ub(255,10,20);
glBegin(GL_POLYGON);
glVertex2f(-.5,1);
glVertex2f(.5,1);
glVertex2f(.5,3);
glVertex2f(-.5,3);

glEnd();

glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(-.5,3);
glVertex2f(.5,3);
glVertex2f(.5,4);
glVertex2f(-.5,4);



glEnd();
glColor3ub(255,10,10);
glBegin(GL_POLYGON);
glVertex2f(-.5,4);
glVertex2f(.5,4);
glVertex2f(.5,5);
glVertex2f(-.5,5);

glEnd();


glColor3ub(208,214,203);
glBegin(GL_POLYGON);
glVertex2f(-.6,5);
glVertex2f(.6,5);
glVertex2f(.5,5.2);
glVertex2f(-.5,5.2);

glEnd();
glPushMatrix();
//this is light
glTranslatef(0,0,lightz);
glRotatef(_angle,0,1,0);
glColor4ub(255,255,0,150);
glBegin(GL_TRIANGLES);
glVertex2f(0,5.4);
glVertex2f(-2,5.4);
glVertex2f(-2,6.5);
glEnd();

glPopMatrix();


glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(-.4,5.2);
glVertex2f(.4,5.2);
glVertex2f(.4,5.8);
glVertex2f(-.4,5.8);

glEnd();

glColor3ub(255,255,255);
glBegin(GL_POLYGON);
glVertex2f(.6,5.8);
glVertex2f(-.6,5.8);
glVertex2f(0,6.5);

glEnd();
//lighthouse ends here, adding ground (dirt)

glColor3ub(102,93,62);
glBegin(GL_POLYGON);
glVertex2f(2,-1.55);
glVertex2f(-2,-1.5);
glVertex2f(-.8,-2);

glEnd();

//lightcones

}




void display(void)
{
/* clear all pixels */
glClear(GL_COLOR_BUFFER_BIT);
sky();

glPushMatrix();

glScalef(1.5,.666,0);
glTranslatef(SceneX,1.4,0);
Mountainscene();
glPopMatrix();
//Draw a triangle using line.


ocean();
glPushMatrix();

glTranslatef(-3.25,ShipY,0);
glRotatef(180,0,1,0);
drawship(); // ship movement here
glPopMatrix();





glPushMatrix();
glTranslatef(IceX,IceY,0);
glScalef(.5,.5,1);

ice();

glPopMatrix();

glPushMatrix();
glTranslatef(sunX,5.5,0);
drawsun();
glPopMatrix();

//clous
glPushMatrix();
glTranslatef(CloudX,0,0);
drawCloudScene(); // sun movement here
glPopMatrix();


shore();
shoremid();
shoretop();
//
glPushMatrix();
glScalef(.75,.75,1);
glTranslatef(lightX,-6,0);

lighthouse();
glPopMatrix();

glFlush();
}
void myDisplayFunction(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
gluOrtho2D(-(w/2)/100,(w/2)/100,(-h/2)/100,(h/2)/100);
glColor3ub(255,255,255);
//	glBegin(GL_POLYGON);
//
//glVertex2f(0,0);
//glVertex2f(.75,0);
//glVertex2f(.75,.75);
//
//	glEnd();
glPushMatrix();
glTranslatef(-3.5,0,0);
glScalef(.01,.01,0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'G');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'A');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'M');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'O');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'V');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'E');
		glutStrokeCharacter(GLUT_STROKE_ROMAN,'R');
		glPopMatrix();
	glFlush();
	glutSwapBuffers();
}


int winner()
{

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitWindowSize(1360, 750);
	glutCreateWindow("End");
glutInitWindowSize(h, w);
glutInitWindowPosition(0, 0);
glClearColor(0.0, 0.0, 0.0, 1.0);


	glutDisplayFunc(myDisplayFunction);
//	gluOrtho2D(-(w/2)/100,(w/2)/100,(-h/2)/100,(h/2)/100);

	glutMainLoop();

	return 0;
}


void myKeyboardFunc( unsigned char key, int x, int y )

{
  switch(key)
 {
 case 13:if(flag==0) //Ascii of 'enter' key is 13
    flag=1;
    start =true;
  break;
       }
    display();
}

void mydisplay(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

 if(flag==0)
   frontscreen ();
 if(flag==1)
  display();

   glFlush();
   glutSwapBuffers();

}



void init(void)
{
/* select clearing (background) color */
glClearColor(0.0, 0.0, 0.0, 0.0);
/* initialize viewing values */
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
//glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
 glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
gluOrtho2D(-(w/2)/100,(w/2)/100,(-h/2)/100,(h/2)/100);
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with “hello”
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
void update(int value) {
    _angle -= .5f;

	if (_angle < 360) {
		_angle += 360;
	}


if (start){
    lightX-=.008;
    SceneX -= .005;
    IceX -= .05;
    CloudX -= .01; //we can make a function, and put these over there for movement controls that'd be nice

    if(pressu){
                     ShipY+=.05;

            if(ShipY>=1.5){
                                   ShipY=1.5;

               pressu=false;
            }
    }

     else if(pressd){
                     ShipY-=.05;

        if(ShipY<=-1){
                               ShipY=-1;

pressd=false;
        }
    }


}
if(CheckCollision()){
//

End = true;
    cout << "may day";
collide =false;
//exit(30000);
winner();

}

    if(CloudX<-9.5){

        CloudX =9;

    }

    if(SceneX-.3 < -9)
    {
        SceneX= 9.5;
    }
//ice cycle



    if(IceX < -5){

       // cout<<"May Day";
IceX =5;
if(IceY >=0){

IceY = -2;
ice1 = false;
ice2 = true; }
else if (IceY <= 0)  {

    IceY = 0;

    ice1= true;
    ice2 = false;

}

    }



	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(50, update, 0); //Notify GLUT to call update again in 25 milliseconds
}

void mainmenu(int id)
{		glutPostRedisplay();

	switch(id)
	{
		case 1:exit(0);
		break;
		case 2:
		    //NIGHT
		    Day =false;
		    if(!Day){
skyR=45;
SkyG=104;
SkyB=103;
sunR=255;
sunG=255;
sunB =255;
sunX = - 3;
oceanR=24;
oceanG=57;
oceanB=109;
lightz=0;
slghtR = 222;
slghtG = 249;
slghtB = 71;

		glutPostRedisplay();


		    }

			break;
		case 3:
		    Day = true;
		    if(Day){
                skyR=42;
                SkyG=237;
                SkyB=204;
                sunR =252;
                sunG=212;
                sunB=64;
                sunX =  3;
                oceanR=40;
                oceanG=95;
                oceanB=183;
                lightz=-5;
                slghtR = 40;
                slghtG = 95;
                slghtB = 183;
		glutPostRedisplay();

		    }
			break;

	}
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize(h, w);
glutInitWindowPosition(0, 0);
glutCreateWindow("TITANIC");
init();
//glutFullScreen();

glutDisplayFunc(mydisplay);
glutCreateMenu(mainmenu);
glutAddMenuEntry("QUIT",1);
glutAddMenuEntry("NIGHT",2);
glutAddMenuEntry("DAY",3);

glutAttachMenu(GLUT_RIGHT_BUTTON);

glutTimerFunc(500,update, 0);
glutKeyboardFunc(myKeyboardFunc);
glutSpecialFunc(keyboardown);
glutMainLoop();


return 0; /* ISO C requires main to return int. */
}



