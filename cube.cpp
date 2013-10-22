#include<GL/glut.h>
#include<iostream>
#include<math.h>
using namespace std;
class Point;
int size = 45;
class Point 
{
	int x,y,z;
	public:
	Point()
	{
		x=y=z=0;

	}
	 Point (int x1,int y1,int z1)
	{
		x=x1; y =y1; z=z1;
	}
	int getx()
	{
		return x;
	}
	int gety()
	{
		return y;
	}
	int getz()
	{
		return z;
	}
		
}p[8];
	
void initpoints()
{
	p[0]=Point(0,0,0);
	p[1]=Point(size,0,0);
	p[2]=Point(size,size,0);	
	p[3]=Point(0,size,0);	
	p[4]=Point(0,0,size);	
	p[5]=Point(size,0,size);	
	p[6]=Point(size,size,size);	
	p[7]=Point(0,size,size);	
}
void plotpoint(Point a)
{
	glVertex3f(a.getx(),a.gety(),a.getz());
}
void drawcube(Point p[8])
{
glBegin(GL_QUADS);
	glColor3f(1.0,0,0);
	plotpoint(p[0]);
	plotpoint(p[1]);
	plotpoint(p[2]);
	plotpoint(p[3]);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0,1,0);
	plotpoint(p[6]);
	plotpoint(p[2]);
	plotpoint(p[3]);
	plotpoint(p[7]);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0,0,1);
	plotpoint(p[0]);
	plotpoint(p[3]);
	plotpoint(p[7]);
	plotpoint(p[4]);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1,0,1);
	plotpoint(p[0]);
	plotpoint(p[4]);
	plotpoint(p[5]);
	plotpoint(p[1]);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(1.0,1,0);
	plotpoint(p[6]);
	plotpoint(p[7]);
	plotpoint(p[4]);
	plotpoint(p[5]);
	glEnd();
	glBegin(GL_QUADS);
	glColor3f(0,1,1);
	plotpoint(p[6]);
	plotpoint(p[5]);
	plotpoint(p[1]);
	plotpoint(p[2]);
	glEnd();
	glFlush();

}
void mydisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(1,0.5,0);
	glBegin(GL_LINES);
	glVertex3f(-640,0,0);
	glVertex3f(640,0,0);	
	glVertex3f(0,-480,0);
	glVertex3f(0,480,0);
	glVertex3f(0,0,-520);
	glVertex3f(0,0,520);
	glEnd();
	drawcube(p);
	glFlush();

}

void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(0.5,0,0.4);	
	glPointSize(10);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//gluOrtho2D(0,640,0,480);	
	glOrtho(-640,640,-480,-480.0,-520,520);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(4,4,4,0,1,0,0,1,0);
}
int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	initpoints();
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,440);
	glutCreateWindow("TRANSFORM");
	glutDisplayFunc(mydisplay);
	
	myinit();
	glutMainLoop();
	return 0;
}

