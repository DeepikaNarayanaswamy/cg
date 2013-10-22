#include<GL/glut.h>
#include<iostream>
using namespace std;
float x[6] ={125,100,100,120,200,200};
float y[6]={230,200,100,80,100,200};
void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1);
	gluOrtho2D(-512.0,512.0,-512.0,512.0);
}

void mydisplay()
{
	int i,j,k,p[3][1],p1[3][1];
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5,1.0,0.0);
	glBegin(GL_POLYGON);
	float trans[3][3] = {{2,0,0},{0,2,0},{0,0,1}};
	for (i=0;i<4;i++)
		{
		glVertex2d(x[i],y[i]);
		
		}	
		glEnd();

	for (i=0;i<6;i++)
	{
		p[0][0]=x[i];
		p[1][0]=y[i];
		p[2][0]=1;
		for (j=0;j<3;j++)
		{
			p1[j][0]=0;
			for (k=0;k<3;k++)
			{
				p1[j][0]+=trans[j][k]*p[k][0];
			}
		}
		glBegin(GL_POLYGON);
		glColor3f(1.0,0.0,0.0);
		glVertex2d(p1[0][0],p1[1][0]);
		
	}
	glEnd();
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


