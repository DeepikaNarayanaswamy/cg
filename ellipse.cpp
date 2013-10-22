#include<GL/glut.h>
#include<iostream>
#include<math.h>
void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1);
	gluOrtho2D(0.0,512,0.0,512);
}
int rounding(double a)
{
	return (int)a+0.5;
}
void drawellipse(int xc,int yc, int rx, int ry)
{
	float px,py,y,x,p;
	x=0;y=ry;
	px=0;
	py=2*pow(rx,2)*y;
	p=rounding(pow(ry,2)-(pow(rx,2)*ry)+(0.25*pow(rx,2)));
		glBegin(GL_POINTS);
		glColor3f(0.0,0.0,1.0);
		glVertex2d(xc+x,yc+y);		
		glVertex2d(xc-x,yc+y);	
		glVertex2d(xc+x,yc-y);
		glVertex2d(xc-x,yc-y);
		glEnd();
	
	while (px < py)
	{
		x++;
		px+=2*pow(ry,2);
		if (p<0)
			p+=px+pow(ry,2);
		else
		{
			y--;
			py-=2*pow(rx,2);		
			p+=px+pow(ry,2)-py;
		}
		glBegin(GL_POINTS);
		glColor3f(0.0,0.0,1.0);
		glVertex2d(xc+x,yc+y);		
		glVertex2d(xc-x,yc+y);	
		glVertex2d(xc+x,yc-y);
		glVertex2d(xc-x,yc-y);
		glEnd();
	}
	p=rounding( pow(x+0.5,2)*pow(ry,2)+pow(y-1,2)*pow(rx,2)-pow(rx,2)*pow(ry,2));
	while (y>0)
	{
		y--;
		py-=2*pow(rx,2);
		if (p>0)
			p+=pow(rx,2)-py;
		else
			{
				x++;
				px+=2*pow(ry,2);
				p+=pow(rx,2)+px-py;
			}
	glBegin(GL_POINTS);
		glColor3f(0.0,0.0,1.0);
		glVertex2d(xc+x,yc+y);		
		glVertex2d(xc-x,yc+y);	
		glVertex2d(xc+x,yc-y);
		glVertex2d(xc-x,yc-y);
		glEnd();
	}
	glFlush();
}

void mydisplay()
{

	glClear(GL_COLOR_BUFFER_BIT);
	drawellipse(256,256,150,75);
	drawellipse(400,400,75,150);
	glFlush();
}
int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(512,512);
	glutCreateWindow("TRANSFORM");
	glutDisplayFunc(mydisplay);
	myinit();
	glutMainLoop();
	return 0;
}

