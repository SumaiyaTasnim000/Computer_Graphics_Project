#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include <GL/gl.h>
#include <stdlib.h>
#define SPEED1 3.0
#define SPEED2 1.0
#include<math.h>
#define PI  3.14159265358979323846
using namespace std;                 //speed of traffic
float i=0.0;                        //movement of car
float m=0.0;                        //movement of clouds
float n=0.0;                        //movement of plane along x-axis
float o=0.0;                        //  and y-axis
int light=1;                        //1 for green-light, 0 for red-light
int day=1;                          //1 for day ,0 for night
int plane=0;                        //1 for plane
int comet=0;                        //1 for comet
int _move = 0.0;                    //movement of plane
int _move1 = 0.0;                   //movement of boat
//int _move2 = 0.0;                   //movement of sun
int _move3 = 0.0;                //movement of bird

void draw_pixel(GLint cx, GLint cy)
{
	glBegin(GL_POINTS);
		glVertex2i(cx,cy);
	glEnd();
}
void plotpixels(GLint h,GLint k, GLint x,GLint y)
{
	draw_pixel(x+h,y+k);
	draw_pixel(-x+h,y+k);
	draw_pixel(x+h,-y+k);
	draw_pixel(-x+h,-y+k);
	draw_pixel(y+h,x+k);
	draw_pixel(-y+h,x+k);
	draw_pixel(y+h,-x+k);
	draw_pixel(-y+h,-x+k);
}

void draw_circle(GLint h, GLint k, GLint r)
{
	GLint d=1-r, x=0, y=r;
	while(y>x)
	{
		plotpixels(h,k,x,y);
		if(d<0) d+=2*x+3;
		else
		{
			d+=2*(x-y)+5;
			--y;
		}
		++x;
	}
	plotpixels(h,k,x,y);
}
void draw_object()
{
int l;
if(day==1)
{
                                    //sky
glColor3f(0.0,0.9,0.9);
glBegin(GL_POLYGON);
    glVertex2f(0,380);
    glVertex2f(0,700);
    glVertex2f(1100,700);
    glVertex2f(1100,380);
glEnd();
glColor3f(0.7f,1.0f,1.0f);
glBegin(GL_POLYGON);
glVertex2f(1100,220);
glVertex2f(1100,0);
glVertex2f(0,0);
glVertex2f(0,220);
glEnd();

//glPushMatrix();                 //sun
//glTranslatef(0.0f,_move2,0.0f);
glBegin(GL_POLYGON);
	for(l=0;l<=35;l++)
{
		glColor3f(1.0,0.9,0.0);
		draw_circle(100,600,l);
}
glPopMatrix();
                        //cloud1
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(160+m,625,l);
	}
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(200+m,625,l);
		draw_circle(225+m,625,l);
	}
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(265+m,625,l);
	}
                                    //cloud2
	for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(370+m,615,l);
}
	for(l=0;l<=35;l++)
	{

		glColor3f(1.0,1.0,1.0);
		draw_circle(410+m,615,l);
		draw_circle(435+m,615,l);
		draw_circle(470+m,615,l);
	}

for(l=0;l<=20;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(500+m,615,l);
    }


}
else
{                                    //sky
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,380);
glVertex2f(0,700);
glVertex2f(1100,700);
glVertex2f(1100,380);
glEnd();
glColor3f(0.0,2.0,90.0);
glBegin(GL_POLYGON);
glVertex2f(1100,220);
glVertex2f(1100,0);
glVertex2f(0,0);
glVertex2f(0,220);
glEnd();


    //moon
int l;
	for(l=0;l<=35;l++)
	{
		glColor3f(1.0,1.0,1.0);
		draw_circle(100,625,l);
	}
//star1
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(575,653);
glVertex2f(570,645);
glVertex2f(580,645);
glVertex2f(575,642);
glVertex2f(570,650);
glVertex2f(580,650);
glEnd();
//star2
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(975,643);
glVertex2f(970,635);
glVertex2f(980,635);
glVertex2f(975,632);
glVertex2f(970,640);
glVertex2f(980,640);
glEnd();
                                    //star3
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(875,543);
glVertex2f(870,535);
glVertex2f(880,535);
glVertex2f(875,532);
glVertex2f(870,540);
glVertex2f(880,540);
glEnd();
                                    //star4
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(375,598);
glVertex2f(370,590);
glVertex2f(380,590);
glVertex2f(375,587);
glVertex2f(370,595);
glVertex2f(380,595);
glEnd();
                                    //star5
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(750,628);
glVertex2f(745,620);
glVertex2f(755,620);
glVertex2f(750,618);
glVertex2f(745,625);
glVertex2f(755,625);
glEnd();
                                    //star6
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(200,628);
glVertex2f(195,620);
glVertex2f(205,620);
glVertex2f(200,618);
glVertex2f(195,625);
glVertex2f(205,625);
glEnd();
                                    //star7
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex2f(500,543);
glVertex2f(495,535);
glVertex2f(505,535);
glVertex2f(500,532);
glVertex2f(495,540);
glVertex2f(505,540);
glEnd();


}






glPushMatrix();                      //plane
glTranslatef(_move, 0.0, 0.0);
glBegin(GL_POLYGON);
glColor3f(2.0f, 0.5f, 1.0f);
glVertex3f(200,575,0);
glVertex3f(230,538,0);
glVertex3f(200,500,0);
glVertex3f(0,500,0);
glVertex3f(0,575,0);
glVertex3f(200,575,0);
glEnd();
 ////Plane sides////
glBegin(GL_POLYGON);
glColor3f(1.0,0.0, 0.0);
glVertex3f(150,500,0);
glVertex3f(190,465,0);
glVertex3f(185,460,0);
glVertex3f(100,500,0);
glVertex3f(150,500,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,0.0, 0.0);
glVertex3f(45,640,0);
glVertex3f(60,575,0);
glVertex3f(20,575,0);
glVertex3f(30,640,0);
glVertex3f(45,640,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,0.0, 0.0);
glVertex3f(155,640,0);
glVertex3f(180,575,0);
glVertex3f(140,575,0);
glVertex3f(125,640,0);
glVertex3f(155,640,0);
glEnd();

//front glass//
glBegin(GL_POLYGON);
glColor3f(1.0f, 1.0f, 1.0f);
glVertex3f(200,575,0);
glVertex3f(230,538,0);
glVertex3f(200,538,0);
glVertex3f(200,575,0);
glEnd();
//plane windows//
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(20,550,0);
glVertex3f(20,535,0);
glVertex3f(10,535,0);
glVertex3f(10,550,0);
glVertex3f(20,550,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(50,550,0);
glVertex3f(50,535,0);
glVertex3f(40,535,0);
glVertex3f(40,550,0);
glVertex3f(50,550,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(80,550,0);
glVertex3f(80,535,0);
glVertex3f(70,535,0);
glVertex3f(70,550,0);
glVertex3f(80,550,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(110,550,0);
glVertex3f(110,535,0);
glVertex3f(100,535,0);
glVertex3f(100,550,0);
glVertex3f(110,550,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(140,550,0);
glVertex3f(140,535,0);
glVertex3f(130,535,0);
glVertex3f(130,550,0);
glVertex3f(140,550,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(170,550,0);
glVertex3f(170,535,0);
glVertex3f(160,535,0);
glVertex3f(160,550,0);
glVertex3f(170,550,0);
glEnd();
glPopMatrix();

glPushMatrix();                      //bird
glTranslatef(_move3, 0.0, 0.0);
glBegin(GL_POLYGON);


 glColor3f(1.4,0.9,0.0);       //bird's tail
glVertex3f(1100,630,0);
glVertex3f(1100,620,0);
glVertex3f(1090,623,0);
glVertex3f(1090,625,0);
glVertex3f(1100,630,0);
glEnd();
glBegin(GL_POLYGON);                  //bird's body
 glColor3f(0.4,0.8,0.0);
glVertex3f(1090,640,0);
glVertex3f(1090,610,0);
glVertex3f(1075,623,0);
glVertex3f(1075,625,0);
glVertex3f(1090,640,0);
glEnd();
glBegin(GL_POLYGON);                 //bird's wing
 glColor3f(0.4,0.8,0.0);
glVertex3f(1085,615,0);
glVertex3f(1080,595,0);
glVertex3f(1078,607,0);
glVertex3f(1075,600,0);
glVertex3f(1080,620,0);
glVertex3f(1085,615,0);
glEnd();
glBegin(GL_POLYGON);                 //bird's beak
 glColor3f(0.4,0.8,0.0);
glVertex3f(1062,628,0);
glVertex3f(1062,623,0);
glVertex3f(1055,627,0);
glVertex3f(1062,628,0);
glEnd();
glBegin(GL_POLYGON);                   //bird's head
	for(l=0;l<=7;l++)
{
		glColor3f(1.0,1.0,0.0);
		draw_circle(1070,625,l);
}
glPopMatrix();

                                    //road boundary
glColor3f(0.0,0.0,0.0);
glBegin(GL_POLYGON);
glVertex2f(0,210);
glVertex2f(0,220);
glVertex2f(1100,220);
glVertex2f(1100,210);
glEnd();
                                   //road
glColor3f(0.2,0.2,0.2);
glBegin(GL_POLYGON);
glVertex2f(0,220);
glVertex2f(0,380);
glVertex2f(1100,380);
glVertex2f(1100,220);
glEnd();


glBegin(GL_POLYGON);    // Building 1
glColor3f(1.0f, 0.5f, 0.0f);
glVertex3f(150,465,0);
glVertex3f(150,380,0);
glVertex3f(50,380,0);
glVertex3f(50,465,0);
glVertex3f(150,465,0);
glEnd();
glBegin(GL_POLYGON);    // Building 1 windows
glColor3f(1.0,1.0,1.0);
glVertex3f(90,400,0);
glVertex3f(90,390,0);
glVertex3f(70,390,0);
glVertex3f(70,400,0);
glVertex3f(90,400,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(130,400,0);
glVertex3f(130,390,0);
glVertex3f(110,390,0);
glVertex3f(110,400,0);
glVertex3f(130,400,0);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex3f(50,410,0);
glVertex3f(150,410,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(90,430,0);
glVertex3f(90,420,0);
glVertex3f(70,420,0);
glVertex3f(70,430,0);
glVertex3f(90,430,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(130,430,0);
glVertex3f(130,420,0);
glVertex3f(110,420,0);
glVertex3f(110,430,0);
glVertex3f(130,430,0);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex3f(50,440,0);
glVertex3f(150,440,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(90,460,0);
glVertex3f(90,450,0);
glVertex3f(70,450,0);
glVertex3f(70,460,0);
glVertex3f(90,460,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(130,460,0);
glVertex3f(130,450,0);
glVertex3f(110,450,0);
glVertex3f(110,460,0);
glVertex3f(130,460,0);
glEnd();
glBegin(GL_POLYGON);    // Building 2
glColor3f(0.2f, 1.0f, 0.5f);
glVertex3f(270,440,0);
glVertex3f(270,380,0);
glVertex3f(170,380,0);
glVertex3f(170,440,0);
glVertex3f(270,440,0);
glEnd();

glBegin(GL_POLYGON);    // Building 2 windows
glColor3f(1.0,1.0,1.0);
glVertex3f(210,400,0);
glVertex3f(210,390,0);
glVertex3f(190,390,0);
glVertex3f(190,400,0);
glVertex3f(210,400,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(250,400,0);
glVertex3f(250,390,0);
glVertex3f(230,390,0);
glVertex3f(230,400,0);
glVertex3f(250,400,0);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex3f(170,410,0);
glVertex3f(270,410,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(210,430,0);
glVertex3f(210,420,0);
glVertex3f(190,420,0);
glVertex3f(190,430,0);
glVertex3f(210,430,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(250,430,0);
glVertex3f(250,420,0);
glVertex3f(230,420,0);
glVertex3f(230,430,0);
glVertex3f(250,430,0);
glEnd();


glBegin(GL_POLYGON);    // Building 3
glColor3f(1.0f, 0.0f, 1.0f);
glVertex3f(450,440,0);
glVertex3f(450,380,0);
glVertex3f(350,380,0);
glVertex3f(350,440,0);
glVertex3f(450,440,0);
glEnd();

glBegin(GL_POLYGON);    // Building 3 windows
glColor3f(1.0,1.0,1.0);
glVertex3f(390,400,0);
glVertex3f(390,390,0);
glVertex3f(370,390,0);
glVertex3f(370,400,0);
glVertex3f(390,400,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(430,400,0);
glVertex3f(430,390,0);
glVertex3f(410,390,0);
glVertex3f(410,400,0);
glVertex3f(430,400,0);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex3f(350,410,0);
glVertex3f(450,410,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(390,430,0);
glVertex3f(390,420,0);
glVertex3f(370,420,0);
glVertex3f(370,430,0);
glVertex3f(390,430,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(430,430,0);
glVertex3f(430,420,0);
glVertex3f(410,420,0);
glVertex3f(410,430,0);
glVertex3f(430,430,0);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex3f(350,440,0);
glVertex3f(450,440,0);
glEnd();
glBegin(GL_POLYGON);    // Building 4
glColor3f(0.7f, 0.5f, 0.0f);
glVertex3f(900,465,0);
glVertex3f(900,380,0);
glVertex3f(800,380,0);
glVertex3f(800,465,0);
glVertex3f(150,465,0);
glEnd();
glBegin(GL_POLYGON);    // Building 4 windows
glColor3f(1.0,1.0,1.0);
glVertex3f(840,400,0);
glVertex3f(840,390,0);
glVertex3f(820,390,0);
glVertex3f(820,400,0);
glVertex3f(840,400,0);
glEnd();

glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(880,400,0);
glVertex3f(880,390,0);
glVertex3f(860,390,0);
glVertex3f(860,400,0);
glVertex3f(880,400,0);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex3f(800,410,0);
glVertex3f(900,410,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(840,430,0);
glVertex3f(840,420,0);
glVertex3f(820,420,0);
glVertex3f(820,430,0);
glVertex3f(840,430,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(880,430,0);
glVertex3f(880,420,0);
glVertex3f(860,420,0);
glVertex3f(860,430,0);
glVertex3f(880,430,0);
glEnd();
glBegin(GL_LINES);
glColor3f(1.0,1.0,1.0);
glVertex3f(800,440,0);
glVertex3f(900,440,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(840,460,0);
glVertex3f(840,450,0);
glVertex3f(820,450,0);
glVertex3f(820,460,0);
glVertex3f(840,460,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,1.0);
glVertex3f(880,460,0);
glVertex3f(880,450,0);
glVertex3f(860,450,0);
glVertex3f(860,460,0);
glVertex3f(880,460,0);
glEnd();



glPushMatrix();                 //Boat
glTranslatef(_move1,0.0f,0.0f);
glBegin(GL_POLYGON);
glColor3f(0.4,0.0,0.0);
glVertex3f(290,110,0);
glVertex3f(250,50,0);
glVertex3f(40,50,0);
glVertex3f(0,110,0);
glVertex3f(290,110,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(0.2,1.0,1.0);
glVertex3f(250,50,0);
glVertex3f(250,40,0);
glVertex3f(40,40,0);
glVertex3f(40,50,0);
glVertex3f(250,50,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,1.0,0.4);
glVertex3f(210,150,0);
glVertex3f(250,110,0);
glVertex3f(40,110,0);
glVertex3f(80,150,0);
glVertex3f(210,150,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.4);
glVertex3f(110,140,0);
glVertex3f(110,120,0);
glVertex3f(90,120,0);
glVertex3f(90,140,0);
glVertex3f(110,140,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.4);
glVertex3f(150,140,0);
glVertex3f(150,120,0);
glVertex3f(130,120,0);
glVertex3f(130,140,0);
glVertex3f(150,140,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.4);
glVertex3f(190,140,0);
glVertex3f(190,120,0);
glVertex3f(170,120,0);
glVertex3f(170,140,0);
glVertex3f(190,140,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,0.5,0.0);
glVertex3f(145,160,0);
glVertex3f(190,150,0);
glVertex3f(100,150,0);
glVertex3f(145,160,0);
glEnd();

glBegin(GL_LINES);
glColor3f(0.0,0.0,0.0);
glVertex3f(145,160,0);
glVertex3f(145,205,0);
glEnd();
glBegin(GL_POLYGON);
glColor3f(1.0,0.0,0.0);
glVertex3f(145,190,0);
glVertex3f(190,177,0);
glVertex3f(145,165,0);
glVertex3f(145,190,0);
glEnd();
glPopMatrix();


 /*      glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,160);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,160);
	glEnd();
	glColor3f(0.7,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();
	for(l=0;l<=20;l++)
	{
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		glColor3f(0.0,0.0,0.0);
		draw_circle(1065,375,l);
	}      */                     //car 1 red
glColor3f(0.2,0.9,0.5);
glBegin(GL_POLYGON);
glVertex2f(25+i,270);
glVertex2f(25+i,345);
glVertex2f(75+i,420);
glVertex2f(175+i,420);
glVertex2f(200+i,345);
glVertex2f(250+i,335);
glVertex2f(250+i,270);
glEnd();
                                    //windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(35+i,345);
glVertex2f(80+i,410);
glVertex2f(115+i,410);
glVertex2f(115+i,345);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(125+i,345);
glVertex2f(125+i,410);
glVertex2f(170+i,410);
glVertex2f(190+i,345);
glEnd();
for(l=0;l<20;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(75+i,270,l);
	draw_circle(175+i,270,l);
   }
                                    //car2 blue
glColor3f(9.0,1.0,7.0);
glBegin(GL_POLYGON);
glVertex2f(-470+i,275);
glVertex2f(-470+i,337);
glVertex2f(-400+i,350);
glVertex2f(-372+i,400);
glVertex2f(-210+i,400);
glVertex2f(-180+i,350);
glVertex2f(-135+i,350);
glVertex2f(-110+i,275);
glEnd();
                                    //windows
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
glVertex2f(-400+i,350);
glVertex2f(-364+i,390);
glVertex2f(-300+i,390);
glVertex2f(-300+i,350);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_POLYGON);
    glVertex2f(-290+i,350);
    glVertex2f(-290+i,390);
    glVertex2f(-220+i,390);
    glVertex2f(-192+i,350);
glEnd();
for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(-350+i,275,l);
	draw_circle(-200+i,275,l);
   }
glColor3f(0.3,0.7,0.7); //purple bus
glBegin(GL_POLYGON);
glVertex2f(350+i,270);
glVertex2f(350+i,450);
glVertex2f(722+i,450);
glVertex2f(750+i,350);
glVertex2f(750+i,270);
glEnd();
glColor3f(1.0,1.0,1.0); //window
glBegin(GL_POLYGON);
glVertex2f(650+i,395);
glVertex2f(650+i,435);
glVertex2f(720+i,435);
glVertex2f(730+i,395);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(550+i,395);
glVertex2f(550+i,435);
glVertex2f(625+i,435);
glVertex2f(625+i,395);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(450+i,395);
glVertex2f(450+i,435);
glVertex2f(525+i,435);
glVertex2f(525+i,395);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_POLYGON);
glVertex2f(375+i,395);
glVertex2f(375+i,435);
glVertex2f(425+i,435);
glVertex2f(425+i,395);
glEnd();
for(l=0;l<30;l++)
   {
	glColor3f(0.0,0.0,0.0);
	draw_circle(450+i,275,l);
	draw_circle(625+i,275,l);
   }

                                       //signal
glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
		glVertex2f(1060,220);
		glVertex2f(1060,350);
		glVertex2f(1070,350);
		glVertex2f(1070,220);
	glEnd();
glColor3f(0.3,0.7,0.7);
	glBegin(GL_POLYGON);
		glVertex2f(1040,350);
		glVertex2f(1040,500);
		glVertex2f(1090,500);
		glVertex2f(1090,350);
	glEnd();
for(l=0;l<=20;l++)
	{
 //glColor3f(1.0,0.0,0.0);
       // draw_circle(1065,475,l);
		glColor3f(1.0,1.0,0.0);
		draw_circle(1065,425,l);
		//glColor3f(1.0,0.0,0.0);
		//draw_circle(1065,375,l);
	}


                                      //tree
   glBegin(GL_POLYGON);
glColor3f(0.6,0.298,0.0);
glVertex3f(70,220,0);
glVertex3f(70,300,0);
glVertex3f(85,300,0);
glVertex3f(85,220,0);
glEnd();

   glBegin(GL_POLYGON);
 glColor3f(0.4,0.8,0.0);
glVertex3f(25,300,0);
glVertex3f(77.5,350,0);
glVertex3f(130,300,0);
//glVertex3f(85,220,0);
glEnd();

  glBegin(GL_POLYGON);
glColor3f(0.0,0.4,0.0);
glVertex3f(27,330,0);
glVertex3f(77.5,400,0);
glVertex3f(128,330,0);
//glVertex3f(85,220,0);
glEnd();


//tree 2
   glBegin(GL_POLYGON);
glColor3f(0.6,0.298,0.0);
glVertex3f(220,220,0);
glVertex3f(220,300,0);
glVertex3f(235,300,0);
glVertex3f(235,220,0);
glEnd();

   glBegin(GL_POLYGON);
 glColor3f(0.4,0.8,0.0);
glVertex3f(190,300,0);
glVertex3f(227.5,350,0);
glVertex3f(265,300,0);
//glVertex3f(85,220,0);
glEnd();

  glBegin(GL_POLYGON);
glColor3f(0.0,0.4,0.0);
glVertex3f(190,330,0);
glVertex3f(227.5,430,0);
glVertex3f(265,330,0);
//glVertex3f(85,220,0);
glEnd();


//tree 3
   glBegin(GL_POLYGON);
glColor3f(0.6,0.298,0.0);
glVertex3f(620,220,0);
glVertex3f(620,300,0);
glVertex3f(635,300,0);
glVertex3f(635,220,0);
glEnd();

   glBegin(GL_POLYGON);
 glColor3f(0.4,0.8,0.0);
glVertex3f(590,300,0);
glVertex3f(627.5,350,0);
glVertex3f(665,300,0);
//glVertex3f(85,220,0);
glEnd();

  glBegin(GL_POLYGON);
glColor3f(0.0,0.4,0.0);
glVertex3f(590,330,0);
glVertex3f(627.5,480,0);
glVertex3f(665,330,0);
//glVertex3f(85,220,0);
glEnd();

//tree 4
   glBegin(GL_POLYGON);
glColor3f(0.6,0.298,0.0);
glVertex3f(900,220,0);
glVertex3f(900,300,0);
glVertex3f(915,300,0);
glVertex3f(915,220,0);
glEnd();

   glBegin(GL_POLYGON);
 glColor3f(0.4,0.8,0.0);
glVertex3f(870,300,0);
glVertex3f(907.5,350,0);
glVertex3f(945,300,0);
//glVertex3f(85,220,0);
glEnd();

  glBegin(GL_POLYGON);
glColor3f(0.0,0.4,0.0);
glVertex3f(870,330,0);
glVertex3f(907.5,480,0);
glVertex3f(945,330,0);
//glVertex3f(85,220,0);
glEnd();

//tree 4
   glBegin(GL_POLYGON);
glColor3f(0.6,0.298,0.0);
glVertex3f(425,220,0);
glVertex3f(425,300,0);
glVertex3f(440,300,0);
glVertex3f(440,220,0);
glEnd();

   glBegin(GL_POLYGON);
 glColor3f(0.4,0.8,0.0);
glVertex3f(395,300,0);
glVertex3f(432.5,350,0);
glVertex3f(470,300,0);
//glVertex3f(85,220,0);
glEnd();

  glBegin(GL_POLYGON);
glColor3f(0.0,0.4,0.0);
glVertex3f(395,330,0);
glVertex3f(432.5,450,0);
glVertex3f(470,330,0);
//glVertex3f(85,220,0);
glEnd();












glFlush();


}

void traffic_light()
{
	int l;
if(light==1)
	  {
for(l=0;l<=20;l++)
		{
  glColor3f(0.7,0.0,0.0);
		draw_circle(1065,475,l);
	glColor3f(0.0,1.0,0.0);
		draw_circle(1065,375,l);
		}
	  }
	else
	  {
for(l=0;l<=20;l++)
		{
		glColor3f(1.0,0.0,0.0);
		draw_circle(1065,475,l);
	                                   // glColor3f(0.0,0.0,0.0);
                                    //draw_circle(1065,425,l);
		glColor3f(0.0,0.1,0.0);
		draw_circle(1065,375,l);
		}
	  }
}
void idle()
{
glClearColor(1.0,1.0,1.0,1.0);
if(light==0 && (i>=330 && i<=750))
 {
	 i+=SPEED1/10;
     m+=SPEED2/10;
	n-=2;
	 o+=0.2;
	//c+=2;
 }
if(light==0 && (i>=830 && i<=1100))
 {
	 i+=SPEED1/10;
      m+=SPEED2/10;
	n-=2;
	 o+=0.2;
//	c+=2;
 }
if(light==0 && (i>=1200 && i<=1620))
 {
	 i+=SPEED1/10;
      m+=SPEED2/10;
	n-=2;
	 o+=0.2;
//	c+=2;
 }
if(light==0)
 {
	 i=i;
	  m+=SPEED2/10;
	n-=2;
	 o+=0.2;
//	c+=2;
 }
else
 {
     i+=SPEED1/10;
      m+=SPEED2/10;
	n-=2;
	 o+=0.2;
//	c+=2;
 }
if(i>1630)
	 i=0.0;
if(m>1100)
	 m=0.0;
if( o>75)
 {
	plane=0;
 }
//if(c>500)
 {
	comet=0;
 }
glutPostRedisplay();
}
void keyboardFunc( unsigned char key, int x, int y )
{
switch( key )
    {
case 'g':
case 'G':
light=1;
break;
	case 'r':
	case 'R':
		light=0;
		break;
case 'd':
	case 'D':
		day=1;
		break;
	case 'n':
case 'N':
		day=0;
		break;
    };
}
void main_menu(int index)
{
	switch(index)
	{
	case 1:
	if(index==1)
	 {
	plane=1;
		 o=n=0.0;
	 }
	break;
	case 2:
	if(index==2)
	 {
		comet=1;
//		 c=0.0;
	 }
	break;
	case 3:
        if(index==3)
        {
            exit(0);
        }
    break;
	}
}
void update(int value)
{

    _move +=5;
    if(_move-1> 1100)
    {
        _move = -1;
    }

    _move1 +=1;
    if(_move1-1> 1100)
    {
        _move1 = -1;
    }

    /*_move2 +=1;
    if(_move2-1> 700)
    {
        _move2 = -1;
    }
*/
    _move3 -=1;
    if(_move3+1 < -1100)
    {
        _move3 = 1;
    }
   glutPostRedisplay();

    glutTimerFunc(25, update, 0);
}
void myinit()
{
glClearColor(1.0,1.0,1.0,1.0);
glColor3f(0.0,0.0,1.0);
glPointSize(2.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,1100.0,0.0,700.0);
}
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
draw_object();
traffic_light();
glFlush();
}
int main(int argc,char*argv[])
{
int c_menu;

	printf("Press 'r'/'R' to change the signal light to Red\n");
	printf("Press 'g'/'G' to change the signal light to Green\n");
	printf("Press 'd'/'D' to make it Day Time                \n");
	printf("Press 'n'/'N' to make it Night Time              \n");

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(1100,700);
	glutInitWindowPosition(250,0);
	glutCreateWindow("Dynamic City Simulation");
	myinit();
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyboardFunc);
	c_menu=glutCreateMenu(main_menu);
	//glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutTimerFunc(25, update, 0);
	glutMainLoop();
	return 0;
}
