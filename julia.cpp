#include<GL/glut.h>
#include<iostream>
#include<math.h>
void myinit()
{
	
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(640,0.0,440,0.0);
}
int julia (double sx,double sy)
{
	double cx=-0.3,cy=-0.6,dx,dy,fsq,tmp;
	dx=sx; dy=sy;
	fsq=dx*dx + dy*dy;
	int itermax=50,iteration;
	for (iteration =1 ; iteration <= itermax && fsq < 4 ; iteration ++)
	{
		tmp=dx;
		dx=dx*dx - dy*dy+cx;
		dy=2*tmp*dy+cy;
		fsq = dx*dx + dy*dy;
	}
	return iteration;
}
void color (int x, int y, int col)
	{
		if (col==1)
			{
				glBegin(GL_POINTS);			
				glColor3f(1.0,0,0);
				glVertex2i(x,y);
				glEnd();
			}
		else
			{
					
				glBegin(GL_POINTS);			
				glColor3f(0,1.0,0);
				glVertex2i(x,y);
				glEnd();
			}
	glFlush();
}
void drawfractal()
{
	double hx,hy,zoom=1.5,sx,sy,hxres,hyres,iteration;
	hxres=100; hyres=400;
	for (hy=1;hy<=hyres;hy++)
	{
		sy= (hy -hyres/2)/(0.5*zoom*hyres);
		for (hx=1;hx<=hxres;hx++)
		{
			sx= 1.5 * (hx-hxres/2)/(0.5*zoom*hxres);
			iteration = julia(sx,sy);
			if (iteration <= 50 ) color (hx,hy,1);	
			else color (hx,hy,2);
		}
	}
	//glFlush();
}
void mydisplay()
{

	glClear(GL_COLOR_BUFFER_BIT);
	drawfractal();
	glFlush();
}
int main(int argc, char**argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(640,440);
	glutCreateWindow("TRANSFORM");
	glutDisplayFunc(mydisplay);
	myinit();
	glutMainLoop();
	return 0;
}

