#include<GL/glut.h>
#include<iostream>
using namespace std;
int r=30,xc=10,yc=10;
void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1);
	gluOrtho2D(0.0,512,0.0,512);
}
void mycircle(int x1)
{
	int i,p,x0,y0,x,y;
	x=0;y=r;

	glClearColor(1.0,1.0,1.0,1.0);
	glColor3f(1.0,0.0,0.0);
	sleep(1);

	for (i=0;i<8;i++)
	{
		glBegin(GL_POINTS);
		glVertex2d(xc+x,yc+y);
		glEnd();
		x=0;y=r;
		p=1-r;
		while (x<y)
		{
			x+=1;
			if (p<0)
			{
				p+=2*x+1;
			}
			else
			{
				y-=1;
				p+=2*x+1-2*y;
			}
			switch(i)
			{
				case 0 : x0=x+xc;y0=y+yc;break;
				case 1 : x0=-x+xc;y0=y+yc;break;
				case 2 : x0=x+xc;y0=-y+yc;break;
				case 3 : x0=-x+xc;y0=-y+yc;break;
				case 4 : x0=y+xc;y0=x+yc;break;
				case 5 : x0=-y+xc;y0=x+yc;break;
				case 6 : x0=y+xc;y0=-x+yc;break;
				case 7 : x0=-y+xc;y0=-x+yc;break;
			}
			glBegin(GL_POINTS);
			glVertex2d(x0,y0);
			glEnd();
		}
	}
	glFlush();
	if (r < 100 || xc <=256){r+=10;xc+=40;yc+=40;}
	else if ( yc>=0) {r-=20;xc+=40;yc-=40;}
	

}
void mydisplay()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	//r=30;xc=256;yc=256;
//sleep(1);
	mycircle(1);
	
	glutPostRedisplay();
	//if (xc < 512){xc+=10;glutPostRedisplay();}
	glFlush();
	
}

int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(512,512);
	glutCreateWindow("TRANSFORM");
	glutDisplayFunc(mydisplay);
	glutTimerFunc(1000,mycircle,1);
	myinit();
	glutMainLoop();
	return 0;
}

