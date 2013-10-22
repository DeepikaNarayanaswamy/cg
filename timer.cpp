#include<GL/glut.h>
#include<iostream>
using namespace std;
int x[4]= {100,200,100,200};
int y[4]= {100,200,200,100};
float trans[3][3]= {{0.5,0,0},{0,1,0},{0,0,1}};
int x1=100,x2=100,y1=100,y2=200,count=0;
void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1);
	gluOrtho2D(-512.0,512.0,-512.0,512.0);
}
void translate(int w)
{
	int i,j,k;
	
	int p[3][1],p1[3][1];
	//sleep(1);
if (count > 2 )
	{
		trans[0][0]=1.5; trans[1][1]=1;
	}
else if (count > 4)
{
	trans[0][0]=0.5;
	count=0;
}
	for (i=0;i<4;i++)
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
		x[i]=p1[0][0];
		y[i]=p1[1][0];		
	}
	count++;

}

void mydisplay()
{
	int i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_POLYGON);
	for (i=0;i<4;i++)
	glVertex2d(x[i],y[i]);
	glEnd();
	
	sleep(1);
	//count++;
	translate(1);
	
	glutPostRedisplay();
	glFlush();
}


int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(512,512);
	glutCreateWindow("TRANSFORM");
	glutDisplayFunc(mydisplay);
	glutTimerFunc(1000,translate,1);
	myinit();
	glutMainLoop();
	return 0;
}


