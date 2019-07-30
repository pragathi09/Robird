#include<GL/glut.h> 
#include<stdio.h>
#include<time.h>
GLfloat mat_ambient[][6]={{0.9,0.9,0.9},{9.0,7.0,0.0},{0.5,0.8,2.0},{1.0,0.0,0.0},{1.0,1.0,1.0},{1.0,1.0,0.0}};
GLfloat mat_diffuse[]={0.5,0.5,0.5,1.0};
GLfloat mat_specular[]={1.0,1.0,1.0,1.0};
const GLfloat mat_shininess[]={50.0};
GLfloat light_intensity[]={0.7,0.7,0.7,1.0};
GLfloat light_position[][4]={{2.0,6.0,3.0,0.0},{10.0,10.0,0.0,0.0}};
int i,x=0,y=0;
int frameNumber = 0;
float rotx=0.5,zoom=0.0;
static int m,s,a,b,value=0,window;
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=2;
static GLdouble viewer[]={10.0,10.0,40.0};
void init()
{
glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);
glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);
glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
glLightfv(GL_LIGHT0,GL_DIFFUSE,light_intensity);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,400.0,0.0,400.0,0.0,400.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluLookAt(0.0,40.0,70.0,10.0,35.0,0.0,0.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
int posX =-50, posY =0, posZ = 0;
int p,q,r;
int zoomin=2;
int f = 0;
//road
void road()
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.2,0.2,0.2);
glBegin(GL_QUADS);
glVertex3f(180.0,50.0,0.0);
glVertex3f(190.0,100.0,0.0);
glVertex3f(200.0,100.0,0.0);
glVertex3f(220.0,50.0,0.0);
glEnd();
glColor3f(0.2,0.2,0.2);
glBegin(GL_QUADS);
glVertex3f(-100.0,200.0,0.0);
glVertex3f(500.0,200.0,0.0);
glVertex3f(500.0,220.0,0.0);
glVertex3f(-100.0,220.0,0.0);
glEnd();
glColor3f(0.2,0.2,0.2);
glBegin(GL_QUADS);
glVertex3f(200.0,200.0,0.0);
glVertex3f(150.0,0.0,0.0);
glVertex3f(280.0,0.0,0.0);
glVertex3f(240.0,200.0,0.0);
glEnd();
glColor3f(0.2,0.2,0.2);
glBegin(GL_QUADS);
glVertex3f(-100.0,220.0,0.0);
glVertex3f(205.0,220.0,0.0);
glVertex3f(234.0,220.0,0.0);
glVertex3f(230.0,240.0,0.0);
glEnd();
//glFlush();
}
//buildings
void buildings() 
{
glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
glPushMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[0]);
glTranslated(310.0,300.0,0.0);
glRotated(280.0,0,1,0);
glScaled(1.0,2.0,1.0);
glutSolidCube(70.0);
glPopMatrix();
glPushMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[2]);
glTranslated(90.0,230.0,0.0);
glRotated(280.0,0,1,0);
glScaled(1.0,1.0,1.0);
glutSolidCube(105.0);
glPopMatrix();
  glDisable(GL_LIGHTING);
  glDisable(GL_LIGHT0);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_NORMALIZE);
//glFlush();
}
//pak
void pak_build()
{
glColor3f(0.3,0.3,0.3);
glBegin(GL_QUADS);
glVertex3f(255.0,410.0,0.0);
glVertex3f(255.0,190.0,0.0);
glVertex3f(375.0,191.0,0.0);
glVertex3f(375.0,410.0,0.0);
glEnd();
glColor3f(0.0,0.0,0.5);
glBegin(GL_QUADS);
glVertex3f(275.0,390.0,0.0);
glVertex3f(275.0,300.0,0.0);
glVertex3f(355.0,300.0,0.0);
glVertex3f(355.0,390.0,0.0);
glEnd();
glColor3f(0.6,0.4,0.12);
glBegin(GL_QUADS);
glVertex3f(305.0,260.0,0.0);
glVertex3f(305.0,190.0,0.0);
glVertex3f(335.0,191.0,0.0);
glVertex3f(335.0,260.0,0.0);
glEnd();
}
void tree()
{
int k,p;
for(k=0;k<420;k+=40)
{
glColor3f(1.0,0.5,0.0);
glBegin(GL_QUADS);
glVertex3f(20.0+k,320.0,0.0);
glVertex3f(20.0+k,270.0,0.0);
glVertex3f(30.0+k,270.0,0.0);
glVertex3f(30.0+k,320.0,0.0);
glEnd();
}
for(p=0;p<420;p+=40){
glColor3f(0.0,0.7,0.0);
glBegin(GL_TRIANGLES);
glVertex3f(25.0+p,390.0,0.0);
glVertex3f(0.0+p,320.0,0.0);
glVertex3f(50.0+p,320.0,0.0);
glEnd();
}
}
void fence()
{
int i;
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex3f(0.0,280.0,0.0);
glVertex3f(420.0,280.0,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f(0.0,310.0,0.0);
glVertex3f(420.0,310.0,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f(0.0,300.0,0.0);
glVertex3f(420.0,300.0,0.0);
glEnd();
for(i=0;i<420;i+=5)
{glBegin(GL_LINES);
glVertex3f(0.0+i,310.0,0.0);
glVertex3f(20.0+i,280.0,0.0);
glEnd();
}
for(i=0;i<420;i+=5)
{glBegin(GL_LINES);
glVertex3f(30.0+i,310.0,0.0);
glVertex3f(20.0+i,280.0,0.0);
glEnd();
}
}

//windows
void windows(double c1,double c2,double c3)
{
int k=0;
for(k=0;k<120;k+=20)
{
glColor3f(0.8-c1,0.8-c2,0.0+c3);
glBegin(GL_QUADS);
glVertex3f(295.0,350.0-k,0.0);
glVertex3f(305.0,350.0-k,0.0);
glVertex3f(305.0,360.0-k,0.0);
glVertex3f(295.0,360.0-k,0.0);
glEnd();
glColor3f(0.8-c1,0.8-c2,0.0+c3);
glBegin(GL_QUADS);
glVertex3f(315.0,350.0-k,0.0);
glVertex3f(325.0,350.0-k,0.0);
glVertex3f(325.0,360.0-k,0.0);
glVertex3f(315.0,360.0-k,0.0);
glEnd();
glColor3f(0.8-c1,0.8-c2,0.0+c3);
glBegin(GL_QUADS);
glVertex3f(335.0,350.0-k,0.0);
glVertex3f(345.0,350.0-k,0.0);
glVertex3f(345.0,360.0-k,0.0);
glVertex3f(335.0,360.0-k,0.0);
glEnd();
}
glColor4f(0.8-c1,0.8-c2,0.0+c3,0.5);
glBegin(GL_QUADS);
glVertex3f(65.0,195.0,0.0);
glVertex3f(145.0,195.0,0.0);
glVertex3f(145.0,265.0,0.0);
glVertex3f(65.0,265.0,0.0);
glEnd();
//glFlush();
}
void grass_pak()
{
glColor3f(0.0,0.5,0.0);
glBegin(GL_QUADS);
glVertex3f(0.0,270.0,0.0);
glVertex3f(0.0,0.0,0.0);
glVertex3f(500.0,0.0,0.0);
glVertex3f(500.0,270.0,0.0);
glEnd();
}
void grass_farm()
{
glColor3f(0.5,0.35,0.05);
glBegin(GL_QUADS);
glVertex3f(0.0,210.0,0.0);
glVertex3f(0.0,0.0,0.0);
glVertex3f(700.0,0.0,0.0);
glVertex3f(700.0,210.0,0.0);
glEnd();
}
void strip_farm()
{
for(i=0;i<700;i+=120)
{
glColor3f(0.0,0.5,0.0);
glBegin(GL_QUADS);
glVertex3f(0.0+i,210.0,0.0);
glVertex3f(0.0+i,0.0,0.0);
glVertex3f(5.0+i,0.0,0.0);
glVertex3f(5.0+i,210.0,0.0);
glEnd();
}
glColor3f(0.0,0.5,0.0);
glBegin(GL_QUADS);
glVertex3f(0.0,105.0,0.0);
glVertex3f(0.0,110,0.0);
glVertex3f(500.0,110.0,0.0);
glVertex3f(500.0,105,0.0);
glEnd();
}
void flower()
{int i,j;
for(i=0;i<700;i=i+35)
for(j=0;j<700;j=j+50)
{
glColor3f(0.9,0.8,0.4);
glBegin(GL_QUADS);
glVertex3f(30.0+j,200.0-i,0.0);
glVertex3f(30.0+j,190.0-i,0.0);
glVertex3f(40.0+j,190.0-i,0.0);
glVertex3f(40.0+j,200.0-i,0.0);
glEnd();
}
for(i=0;i<700;i=i+35)
for(j=0;j<700;j=j+50)
{
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);
glVertex3f(35.0+j,190.0-i,0.0);
glVertex3f(35.0+j,180.0-i,0.0);
glEnd();}
for(i=0;i<700;i=i+35)
for(j=0;j<700;j=j+50)
{
glColor3f(0.0,1.0,0.0);
glBegin(GL_LINES);
glVertex3f(30.0+j,187.0-i,0.0);
glVertex3f(35.0+j,180.0-i,0.0);
glVertex3f(35.0+j,180.0-i,0.0);
glVertex3f(40.0+j,187.0-i,0.0);
glEnd();}
for(i=0;i<700;i=i+35)
for(j=0;j<700;j=j+50)
{
glColor3f(1.0,0.0,0.0);
glPushMatrix();
glTranslated(35.0+j,195.0-i,0.0);
glutSolidSphere(4,4,4);
glPopMatrix();}
}
//grass
void grass()
{
glColor3f(0.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex3f(-100.0,200.0,0.0);
glVertex3f(200.0,200.0,0.0);
glVertex3f(150.0,0.0,0.0);
glVertex3f(-100.0,0.0,0.0);
glEnd();
glColor3f(0.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex3f(280.0,0.0,0.0);
glVertex3f(240.0,200.0,0.0);
glVertex3f(500.0,200.0,0.0);
glVertex3f(500.0,0.0,0.0);
glEnd();
glColor3f(0.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex3f(-100.0,220.0,0.0);
glVertex3f(205.0,220.0,0.0);
glVertex3f(210.0,240.0,0.0);
glVertex3f(-100.0,240.0,0.0);
glEnd();
glColor3f(0.0,1.0,0.0);
glBegin(GL_QUADS);
glVertex3f(234.0,220.0,0.0);
glVertex3f(230.0,240.0,0.0);
glVertex3f(500.0,240.0,0.0);
glVertex3f(500.0,220.0,0.0);
glEnd();
//glFlush();
}
//sun
void sun()
{
glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[1]);
glPushMatrix();
glTranslated(380.0,370.0,0.0);
glScaled(1.0,2.0,1.0);
glutSolidSphere(20.0,50,50);
glPopMatrix();
glDisable(GL_LIGHTING);
  glDisable(GL_LIGHT0);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_NORMALIZE);
//glFlush();
}
//bird
void birdup()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex3f(93.0,321,45.0);
glVertex3f(133.0,321.0,45.0);
glVertex3f(111.0,333,45.0);
glVertex3f(86.0,333.0,45.0);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex3f(111.0,333,45.0);
glVertex3f(86.0,333.0,45.0);
glVertex3f(60.0,350.0,45.0);
glEnd();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[3]);
glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
glPushMatrix();
glTranslated(110.0,310.0,45.0);
glScaled(2.0,1.0,1.0);
glutSolidSphere(15.0,50,50);
glPopMatrix();
glPushMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[5]);
glTranslated(149.0,310.0,45.0);
glRotated(90.0,0,1,0);
glScaled(1.0,0.3,1.0);
glutSolidCone(10.0,10.0,10.0,10.0);
glPopMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[4]);
glPushMatrix();
glTranslated(140.0,310.0,45.0);
glutSolidSphere(10.0,50,50);
glPopMatrix();
glDisable(GL_LIGHTING);
  glDisable(GL_LIGHT0);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_NORMALIZE);
glBegin(GL_QUADS);
glVertex3f(95.0,315,45.0);
glVertex3f(130.0,315.0,45.0);
glVertex3f(108.0,330.0,45.0);
glVertex3f(83.0,330.0,45.0);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_TRIANGLES);
glVertex3f(108.0,330.0,45.0);
glVertex3f(83.0,330.0,45.0);
glVertex3f(55.0,347.0,45.0);
glEnd();

}

void birddown()
{
glColor3f(0.5,0.5,0.5);
glBegin(GL_QUADS);
glVertex3f(93.0,321.0,45.0);
glVertex3f(133.0,321.0,45.0);
glVertex3f(111.0,309.0,45.0);
glVertex3f(86.0,309.0,45.0);
glEnd();
glColor3f(0.5,0.5,0.5);
glBegin(GL_TRIANGLES);
glVertex3f(111.0,309.0,45.0);
glVertex3f(86.0,309.0,45.0);
glVertex3f(60.0,292.0,45.0);
glEnd();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[3]);
glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
  glShadeModel(GL_SMOOTH);
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_NORMALIZE);
glPushMatrix();
glTranslated(110.0,310.0,45.0);
glScaled(2.0,1.0,1.0);
glutSolidSphere(15.0,50,50);
glPopMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[5]);
glPushMatrix();
glTranslated(149.0,310.0,45.0);
glRotated(90.0,0,1,0);
glScaled(1.0,0.3,1.0);
glutSolidCone(10.0,10.0,10.0,10.0);
glPopMatrix();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[4]);
glPushMatrix();
glTranslated(140.0,310.0,45.0);
glutSolidSphere(10.0,50,50);
glPopMatrix();
  glDisable(GL_LIGHTING);
  glDisable(GL_LIGHT0);
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_NORMALIZE);
glColor3f(0.5,0.5,0.5);
glBegin(GL_QUADS);
glVertex3f(95.0,315.0,45.0);
glVertex3f(130.0,315.0,45.0);
glVertex3f(108.0,300.0,45.0);
glVertex3f(83.0,300.0,45.0);
glEnd();
glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient[3]);
glColor3f(0.5,0.5,0.5);
glBegin(GL_TRIANGLES);
glVertex3f(108.0,300.0,45.0);
glVertex3f(83.0,300.0,45.0);
glVertex3f(55.0,283.0,45.0);
glEnd();
}
//lamps
void lamps(double color)
{
int p,q,r;
for(p=0,q=0,r=0;p<180;p+=60,q+=15,r+=3)
{
glColor3f(0.3,0.3,0.3);
glPushMatrix();
glTranslated(295.0-q,80.0+p,0.0);
glScaled(1.0,8.0-r,1.0);
glutSolidCube(10.0);
glPopMatrix();
glColor3f(1.0,1.0,1.0-color);
glPushMatrix();
glTranslated(295.0-q,100.0+p,0.0);
glutSolidSphere(17.0-r,50,50);
glPopMatrix();
}
for(p=0,q=0,r=0;p<180;p+=60,q+=15,r+=3)
{
glColor3f(0.3,0.3,0.3);
glPushMatrix();
glTranslated(150.0+q,80.0+p,0.0);
glScaled(1.0,8.0-r,1.0);
glutSolidCube(10.0);
glPopMatrix();
glColor3f(1.0,1.0,1.0-color);
glPushMatrix();
glTranslated(150.0+q,100.0+p,0.0);
glutSolidSphere(17.0-r,50,50);
glPopMatrix();
}
for(p=0;p<70;p+=60)
{
glColor3f(0.3,0.3,0.3);
glPushMatrix();
glTranslated(325.0+p,200.0,0.0);
glScaled(1.0,2.0,1.0);
glutSolidCube(10.0);
glPopMatrix();
glColor3f(1.0,1.0,1.0-color);
glPushMatrix();
glTranslated(325.0+p,220.0,0.0);
glutSolidSphere(11.0,50,50);
glPopMatrix();
}
}
void strip()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex3f(215.0,60.0,0.0);
glVertex3f(213.0,30.0,0.0);
glVertex3f(225.0,30.0,0.0);
glVertex3f(223.0,60.0,0.0);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex3f(215.0,120.0,0.0);
glVertex3f(213.0,90.0,0.0);
glVertex3f(225.0,90.0,0.0);
glVertex3f(223.0,120.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(215.0,175.0,0.0);
glVertex3f(213.0,150.0,0.0);
glVertex3f(225.0,150.0,0.0);
glVertex3f(223.0,175.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(216.0,220.0,0.0);
glVertex3f(214.0,200.0,0.0);
glVertex3f(224.0,200.0,0.0);
glVertex3f(223.0,220.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(216.0,240.0,0.0);
glVertex3f(214.0,234.0,0.0);
glVertex3f(224.0,234.0,0.0);
glVertex3f(223.0,240.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(30.0,213.0,0.0);
glVertex3f(30.0,208.0,0.0);
glVertex3f(47.0,208.0,0.0);
glVertex3f(47.0,213.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(73.0,213.0,0.0);
glVertex3f(73.0,208.0,0.0);
glVertex3f(90.0,208.0,0.0);
glVertex3f(90.0,213.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(110.0,213.0,0.0);
glVertex3f(110.0,208.0,0.0);
glVertex3f(127.0,208.0,0.0);
glVertex3f(127.0,213.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(153.0,213.0,0.0);
glVertex3f(153.0,208.0,0.0);
glVertex3f(170.0,208.0,0.0);
glVertex3f(170.0,213.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(253.0,213.0,0.0);
glVertex3f(253.0,208.0,0.0);
glVertex3f(270.0,208.0,0.0);
glVertex3f(270.0,213.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(300.0,213.0,0.0);
glVertex3f(300.0,208.0,0.0);
glVertex3f(317.0,208.0,0.0);
glVertex3f(317.0,213.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(343.0,213.0,0.0);
glVertex3f(343.0,208.0,0.0);
glVertex3f(360.0,208.0,0.0);
glVertex3f(360.0,213.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(383.0,213.0,0.0);
glVertex3f(383.0,208.0,0.0);
glVertex3f(400.0,208.0,0.0);
glVertex3f(400.0,213.0,0.0);
glEnd();
}
void cloud()
{
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslated(300.0,370.0,0.0);
glScaled(3.0,0.1,1.0);
glutSolidSphere(20.0,60.0,50);
glPopMatrix();
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslated(250.0,365.0,0.0);
glScaled(3.0,0.1,1.0);
glutSolidSphere(20.0,60.0,50);
glPopMatrix();
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslated(100.0,370.0,0.0);
glScaled(3.0,0.1,1.0);
glutSolidSphere(20.0,60.0,50);
glPopMatrix();
}

void sky()
{
glClearColor(0.0,0.5,0.9,0.0);
}
void bridge()
{
glColor3f(1.0,0.1,0.1);
glBegin(GL_TRIANGLES);
glVertex3f(240.0,230.0,0.0);
glVertex3f(270.0,230.0,0.0);
glVertex3f(255.0,330.0,0.0);
glEnd();
glColor3f(1.0,0.1,0.1);
glBegin(GL_TRIANGLES);
glVertex3f(170.0,230.0,0.0);
glVertex3f(200.0,230.0,0.0);
glVertex3f(185.0,330.0,0.0);
glEnd();
glColor3f(0.1,0.1,0.1);
glBegin(GL_QUADS);
glVertex3f(192.0,280.0,0.0);
glVertex3f(248.0,280.0,0.0);
glVertex3f(248.0,287.0,0.0);
glVertex3f(192.0,287.0,0.0);
glEnd();
}
void trees()
{
glColor3f(0.9,0.5,0.0);
glBegin(GL_QUADS);
glVertex3f(80.0,235.0,0.0);
glVertex3f(90.0,235.0,0.0);
glVertex3f(90.0,290.0,0.0);
glVertex3f(80.0,290.0,0.0);
glEnd();
glColor3f(0.6,1.0,0.1);
glBegin(GL_TRIANGLES);
glVertex3f(60.0,290.0,0.0);
glVertex3f(110.0,290.0,0.0);
glVertex3f(85.0,360.0,0.0);
glEnd();
glColor3f(0.6,1.0,0.1);
glBegin(GL_TRIANGLES);
glVertex3f(65.0,320.0,0.0);
glVertex3f(105.0,320.0,0.0);
glVertex3f(85.0,390.0,0.0);
glEnd();
glColor3f(0.6,1.0,0.1);
glBegin(GL_TRIANGLES);
glVertex3f(70.0,350.0,0.0);
glVertex3f(100.0,350.0,0.0);
glVertex3f(85.0,395.0,0.0);
glEnd();
}
void small_birds(){
glBegin(GL_LINES);//line1 for birds1
glVertex3f(320.0,340.0,0.0);
glVertex3f(325.0,330.0,0.0);
glEnd();
glBegin(GL_LINES);//line2 for birds1
glVertex3f(325.0,330.0,0.0);
glVertex3f(330.0,340.0,0.0);
glEnd();
glBegin(GL_LINES);//line3 for birds1
glVertex3f(320.0,330.0,0.0);
glVertex3f(330.0,330.0,0.0);
glEnd();
glBegin(GL_LINES);//line1 for birds2
glVertex3f(300.0,340.0,0.0);
glVertex3f(305.0,330.0,0.0);
glEnd();
glBegin(GL_LINES);//line2 for birds2
glVertex3f(305.0,330.0,0.0);
glVertex3f(310.0,340.0,0.0);
glEnd();
glBegin(GL_LINES);//line3 for birds2
glVertex3f(300.0,330.0,0.0);
glVertex3f(310.0,330.0,0.0);
glEnd();
}
void banner()
{
glColor3f(0.2,0.2,0.2);
glBegin(GL_QUADS);
glVertex3f(45.0,210.0,0.0);
glVertex3f(45.0,150.0,0.0);
glVertex3f(130.0,150.0,0.0);
glVertex3f(130.0,210.0,0.0);
glEnd();
glColor3f(0.9,0.0,0.0);
glBegin(GL_LINES);
glVertex3f(45.0,180.0,0.0);
glVertex3f(45.0,100.0,0.0);
glEnd();
glBegin(GL_LINES);
glVertex3f(130.0,180.0,0.0);
glVertex3f(130.0,100.0,0.0);
glEnd();
}
void moon()
{
glColor3f(1.0,1.0,1.0);
glPushMatrix();
glTranslated(380.0,370.0,0.0);
glScaled(1.0,2.0,1.0);
glutSolidSphere(20.0,50,50);
glPopMatrix();
}
void drawText(float x, float y,char *s)
{
	int i;
	glRasterPos2f(x, y);
	for (i = 0; s[i]!='\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, s[i]);
			
		
	}
}
void drawText1(float x, float y,char *s)
{
	int i;
	glRasterPos2f(x, y);
	for (i = 0; s[i]!='\0'; i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, s[i]);
			
		
	}
}
void aplane()
{
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex3f(50.0,250.0,0.0);
glVertex3f(50.0,220.0,0.0);
glVertex3f(150.0,220.0,0.0);
glVertex3f(150.0,250.0,0.0);
glEnd();
glColor3f(1.0,1.0,1.0);
glBegin(GL_QUADS);
glVertex3f(150.0,250.0,0.0);
glVertex3f(150.0,220.0,0.0);
glVertex3f(157.0,225.0,0.0);
glVertex3f(157.0,245.0,0.0);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_TRIANGLES);
glVertex3f(157.0,245.0,0.0);
glVertex3f(157.0,225.0,0.0);
glVertex3f(173.0,235.0,0.0);
glEnd();
glColor3f(1.0,0.0,0.0);
glBegin(GL_QUADS);//TOP THING
glVertex3f(50.0,275.0,0.0);
glVertex3f(50.0,250.0,0.0);
glVertex3f(74.0,250.0,0.0);
glVertex3f(60.0,270.0,0.0);
glEnd();
glBegin(GL_QUADS);//WINGS
glVertex3f(100.0,233.0,0.0);
glVertex3f(85.0,213.0,0.0);
glVertex3f(115.0,213.0,0.0);
glVertex3f(130.0,233.0,0.0);
glEnd();
glColor3f(8.0,7.0,0.0);
glBegin(GL_QUADS);//WIN1 FRPM BACK
glVertex3f(65.0,240.0,0.0);
glVertex3f(65.0,235.0,0.0);
glVertex3f(70.0,235.0,0.0);
glVertex3f(70.0,240.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(80.0,240.0,0.0);
glVertex3f(80.0,235.0,0.0);
glVertex3f(85.0,235.0,0.0);
glVertex3f(85.0,240.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(95.0,240.0,0.0);
glVertex3f(95.0,235.0,0.0);
glVertex3f(100.0,235.0,0.0);
glVertex3f(100.0,240.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(110.0,240.0,0.0);
glVertex3f(110.0,235.0,0.0);
glVertex3f(115.0,235.0,0.0);
glVertex3f(115.0,240.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(125.0,240.0,0.0);
glVertex3f(125.0,235.0,0.0);
glVertex3f(130.0,235.0,0.0);
glVertex3f(130.0,240.0,0.0);
glEnd();
glBegin(GL_QUADS);
glVertex3f(140.0,240.0,0.0);
glVertex3f(140.0,235.0,0.0);
glVertex3f(145.0,235.0,0.0);
glVertex3f(145.0,240.0,0.0);
glEnd();
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINES);//line for wheels
glVertex3f(80.0,220.0,0.0);
glVertex3f(80.0,210.0,0.0);
glEnd();
glBegin(GL_LINES);//line for wheels
glVertex3f(135.0,220.0,0.0);
glVertex3f(135.0,210.0,0.0);
glEnd();
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslated(135.0,210.0,0.0);
glutSolidSphere(3.0,3.0,3.0);
glPopMatrix();
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslated(80.0,210.0,0.0);
glutSolidSphere(3.0,3.0,3.0);
glPopMatrix();
glColor3f(1.0,0.0,0.0);
drawText1(90,242,"S  P  I  C  E  J  E  T");
}
void cameraView(float rotx,float zoom)
{
init();
glLoadIdentity();
gluLookAt(viewer[0],viewer[1],viewer[2],10.0,40.0,10.0,0.0,1.0,0.0);
glClearColor(0.0,0.5,0.9,0.0);
glTranslated(0.5+rotx,0.5+rotx,5.0);
glScaled(1.0,1.0+zoom,1.0);
road();
grass();
trees();
bridge();
lamps(0.0);
glFlush();
glutPostRedisplay();
glutSwapBuffers();
}
void keyss(unsigned char key,int x,int y)
{
  if(key=='x')viewer[0]-=0.5;
  if(key=='X')viewer[0]+=0.5;
  if(key=='y')viewer[1]-=0.5;
  if(key=='Y')viewer[1]+=0.5;
  if(key=='z'){viewer[2]-=0.5;}
  if(key=='Z'){viewer[2]+=0.5;}
  if(key=='m'){rotx+=0.5;}
  if(key=='M'){rotx-=0.5;}
  if(key=='n')zoom+=0.1;
  if(key=='N')zoom-=0.1;
  cameraView(rotx,zoom);
}
//modes
void dayMode(void) {
glLightfv(GL_LIGHT0,GL_POSITION,light_position[0]);
glClearColor(0.0,0.7,1.0,0.0);
init();
road();
grass();
sun();
buildings();
lamps(0.0);
windows(0.8,0.1,0.5);
if(posX%2==0)
{
glPushMatrix();
glTranslatef(posX,posY,posZ);
birdup();
glPopMatrix();
}
else
{
glPushMatrix();
glTranslatef(posX,posY,posZ);
birddown();
glPopMatrix();
}
glColor3f(0.0,0.0,0.0);
drawText(30,370,"Use arrow keys to navigate the bird");
glFlush();
}

void nightMode()
{
glClearColor(0.0,0.0,0.2,0.9);
glLightfv(GL_LIGHT0,GL_POSITION,light_position[1]);
init();
road();
grass();
moon();
buildings();
lamps(1.0);
windows(0.0,0.0,0.0);
if(posX%2==0)
{
glPushMatrix();
glTranslatef(posX,posY,posZ);
birdup();
glPopMatrix();
}
else
{
glPushMatrix();
glTranslatef(posX,posY,posZ);
birddown();
glPopMatrix();
}
glColor3f(1.0,1.0,1.0);
drawText(30,370,"Use arrow keys to navigate the bird");
glFlush();
}
//farm
void display_farm()
{
init();
glPushMatrix();
glScaled(0.6,0.6,0.6);
grass_farm();
strip_farm();
cloud();
flower();
glPopMatrix();
//if(frameNumber%2==0)
//{
glPushMatrix();
glScaled(0.35,0.35,0.35);
glTranslatef(frameNumber,250.0,0.0);
birdup();
glPopMatrix();
//}
/*else
{
glPushMatrix();
glScaled(0.5,0.5,0.5);
glTranslatef(frameNumber,250.0,0.0);
birddown();
glPopMatrix();
}*/
glColor3f(0.0,0.0,0.0);
if(frameNumber<400)
{
glPushMatrix();
glScaled(0.6,0.6,0.6);
small_birds();
glPopMatrix();
}
else if(frameNumber>=400 && frameNumber<500)
{
glPushMatrix();
glScaled(0.6,0.6,0.6);
glTranslatef(30.0,30.0,0);
small_birds();
glPopMatrix();
}
else
{
glPushMatrix();
glScaled(0.6,0.6,0.6);
glTranslatef(60.0,60.0,0);
small_birds();
glPopMatrix();
}
glFlush();
}
void display_aero()
{
 init();
 road();
 cloud();
 grass();
strip();
aplane();
glPushMatrix();
glScaled(0.5,0.5,0.5);
glTranslatef(65.0,250.0,0.0);
birdup();
glPopMatrix();
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslatef(0.0,0.0,0.0);
small_birds();
glPopMatrix();
glColor3f(1.0,0.0,0.0);
drawText(300,75,"Location:Canada Airport(runway)");
glColor3f(0.0,0.0,0.0);
drawText(90,170,"PRESS 'a'");
glFlush();
}
void dis_home()
{
init();
glColor3f(0.0,0.0,0.0);
drawText(150, 350, "PROJECT THEME:WAR AND PEACE ");
drawText(180, 320,"PROJECT TITLE: ");
drawText(150, 300,"GARUD-The drone of surgical strike");
drawText(180, 280,"(aka ROBIRD)");
drawText(160, 230,"SAKSHI SINGH(1BI16CS127)");
drawText(160, 260,"PRAGATHI G(1BI16CS097)");
drawText(40,200,"BHANUSHREE K.J");
drawText(40,180,"Assistant Professor");
drawText(290,200,"K.N PRASHANTH KUMAR");
drawText(290,180,"Assistant Professor");
drawText(190.0, 130, "BIT, Bangalore");
drawText(150, 100, "RIGHT CLICK and choose the desired option");
}
//terroristcamp
void pkmkb()
{
init();
grass_pak();
tree();
fence();
pak_build();
banner();
if(posX%2==0)
{
glPushMatrix();
glTranslatef(posX,posY,posZ);
birdup();
glPopMatrix();
}
else
{
glPushMatrix();
glTranslatef(posX,posY,posZ);
birddown();
glPopMatrix();
}
glColor3f(0.0,0.0,0.0);
drawText(300,75,"Location:Terrorist camp in Pakistan");
glColor3f(1.0,1.0,1.0);
drawText(55,180,"xxCRUSH INDIAxx");
glFlush();
}

void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds) 
        ; 
} 
//timer
void doFrame(int v)
{       
	frameNumber++;
	
if(frameNumber>650)
	frameNumber=-400;


	glutPostRedisplay();
	glutTimerFunc(20, doFrame, 0);
}
//menu
void menu(int num)
{
if(num==0)
{
glutDestroyWindow(window);
exit(0);
}
else
value=num;
glutPostRedisplay();
}

void createMenu(void)
{
b=glutCreateMenu(menu);
glutAddMenuEntry("pakisan terrorist base camp",4);
glutAddMenuEntry("Airport-View",5);
glutAddMenuEntry("farm-view",6);
a=glutCreateMenu(menu);
glutAddMenuEntry("Day-Mode",1);
glutAddMenuEntry("Night-Mode",2);

m=glutCreateMenu(menu);
glutAddSubMenu("View",a);
glutAddSubMenu("Applications",b);
glutAddMenuEntry("Camera-View",3);
glutAddMenuEntry("Quit",7);
glutAttachMenu(GLUT_RIGHT_BUTTON);
}
//display
void display()
{
glClearColor(1.0,1.0,1.0,0.0);
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
switch(value)
{
case 0:dis_home();
break;
case 1:dayMode();
break;
case 2:nightMode();
break;
case 3:cameraView(rotx,zoom);
glutKeyboardFunc(keyss);
break;
case 4:glClearColor(0.0,0.0,0.2,0.9);
pkmkb();
break;
case 5:glClearColor(0.0,0.7,1.0,0.0);
display_aero();
break;
case 6:glClearColor(0.0,0.7,1.0,0.0);
display_farm();
break;
case 7:exit(0);
break;
}
glFlush();
}
//keyboard
int move_unit = 9;
void keyboardown(int key, int x, int y)
{
    switch (key){ 
        case GLUT_KEY_RIGHT:
            posX+=move_unit;;
            break;

        case GLUT_KEY_LEFT:
            posX-=move_unit;;
        break;

        case GLUT_KEY_UP:
            zoomin+=1;
            posY+=move_unit;
            posX+=move_unit;;
            break;

        case GLUT_KEY_DOWN:
            posY-=move_unit;
            posX+=move_unit;;
        break;
    }
    glutPostRedisplay();
}
int i=0;
void motion(unsigned char keys, int x, int y)
{
 if(keys== 'a')
 {
   for(q=0;q<120;q=q+10)
    {
road();
 cloud();
 grass();
strip();
aplane();
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslatef(0.0-q,0.0-q,0.0);
small_birds();
glPopMatrix();
delay(200);
glFlush();
}  
for(p=0;p<200;p=p+9)
    {
road();
 cloud();
 grass();
strip();
aplane();
if((p%2)==0)
{
glPushMatrix();
glTranslatef(65,300-p,0);
glScaled(0.5,0.5,0.5);
birdup();
glPopMatrix();
}
else
{
glPushMatrix();
glTranslatef(65,300-p,0);
glScaled(0.5,0.5,0.5);
birddown();
glPopMatrix();
}
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslatef(-120.0,-120.0,0.0);
small_birds();
glPopMatrix();
delay(150);
glFlush();
}
for(q=0;q<200;q=q+10)
    {
road();
 cloud();
 grass();
strip();
aplane();
glColor3f(0.0,0.0,0.0);
glPushMatrix();
glTranslated(-120+q,-120+q,0.0);
small_birds();
glPopMatrix();
delay(100);
glFlush();} 
for(q=0;q<300;q=q+10)
    {
road();
cloud();
grass();
strip();
glPushMatrix();
glTranslatef(0.0+q,0.0+q,0);
aplane();
glPopMatrix();
glColor3f(0.0,0.0,0.0);
delay(100);
glFlush();
} 
}
glutPostRedisplay();
}

void myReshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
if(w<=h)
glFrustum(0.0,400.0,0.0*(GLfloat)h/(GLfloat)w,400.0*(GLfloat)h/(GLfloat)w,0.0,400.0);
else
glFrustum(0.0,400.0,0.0*(GLfloat)w/(GLfloat)h,400.0*(GLfloat)w/(GLfloat)h,0.0,400.0);
glMatrixMode(GL_MODELVIEW);
}
//viewkeys
int main (int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
  glutInitWindowSize(500,500);
  glutInitWindowPosition (50, 50);
  glutCreateWindow ("GARUD-the drone of surgical strike");
  createMenu();  
  glutSpecialFunc(keyboardown);
  createMenu();
  glViewport(0,0,640,480);
  glutKeyboardFunc(motion);
  glutTimerFunc(20, doFrame, 0);
  glutReshapeFunc(myReshape);
  glutDisplayFunc(display);
  glutMainLoop ();
  return 0;
}
