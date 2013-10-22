#include<GL/glut.h>
#include<iostream>
using namespace std;
int inside =0;
const int top =8,bottom=4,right1=2,left1=1;
int xmin = 0 , xmax=100,ymin=0,ymax=100;
void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(-40,840,-480,480);
}
int findcode(double x, double y)
{
	int code=0;		
	if (x<xmin)
		code|=left1;
	else if (x>xmax)
		code |=right1;
	if (y < ymin)
		code|=bottom;
	else if (y>ymax)
		code|=top;
	return code;
}
void drawline (double x1, double y1, double x2, double y2)
{
	int code1,code2,i=0,j=4,code;
	double m,x,y;
	bool accept = false;
	code1 = findcode (x1,y1);
	code2=findcode(x2,y2);
	while (true)
	{
		if (!(code1 | code2))
		{
			accept=true;
			break;
		}
		else if (code1 & code2)
			{	
				accept=false;break;
			}
		else
		{
			code=code1 > code2 ? code1 : code2;
			m = (y2-y1)/(x2-x1);
			if (code & top)
			{
				x=x1+(ymax-y1)/m;
				y=ymax;
			}
			else if ( code & bottom)
			{
				x=x1+(ymin-y1)/m;
				y=ymin;
			}
			else if ( code & left1)
			{
				y=y1+m*(xmin-x1);
				x=xmin;
			}

			else if ( code & right1)
			{
				y=y1+m*(xmax-x1);
				x=xmax;
			}
			if (code == code1)
			{
				x1=x; y1=y;
				code1=findcode(x1,y1);
			}
			else if (code2==code)
			{
				x2=x; y2=y;
				code2=findcode(x2,y2);
			}
		}
		i++;
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0,0.0,0.0);
		glVertex2d(xmin+(i*150),ymin);
		glVertex2d(xmin+(i*150),ymax);
		glVertex2d(xmax+(i*150),ymax);
		glVertex2d(xmax+(i*150),ymin);
		glVertex2d(xmin+(i*150),ymin);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,1.0);
		glVertex2d(x1+(i*150),y1);
		glVertex2d(x2+(i*150),y2);
		glEnd();
		
		j--;
	}
	while (j>0)
	{
		i++;	
		glBegin(GL_LINE_STRIP);
		glColor3f(1.0,0.0,0.0);
		glVertex2d(xmin+(i*150),ymin);
		glVertex2d(xmin+(i*150),ymax);
		glVertex2d(xmax+(i*150),ymax);
		glVertex2d(xmax+(i*150),ymin);
		glVertex2d(xmin+(i*150),ymin);
		glEnd();
		glBegin(GL_LINES);
		glColor3f(0.0,0.0,1.0);
		glVertex2d(x1+(i*150),y1);
		glVertex2d(x2+(i*150),y2);
		glEnd();
		j--;
	}
	glFlush();
}
void mydisplay()
{
	double x1,y1,x2,y2;
	glClear(GL_COLOR_BUFFER_BIT);
	cout <<"enter the value of (x1,y1) & (x2,y2)";
	cin>>x1>>y1>>x2>>y2;
	glColor3f(0.0,0.8,0.0);
	glBegin(GL_LINE_STRIP);

		glVertex2d(xmin,ymin);
		glVertex2d(xmin,ymax);
		glVertex2d(xmax,ymax);
		glVertex2d(xmax,ymin);
		glVertex2d(xmin,ymin);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,1.0);
		glVertex2d(x1,y1);
		glVertex2d(x2,y2);
	glEnd();
	drawline(x1,y1,x2,y2);
	glFlush();
}
int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,480);
	glutCreateWindow("TRANSFORM");
	glutDisplayFunc(mydisplay);
	myinit();
	glutMainLoop();
	return 0;
}

