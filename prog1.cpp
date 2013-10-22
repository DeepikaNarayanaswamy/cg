#include<GL/glut.h>
#include<iostream>
using namespace std;
void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1);
	gluOrtho2D(0,300.0,0,400.0);
}

void myline(float x1,float y1,float x2,float y2)
{
	float dx,dy,twodx,twody,twodxdy,x,y;
	float p,xend,yend;
	int flag;
	if (x1>x2)
		dx=x1-x2;
	else 
		dx=x2-x1;
	if (y1 > y2)
		dy=y1-y2;
	else
		dy=y2-y1;
		
	if (dx>dy) // slope < 1
	{
		cout <<" i am here ";
		p = 2*dy -dx;
		xend=x2;
		x=x1;y=y1;
		if (y1>y2)
		{
			flag=0;	
		}
		else
		{
			flag=1;
		}
		glColor3f(1.0,0.0,0.0);
		while (x <= xend)
		{
			x=x+1;		
			if (p <0 )	
				p+=2*dy;
			else
				{
					if (flag==0)
					y=y-1;
					else
					y=y+1;
				p+=2*(dy-dx);
				}
		glBegin(GL_POINTS);
		glVertex2d(x,y);
		glEnd();
		}
	}
	else 
	{
		yend=y2;
		x=x1;y=y1;
		p=2*dx - dy;
		if (x1>x2)
		flag=0;
		else
		flag=1;
		while (y <= yend)
		{
			y+=1;
			if (p < 0)
				p+=2*dx;
			else
			{				
				p+=2*(dx-dy);
				if (flag==0)
				x-=1;
				else
				x+=1;
			}
			glColor3f(1.0,0.0,0.0);
			glBegin(GL_POINTS);
			glVertex2d(x,y);
			glEnd();
		}
	}
	glFlush();

}

void mydisplay()
{
	float x1,y1,x2,y2;
	glClear(GL_COLOR_BUFFER_BIT);
	cout<<"Enter the line coordinates (x1,y1) & (x2,y2)";
	cin>>x1>>y1>>x2>>y2;
	myline(x1,y1,x2,y2);
}


int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(300,400);
	glutCreateWindow("fractal");
	glutDisplayFunc(mydisplay);
	myinit();
	glutMainLoop();
	return 0;
}

