#include<stdio.h>
#include<GL/glut.h>
#include <graphics.h>
#include "math.h"
#define DEG2RAD 3.14159/180.0
// Define the value of PI, upto 12 decimal places
#define PI 3.141592653589
#pragma GCC diagnostic ignored "-Wwrite-strings"

void bus(int);
void road();
void signal();
void car(int);
void bush();
void mydisplay();
void display();
void frontsreen();
void drawstring();
void setFont();
void myMouse();
void update();
void control();
void helpscreen();
void drawCircle(GLfloat x, GLfloat y,
                GLfloat r, GLfloat g, GLfloat b,
                GLfloat sx, GLfloat sy,
                GLfloat radius);
void drawSemiCircle(GLfloat tx, GLfloat ty,
                    GLfloat sx, GLfloat sy,
                    GLfloat r, GLfloat g, GLfloat b,
                    GLfloat radius,
                    GLfloat start_angle, GLfloat end_angle);
void drawArc(GLfloat tx, GLfloat ty,
             GLfloat sx, GLfloat sy,
             GLfloat r, GLfloat g, GLfloat b);
void drawWoman(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
               GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
               GLfloat top_r, GLfloat top_g, GLfloat top_b,
               GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
               GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b);
void print(char *string,
           GLfloat r, GLfloat g, GLfloat b, GLfloat a,
           GLint x, GLint y,
           GLfloat w, GLfloat h,
           GLfloat strokeSize);
void WP_drawThoughtBubble();
void drawTree(GLfloat tx, GLfloat ty,
              GLfloat sx, GLfloat sy);

GLint a=300,b=-300,flag=0,traffic_regulator=1,control_keyl,control_keyr;
GLfloat red=0,blue=1,green=.3;

GLfloat p=0,q=0,r=0;


bool wp_tb_s1_done, wp_tb_s2_done, wp_tb_s3_done, wp_tb_big_done;
GLfloat wp_tb_s1, wp_tb_s2, wp_tb_s3, wp_tb_big,
        wp_tb_text;
//-----------
void *currentfont;

void setFont(void *font)
{
    currentfont=font;
}

void drawstring(float x,float y,float z,char *string)
{
    char *c;
    glRasterPos3f(x,y,z);

    for(c=string; *c!='\0'; c++)
    {
        glColor3f(0.0,0.0,0.0);
        glutBitmapCharacter(currentfont,*c);
    }
}

void frontscreen(void)
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.1,0.1,0.1,0.1);/*background for cover page*/
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1,1,1);
    drawstring(370.0,680.0,0.0,"FR. CONCEICAO RODRIGUES COLLEGE OF ENGINEERING ");
    glColor3f(1,1,1);
    drawstring(355,650,0.0,"DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");

    glColor3f(0.5,0.1,1);
    drawstring(580,600,0.0,"A MINI PROJECT ON");

    glColor3f(1,0.5,0);
    drawstring(270,550,0.0,"GRAPHICAL REPRESENTATION OF TRAFFIC SIGNALS AND TRAFFIC RULES");
    glColor3f(1,0.5,0);

    setFont(GLUT_BITMAP_9_BY_15);

    drawstring(510,400,0.0,"BY:");
    glColor3f(1,1,1);
    drawstring(510,360,0.0,"Ivan Dsilva");
    glColor3f(1,1,1);
    drawstring(510,320,0.0,"Malaika Monteiro");
    glColor3f(1,1,1);
    drawstring(510,280,0.0,"Kris Corriea");
    glColor3f(1,1,1);
    drawstring(510,240,0.0,"Sarah Abraham");
    glColor3f(1,0.5,0);

    drawstring(780,400,0.0,"ROLL NO:");

    glColor3f(1,1,1);
    drawstring(790,360,0.0,"9193");

    glColor3f(1,1,1);
    drawstring(790,320,0.0,"9211");

    glColor3f(1,1,1);
    drawstring(790,280,0.0,"9185");

    glColor3f(1,1,1);
    drawstring(790,240,0.0,"9231");

    glColor3f(1,0.1,1);
    drawstring(540,95,0.0,"***   PRESS ENTER TO START    ***");

    glColor3f(1,0.1,1);



    glFlush();






}

void helpscreen()
{
    setFont(GLUT_BITMAP_TIMES_ROMAN_24);
    glClearColor(0.9,0.9,1,1);/*background for cover page*/
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0.5,0.1,1);
    drawstring(650.0,670.0,0.0,"CONTROLS");



    setFont(GLUT_BITMAP_9_BY_15);

    glColor3f(0.5,0.1,0.2);
    drawstring(350.0,580.0,0.0,"Stop the traffic (Red Light) ........................ MOUSE LEFT CLICK");
    glColor3f(0.5,0.1,0.3);
    drawstring(350.0,540.0,0.0,"Yellow Signal ....................................... MOUSE RIGHT BUTTON (HOLD ON)");
    glColor3f(0.5,0.1,0.4);
    drawstring(350.0,500.0,0.0,"Green Signal ........................................ MOUSE RIGHT BUTTON (RELEASE)");
    glColor3f(0.4,0.1,0.5);
    drawstring(350.0,460.0,0.0,"Allow vehicles to MOVE left to right ................ PRESS 'L'");
    glColor3f(0.5,0.1,0.6);
    drawstring(350.0,420.0,0.0,"Allow vehicles to MOVE right to left ................ PRESS 'R'");
    glColor3f(0.5,0.1,0.7);
    drawstring(350.0,380.0,0.0,"Speed up the vehicles ............................... PRESS 'S'");
    glColor3f(0.5,0.1,0.8);
    drawstring(350.0,220.0,0.0,"Help ................................................ PRESS 'H'");
    glColor3f(0.5,0.1,0.9);
    drawstring(350.0,190.0,0.0,"Escape .............................................. PRESS 'ENTER'");
    glFlush();
}

void control()
{
    if(control_keyl!='l'||control_keyr!='r')
    {
        if(control_keyl=='l')
            a=a+6;
        if(control_keyr=='r')
            b=b-6;
    }

}

void myKeyboard( unsigned char key, int x, int y )

{
    switch(key)
    {
    case 13:
        if(flag==1)
        {
            flag=2;
            mydisplay();
        }
        if(flag==0) //Ascii of 'enter' key is 13
        {
            flag=1;
            mydisplay();
        }

        break;
    case 'l':
        control_keyl=key;
        p=0;
        q=0;
        r=1;
        break;
    case 'r':
        control_keyr=key;
        p=0;
        q=0;
        r=1;
        break;
    case 's':
        mydisplay();
        break;
    case 'h':
        flag=1;
        mydisplay();
        break;
    default:
        break;
    }

}

void myMouse(int button,int state,int x,int y)
{
    if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
    {
        traffic_regulator=0;
        p=1;
        q=0;
        r=0;
    }

    if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
    {
        traffic_regulator=0;
        p=0;
        q=1;
        r=0;
    }
    if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
    {
        traffic_regulator=1;
        p=0;
        q=0;
        r=1;
    }
    glutPostRedisplay();




}

void mydisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(flag==0)
        frontscreen ();
    if(flag==1)
        helpscreen();
    if(flag==2)
        display();
    glutSwapBuffers();
}

void update(int value)
{
    a=a-6;
    b=b+6;
    control();
    /*making day to night*/
    if(blue!=0&&green!=0)
    {
        blue-=.004;
        green-=.004;
    }

    glutPostRedisplay();
}

void display(void)
{
    if(traffic_regulator)
        glutTimerFunc(50,update,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(red,green,blue,0);/*back ground for sky*/
  /**  glBegin(GL_POLYGON);
    glColor3f(0.4,0.0,1.0);
    glVertex2d(0,0);
        glColor3f(0.0,0.0,0.0);
    glVertex2d(0,1700);
        glColor3f(0.0,0.0,0.0);
    glVertex2d(1700,500);
    glColor3f(0.4,1.0,0.0);
    glVertex2d(1700,0);
    glEnd(); **/


    drawWoman(1700, 200, -1, 1,
              20, 20, 20,
              229, 49, 49, // top
              37, 107, 202, // bottom
              229, 49, 49 // skirt
             );

    WP_drawThoughtBubble();

    road();
    drawTree(304,400,1,1);
    drawTree(104,400,1,1);

    int temp = 0;
    for(int j = 0; j < 100; j++)
    {
        bus(temp);
        temp = temp + 2000;
    }
    signal();
    int temp1 = 0;
    for(int i = 0; i < 100 ; i++)
    {
        car(temp1);
        temp1 = temp1 + 2000;
    }
    glColor3ub(5,56,4);
    glRectf(0,0,1500,160);
    bush();
    glFlush();

}

void road()
{
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
//straight road
    glVertex2f(0,5);
    glVertex2f(40,5);
    glVertex2f(40,10);
    glVertex2f(0,10);
    glEnd();
//green edge
    glBegin(GL_POLYGON);
    glColor3f(0.1,0.2,0.1);
    glVertex2f(0,5);
    glVertex2f(40,5);
    glVertex2f(40,4);
    glVertex2f(0,4);
    glEnd();
//cross road
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(10,10);
    glVertex2f(15,10);
    glVertex2f(0,40);
    glVertex2f(4,40);
    glEnd();
    glPopMatrix();

    glLineWidth(2);
    glBegin(GL_LINES);
    glColor3ub(255, 255, 255);
    glVertex2f(0, 325);
    glVertex2f(100, 325);

    glVertex2f(200, 325);
    glVertex2f(400, 325);

    glVertex2f(500, 325);
    glVertex2f(700, 325);

    glVertex2f(800, 325);
    glVertex2f(1000, 325);

    glVertex2f(1100, 325);
    glVertex2f(1300, 325);

    glVertex2f(1400, 325);
    glVertex2f(1600, 325);
    glEnd();
    glLineWidth(1);
}

void signal()
{
    glPushMatrix();
    glScaled(40.0,40.0,0.0);
//stand
    glColor3f(0.1,0.2,0.1);
    glBegin(GL_POLYGON);
    glVertex2f(15,7);
    glVertex2f(15,8);
    glVertex2f(18,8);
    glVertex2f(18,7);
    glEnd();
//pole
    glBegin(GL_POLYGON);
    glVertex2f(16,7);
    glVertex2f(17,8);
    glVertex2f(17,15);
    glVertex2f(16,15);
    glEnd();
//board
    glBegin(GL_POLYGON);
    glVertex2f(15.5,15);
    glVertex2f(17.5,15);
    glVertex2f(17.5,10);
    glVertex2f(15.5,10);
    glEnd();
//red
    glColor3f(p,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(16,14.5);
    glVertex2f(17,14.5);
    glVertex2f(17,14);
    glVertex2f(16,14);
    glEnd();
//yellow
    glColor3f(q,q,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(16,13.5);
    glVertex2f(17,13.5);
    glVertex2f(17,13);
    glVertex2f(16,13);
    glEnd();
//green
    glColor3f(0.0,r,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(16,12.5);
    glVertex2f(17,12.5);
    glVertex2f(17,12);
    glVertex2f(16,12);
    glEnd();
    glPopMatrix();
}

void bus(int t)
{
    glPushMatrix();
    glTranslated((a+t),50.0,0.0);
    glScaled(40.0,40.0,0.0);
    glColor3f(0.5,0.0,0.0);
//bus out line
    glBegin(GL_POLYGON);
    glVertex2f(25,8);
    glVertex2f(25,9.5);
    glVertex2f(26,11);
    glVertex2f(32,11);
    glVertex2f(32,8);
    glEnd();
//window frame
    glColor3f(0,0.1,1);
    glBegin(GL_POLYGON);
    glVertex2f(26.1,9.5);
    glVertex2f(26.1,10.5);
    glVertex2f(31.8,10.5);
    glVertex2f(31.8,9.5);
    glEnd();
//Doors
    glColor3f(0,0.8,1);
    glBegin(GL_POLYGON);
    glVertex2f(26.2,9);
    glVertex2f(26.2,10.4);
    glVertex2f(27.7,10.4);
    glVertex2f(27.7,9);
    glEnd();


    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(27,8.4);
    glVertex2f(27,10.4);
    glVertex2f(27.7,10.4);
    glVertex2f(27.7,8.4);
    glEnd();
//small windows
    glColor3f(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(27.8,9.6);
    glVertex2f(27.8,10.4);
    glVertex2f(29,10.4);
    glVertex2f(29,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(29.1,9.6);
    glVertex2f(29.1,10.4);
    glVertex2f(30.2,10.4);
    glVertex2f(30.2,9.6);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(30.3,9.6);
    glVertex2f(30.3,10.4);
    glVertex2f(31.7,10.4);
    glVertex2f(31.7,9.6);
    glEnd();


//driver window
    glColor3f(0,0.8,1);
    glBegin(GL_POLYGON);
    glVertex2f(25,9.5);
    glVertex2f(26,11);
    glVertex2f(26,9.5);
    glEnd();
    glPopMatrix();
//tyre
    glPushMatrix();//front tyre
    glTranslated((a+970+t),320,0.0);
    glScaled(20.0,20.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(3.0,2.5);
    glVertex2f(3.0,2.6);
    glVertex2f(3.15,3.1);
    glVertex2f(3.2,3.2);
    glVertex2f(3.3,3.35);
    glVertex2f(3.4,3.4);
    glVertex2f(3.5,3.45);
    glVertex2f(3.6,3.55);
    glVertex2f(3.7,3.6);
    glVertex2f(3.8,3.63);
    glVertex2f(4.0,3.65);
    glVertex2f(4.2,3.7);
    glVertex2f(4.4,3.7);
    glVertex2f(4.6,3.65);
    glVertex2f(4.8,3.55);
    glVertex2f(5.0,3.45);
    glVertex2f(5.1,3.4);
    glVertex2f(5.2,3.25);
    glVertex2f(5.3,3.2);
    glVertex2f(5.4,3.0);
    glVertex2f(5.5,2.5);

    glVertex2f(5.45,2.15);
    glVertex2f(5.4,1.9);
    glVertex2f(5.35,1.8);
    glVertex2f(5.2,1.6);
    glVertex2f(5.0,1.5);
    glVertex2f(4.9,1.4);
    glVertex2f(4.7,1.3);
    glVertex2f(4.6,1.27);
    glVertex2f(4.4,1.25);
    glVertex2f(4.0,1.25);
    glVertex2f(3.9,1.3);
    glVertex2f(3.75,1.35);
    glVertex2f(3.6,1.4);
    glVertex2f(3.45,1.55);
    glVertex2f(3.3,1.7);
    glVertex2f(3.2,1.8);
    glVertex2f(3.1,2.2);
    glEnd();
    glPopMatrix();

    glPushMatrix();//back tyre
    glTranslated((a+1140+t),320,0.0);
    glScaled(20.0,20.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(3.0,2.5);
    glVertex2f(3.0,2.6);
    glVertex2f(3.15,3.1);
    glVertex2f(3.2,3.2);
    glVertex2f(3.3,3.35);
    glVertex2f(3.4,3.4);
    glVertex2f(3.5,3.45);
    glVertex2f(3.6,3.55);
    glVertex2f(3.7,3.6);
    glVertex2f(3.8,3.63);
    glVertex2f(4.0,3.65);
    glVertex2f(4.2,3.7);
    glVertex2f(4.4,3.7);
    glVertex2f(4.6,3.65);
    glVertex2f(4.8,3.55);
    glVertex2f(5.0,3.45);
    glVertex2f(5.1,3.4);
    glVertex2f(5.2,3.25);
    glVertex2f(5.3,3.2);
    glVertex2f(5.4,3.0);
    glVertex2f(5.5,2.5);

    glVertex2f(5.45,2.15);
    glVertex2f(5.4,1.9);
    glVertex2f(5.35,1.8);
    glVertex2f(5.2,1.6);
    glVertex2f(5.0,1.5);
    glVertex2f(4.9,1.4);
    glVertex2f(4.7,1.3);
    glVertex2f(4.6,1.27);
    glVertex2f(4.4,1.25);
    glVertex2f(4.0,1.25);
    glVertex2f(3.9,1.3);
    glVertex2f(3.75,1.35);
    glVertex2f(3.6,1.4);
    glVertex2f(3.45,1.55);
    glVertex2f(3.3,1.7);
    glVertex2f(3.2,1.8);
    glVertex2f(3.1,2.2);
    glEnd();
    glPopMatrix();
}

void car(int t)
{
    glPushMatrix(); //making color for outer line
    glTranslated((b-t),190.0,0.0);
    glScaled(20.0,20.0,0.0);
    glColor3f(1.0,0.5,0.4);
    glBegin(GL_POLYGON);
    glVertex2f(2.5,2.5);
    glVertex2f(3.0,3.5);
    glVertex2f(3.5,3.75);
    glVertex2f(4.0,4.0);
    glVertex2f(4.5,4.0);
    glVertex2f(5.0,3.75);
    glVertex2f(5.5,3.5);
    glVertex2f(5.75,3.0);
    glVertex2f(6.0,2.5);
    glVertex2f(16.5,2.5);
    glVertex2f(16.75,3.0);
    glVertex2f(17.0,3.5);
    glVertex2f(17.5,3.75);
    glVertex2f(18.0,4.0);
    glVertex2f(18.5,4.0);
    glVertex2f(19.0,3.75);
    glVertex2f(19.5,3.5);
    glVertex2f(19.75,3.0);
    glVertex2f(20.0,2.5);
    glVertex2f(21.0,2.5);
    glVertex2f(21.0,4.0);
    glVertex2f(21.5,4.0);
    glVertex2f(21.0,4.5);
    glVertex2f(20.0,5.0);
    glVertex2f(15.0,5.0);
    glVertex2f(14.0,5.5);
    glVertex2f(13.0,6.0);
    glVertex2f(12.0,6.5);
    glVertex2f(11.0,7.0);
    glVertex2f(6.0,7.0);
    glVertex2f(5.0,6.5);
    glVertex2f(4.5,6.25);
    glVertex2f(4.25,6.0);
    glVertex2f(4.0,5.75);
    glVertex2f(3.5,5.5);
    glVertex2f(3.0,5.5);
    glVertex2f(1.9,5.45);
    glVertex2f(1.8,5.4);
    glVertex2f(1.7,5.35);
    glVertex2f(1.6,5.3);
    glVertex2f(1.5,5.25);
    glVertex2f(1.4,5.15);
    glVertex2f(1.3,5.0);
    glVertex2f(1.2,4.85);
    glVertex2f(1.1,4.7);
    glVertex2f(1.0,4.3);
    glVertex2f(1.0,3.2);
    glVertex2f(1.1,3.05);
    glVertex2f(1.2,2.9);
    glVertex2f(1.3,2.9);
    glVertex2f(1.4,2.75);
    glVertex2f(1.5,2.65);
    glVertex2f(1.6,2.6);
    glVertex2f(1.7,2.55);
    glVertex2f(1.8,2.5);
    glVertex2f(1.9,2.45);
    glVertex2f(2.0,2.5);
    glEnd();

    glColor3f(1.0,1.0,1.0); //color for outer window
    glBegin(GL_POLYGON);
    glVertex2f(5.0,5.0);
    glVertex2f(14.0,5.0);
    glVertex2f(11.5,6.5);
    glVertex2f(10.5,6.75);
    glVertex2f(7.0,6.75);
    glEnd();

    glColor3f(0.0,0.0,0.0); //making outer line for car
    glBegin(GL_LINE_LOOP);
    glVertex2f(2.5,2.5);
    glVertex2f(3.0,3.5);
    glVertex2f(3.5,3.75);
    glVertex2f(4.0,4.0);
    glVertex2f(4.5,4.0);
    glVertex2f(5.0,3.75);
    glVertex2f(5.5,3.5);
    glVertex2f(5.75,3.0);
    glVertex2f(6.0,2.5);
    glVertex2f(16.5,2.5);
    glVertex2f(16.75,3.0);
    glVertex2f(17.0,3.5);
    glVertex2f(17.5,3.75);
    glVertex2f(18.0,4.0);
    glVertex2f(18.5,4.0);
    glVertex2f(19.0,3.75);
    glVertex2f(19.5,3.5);
    glVertex2f(19.75,3.0);
    glVertex2f(20.0,2.5);
    glVertex2f(21.0,2.5);
    glVertex2f(21.0,4.0);
    glVertex2f(21.5,4.0);
    glVertex2f(21.0,4.5);
    glVertex2f(20.0,5.0);
    glVertex2f(15.0,5.0);
    glVertex2f(14.0,5.5);
    glVertex2f(13.0,6.0);
    glVertex2f(12.0,6.5);
    glVertex2f(11.0,7.0);
    glVertex2f(6.0,7.0);
    glVertex2f(5.0,6.5);
    glVertex2f(4.5,6.25);
    glVertex2f(4.25,6.0);
    glVertex2f(4.0,5.75);
    glVertex2f(3.5,5.5);
    glVertex2f(3.0,5.5);
    glVertex2f(1.9,5.45);
    glVertex2f(1.8,5.4);
    glVertex2f(1.7,5.35);
    glVertex2f(1.6,5.3);
    glVertex2f(1.5,5.25);
    glVertex2f(1.4,5.15);
    glVertex2f(1.3,5.0);
    glVertex2f(1.2,4.85);
    glVertex2f(1.1,4.7);
    glVertex2f(1.0,4.3);
    glVertex2f(1.0,3.2);
    glVertex2f(1.1,3.05);
    glVertex2f(1.2,2.9);
    glVertex2f(1.3,2.9);
    glVertex2f(1.4,2.75);
    glVertex2f(1.5,2.65);
    glVertex2f(1.6,2.6);
    glVertex2f(1.7,2.55);
    glVertex2f(1.8,2.5);
    glVertex2f(1.9,2.45);
    glVertex2f(2.0,2.5);
    glEnd();

    glColor3f(0.0,0.0,0.0);
    glBegin(GL_LINE_LOOP); //outer line for design a car
    glVertex2f(8.0,3.0);
    glVertex2f(16.0,3.0);
    glVertex2f(16.5,3.5);
    glVertex2f(17.0,4.0);
    glVertex2f(16.5,4.25);
    glVertex2f(16.0,4.5);
    glVertex2f(15.0,4.5);
    glVertex2f(15.0,5.0);
    glVertex2f(14.0,5.0);
    glVertex2f(11.5,6.5);
    glVertex2f(10.5,6.75);
    glVertex2f(7.0,6.75);
    glVertex2f(5.0,5.0);
    glVertex2f(7.0,5.0);
    glVertex2f(6.5,4.5);
    glEnd();


    glBegin(GL_LINES); //connecting outer line
    glVertex2d(7.0,5.0);
    glVertex2d(15.0,5.0);
    glEnd();

    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(15.0,4.0);
    glVertex2d(17.0,4.0);
    glEnd();

    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(15.0,3.5);
    glVertex2d(16.5,3.5);
    glEnd();

    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(15.0,5.0);
    glVertex2d(14.0,3.0);
    glEnd();

    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(12.0,5.0);
    glVertex2d(12.0,6.2);
    glEnd();

    glColor3f(0.0,0.0,0.0); //connecting outer line
    glBegin(GL_LINES);
    glVertex2d(7.0,5.0);
    glVertex2d(7.0,6.7);
    glEnd();

    glBegin(GL_POLYGON); //drawing a back tyre
    glVertex2f(3.0,2.5);
    glVertex2f(3.0,2.6);
    glVertex2f(3.15,3.1);
    glVertex2f(3.2,3.2);
    glVertex2f(3.3,3.35);
    glVertex2f(3.4,3.4);
    glVertex2f(3.5,3.45);
    glVertex2f(3.6,3.55);
    glVertex2f(3.7,3.6);
    glVertex2f(3.8,3.63);
    glVertex2f(4.0,3.65);
    glVertex2f(4.2,3.7);
    glVertex2f(4.4,3.7);
    glVertex2f(4.6,3.65);
    glVertex2f(4.8,3.55);
    glVertex2f(5.0,3.45);
    glVertex2f(5.1,3.4);
    glVertex2f(5.2,3.25);
    glVertex2f(5.3,3.2);
    glVertex2f(5.4,3.0);
    glVertex2f(5.5,2.5);

    glVertex2f(5.45,2.15);
    glVertex2f(5.4,1.9);
    glVertex2f(5.35,1.8);
    glVertex2f(5.2,1.6);
    glVertex2f(5.0,1.5);
    glVertex2f(4.9,1.4);
    glVertex2f(4.7,1.3);
    glVertex2f(4.6,1.27);
    glVertex2f(4.4,1.25);
    glVertex2f(4.0,1.25);
    glVertex2f(3.9,1.3);
    glVertex2f(3.75,1.35);
    glVertex2f(3.6,1.4);
    glVertex2f(3.45,1.55);
    glVertex2f(3.3,1.7);
    glVertex2f(3.2,1.8);
    glVertex2f(3.1,2.2);
    glEnd();


    glBegin(GL_POLYGON); //drawing front tyre
    glVertex2f(17.0,2.5);
    glVertex2f(17.0,2.6);
    glVertex2f(17.15,3.1);
    glVertex2f(17.2,3.2);
    glVertex2f(17.3,3.35);
    glVertex2f(17.4,3.4);
    glVertex2f(17.5,3.45);
    glVertex2f(17.6,3.55);
    glVertex2f(17.7,3.6);
    glVertex2f(17.8,3.63);
    glVertex2f(18.0,3.65);
    glVertex2f(18.2,3.7);
    glVertex2f(18.4,3.7);
    glVertex2f(18.6,3.65);
    glVertex2f(18.8,3.55);
    glVertex2f(19.0,3.45);
    glVertex2f(19.1,3.4);
    glVertex2f(19.2,3.25);
    glVertex2f(19.3,3.2);
    glVertex2f(19.4,3.0);

    glVertex2f(19.5,2.5);
    glVertex2f(19.45,2.15);
    glVertex2f(19.4,1.9);
    glVertex2f(19.35,1.8);
    glVertex2f(19.2,1.6);
    glVertex2f(19.0,1.5);
    glVertex2f(18.9,1.4);
    glVertex2f(18.7,1.3);
    glVertex2f(18.6,1.27);
    glVertex2f(18.4,1.25);
    glVertex2f(18.0,1.25);
    glVertex2f(17.9,1.3);
    glVertex2f(17.75,1.35);
    glVertex2f(17.6,1.4);
    glVertex2f(17.45,1.55);
    glVertex2f(17.3,1.7);
    glVertex2f(17.2,1.8);
    glVertex2f(17.1,2.2);
    glEnd();
    glPopMatrix();
}


void myinit()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,1346.0,0.0,728.0);
}

void drawCircle(GLfloat x, GLfloat y,
                GLfloat r, GLfloat g, GLfloat b,
                GLfloat sx, GLfloat sy,
                GLfloat radius)
{
    glPushMatrix();

    glTranslatef(x, y, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = 0; i < 360; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

    glPopMatrix();
}

// Function to Draw Circle
void drawSemiCircle(GLfloat tx, GLfloat ty,
                    GLfloat sx, GLfloat sy,
                    GLfloat r, GLfloat g, GLfloat b,
                    GLfloat radius,
                    GLfloat start_angle, GLfloat end_angle)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    glBegin(GL_POLYGON);
    glColor3ub(r, g, b);
    for (GLfloat i = start_angle; i < end_angle; i += 5)
        glVertex2f(radius * sin(i * PI / 180), radius * cos(i * PI / 180));
    glEnd();

    glPopMatrix();
}

// Function to Draw Arc
void drawArc(GLfloat tx, GLfloat ty,
             GLfloat sx, GLfloat sy,
             GLfloat r, GLfloat g, GLfloat b)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    glPointSize(2);
    glBegin(GL_POINTS);
    glColor3ub(r, g, b);
    for ( GLfloat i = 90; i < 270; i++)
        glVertex2f(15 * sin(i * PI / 180), 15 * cos(i * PI / 180));
    glEnd();
    glPointSize(1);

    glPopMatrix();
}
// Function to Draw a Woman
void drawWoman(GLfloat tx, GLfloat ty, GLfloat sx, GLfloat sy,
               GLfloat hair_r, GLfloat hair_g, GLfloat hair_b,
               GLfloat top_r, GLfloat top_g, GLfloat top_b,
               GLfloat ribbon_r, GLfloat ribbon_g, GLfloat ribbon_b,
               GLfloat skirt_r, GLfloat skirt_g, GLfloat skirt_b)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    // Neck
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(203, 166, 108); // Darker Skin
    glVertex2f(507, 380);
    glVertex2f(507, 360);
    glVertex2f(513, 380);
    glVertex2f(513, 360);
    glEnd();
    glLineWidth(1);

    // Face
    drawCircle(510, 407,
               232, 190, 123, // Lighter Skin
               1, 1,
               30);

    // Hair
    drawSemiCircle(510, 420, 1, .6,
                   hair_r, hair_g, hair_b,
                   35, -90, 90);

    drawSemiCircle(485, 400, .4, 1,
                   hair_r, hair_g, hair_b,
                   35, -180, 0);

    // Left Eye
    drawCircle(505, 410,
               250, 250, 250,
               1, 1,
               5);

    drawCircle(508, 408,
               10, 10, 10,
               1, 1,
               2.5);

    // Right Eye
    drawCircle(530, 410,
               250, 250, 250,
               1, 1,
               5);

    drawCircle(532, 408,
               10, 10, 10,
               1, 1,
               2.5);

    // Smile
    drawArc(514, 388, .5, .3,
            20, 20, 20);

    // Nose
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2f(518, 405);
    glVertex2f(522, 398);
    glVertex2f(522, 398);
    glVertex2f(518, 395);
    glEnd();
    glLineWidth(1);

    // Arms
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(232, 190, 123); // Lighter Skin
    glVertex2f(470, 340);
    glVertex2f(470, 240);
    glVertex2f(475, 340);
    glVertex2f(475, 240);
    glVertex2f(480, 340);
    glVertex2f(480, 240);

    glVertex2f(540, 340);
    glVertex2f(540, 240);
    glVertex2f(545, 340);
    glVertex2f(545, 240);
    glVertex2f(550, 340);
    glVertex2f(550, 240);
    glEnd();
    glLineWidth(1);

    // Top
    glBegin(GL_POLYGON);
    glColor3ub(top_r, top_g, top_b);
    glVertex2f(460, 370);
    glVertex2f(560, 370);
    glVertex2f(540, 300);
    glVertex2f(480, 300);
    glEnd();

    // Skirt
    glBegin(GL_POLYGON);
    glColor3ub(skirt_r, skirt_g, skirt_b);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glVertex2f(560, 180);
    glVertex2f(460, 180);
    glEnd();

    // Ribbon
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(ribbon_r, ribbon_g, ribbon_b);
    glVertex2f(480, 300);
    glVertex2f(540, 300);
    glEnd();
    glLineWidth(1);

    // Legs
    glLineWidth(10);
    glBegin(GL_LINES);
    glColor3ub(232, 190, 123); // Lighter Skin
    glVertex2f(490, 180);
    glVertex2f(490, 150);
    glVertex2f(495, 180);
    glVertex2f(495, 150);

    glVertex2f(525, 180);
    glVertex2f(525, 150);
    glVertex2f(530, 180);
    glVertex2f(530, 150);
    glEnd();
    glLineWidth(1);

    glPopMatrix();
}
void print(char *string,
           GLfloat r, GLfloat g, GLfloat b, GLfloat a,
           GLint x, GLint y,
           GLfloat w, GLfloat h,
           GLfloat strokeSize)
{
    glPushMatrix();

    glColor4f(r, g, b, a);
    glTranslatef(x, y, 0);
    glScalef(w, h, 0);

    glPointSize(strokeSize);
    glLineWidth(strokeSize);

    while (*string)
        glutStrokeCharacter(GLUT_STROKE_MONO_ROMAN, *string++);

    glPopMatrix();

    glLineWidth(1);
    glPointSize(1);
}
void WP_drawThoughtBubble()
{

    // Thought Bubble
    /**drawCircle(800, 580, 150, 200, 240, 1, 1, 80);
    drawCircle(840, 600, 150, 200, 240, 1, 1, 80);
    drawCircle(880, 600, 150, 200, 240, 1, 1, 80);
    drawCircle(920, 600, 150, 200, 240, 1, 1, 80);
    drawCircle(960, 600, 150, 200, 240, 1, 1, 80);
    drawCircle(1000, 580, 150, 200, 240, 1, 1, 80);
    drawCircle(840, 560, 150, 200, 240, 1, 1, 80);
    drawCircle(880, 560, 150, 200, 240, 1, 1, 80);
    drawCircle(920, 560, 150, 200, 240, 1, 1, 80);
    drawCircle(960, 560, 150, 200, 240, 1, 1, 80);**/

    // callout
    glBegin(GL_POLYGON);
    glColor3b(100,100,100);
    glVertex2d( 1000, 700 );
    glVertex2d( 1050, 600 );
    glVertex2d( 1150, 600 );
    glEnd();

    // main block
    glColor3b(100,100,100);
    glRectf(720,500,1090,700);
    glColor3b(100,100,100);


    // Text inside Thought Bubble
    print("Hello there!! I'm your guide Riya",
          0, 0, 0, wp_tb_text, 750, 650, .09, .09, 1);
}
void drawTree(GLfloat tx, GLfloat ty,
              GLfloat sx, GLfloat sy)
{
    glPushMatrix();

    glTranslatef(tx, ty, 0);
    glScalef(sx, sy, 0);

    // Bark
    glBegin(GL_POLYGON);
    glColor3ub(86, 46, 11);
    glVertex2f(0, 0);
    glVertex2f(40, 0);
    glColor3ub(71, 36, 6);
    glVertex2f(35, 200);
    glVertex2f(5, 200);
    glEnd();

    // Tree
    drawCircle(20, 200, 5, 80, 10, 1, 1, 80);

    // Apples
    drawCircle(27, 194, 255, 0, 0, 1, 1.2, 5);
    drawCircle(-15, 170, 255, 0, 0, 1, 1.2, 5);
    drawCircle(47, 155, 255, 0, 0, 1, 1.2, 5);
    drawCircle(-2, 228, 255, 0, 0, 1, 1.2, 5);
    drawCircle(72, 216, 255, 0, 0, 1, 1.2, 5);

    glPopMatrix();
}

void bush()
{


    drawCircle(50, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(120, 0, 100, 200, 15, 1, 1, 80);

    drawCircle(150, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(210, 0, 100, 200, 15, 1, 1, 80);

    drawCircle(250, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(310, 0, 100, 200, 15, 1, 1, 80);

    drawCircle(350, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(410, 0, 100, 200, 15, 1, 1, 80);



    drawCircle(900, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(850, 0, 100, 200, 15, 1, 1, 80);

    drawCircle(1000, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(1070, 0, 100, 200, 15, 1, 1, 80);

    drawCircle(1100, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(1170, 0, 100, 200, 15, 1, 1, 80);

    drawCircle(1200, 40, 100, 200, 15, 1, 1, 80);
    drawCircle(1270, 0, 100, 200, 15, 1, 1, 80);

}

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1346,728);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Traffic simulation");

    /*call back functions*/
    glutDisplayFunc(mydisplay);
    glutKeyboardFunc(myKeyboard);
    glutMouseFunc(myMouse);


    myinit();
    glutMainLoop();
    return 0;
}
