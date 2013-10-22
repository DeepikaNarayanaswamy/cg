#include <GL/glut.h>
#include<iostream>
using namespace std;
	GLfloat mat_specular[] = {0.5, 0.5, 0.5, 1.0};     // Define highlight properties
  	GLfloat mat_shininess[]= {100.0};                   // Define shininess of surface
  	GLfloat light_position[] = {50.0, 50.0, 0.0, 0.0}; // Define light source position
	GLfloat light_diffuse [] = {1.0,1.0,1.0,1.0};
	GLfloat light_ambient[] = {1.0,1.0,1.0,1.0};
	GLfloat light_specular [] = {1.0,1.0,1.0,1.0};
	double yt=0,xt=0;
	int flag=0;
void display()
{
	 glClear(GL_COLOR_BUFFER_BIT);
	 glEnable(GL_DEPTH_TEST); 		
	 glClearColor(0.3, 0.3, 0.3, 0.0);               
                  sleep(1);         
 	 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);   // Set material properties
	 glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess); // Set material properties
	 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	 glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	 glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	 glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	   // Set light properties
 	//Set Color Capability
	 glColorMaterial(GL_FRONT,GL_DIFFUSE);
	 glEnable(GL_COLOR_MATERIAL);		       // Enable color
	 glEnable(GL_LIGHTING);		       // Enable lighting for surfaces
	 glEnable(GL_LIGHT0);			       // Enable light source
 	glColorMaterial(GL_FRONT,GL_AMBIENT);
		glShadeModel(GL_FLAT);
   	//sleep(1);
	cout<<"\n now yt & xt="<<yt<<xt;
		glPushMatrix();
		
		glTranslatef(-0.6,0,0.0);
		glColor3f(1.0,0.5,0.2);
 		glutSolidSphere(0.25,50,50);   
 
	glPopMatrix();
	
   	
	glPushMatrix();

		glTranslatef(-0.3+xt,yt,xt);
		glColor3f(1.0,0.5,0.2);
 		glutSolidSphere(0.05,50,50);   
 
	glPopMatrix();
	glPushMatrix();

		glTranslatef(0.0+xt,yt+0.05,xt);
		glColor3f(0.0,0,0.8);
 		
		glutSolidSphere(0.05,50,50);   
	glPopMatrix();	
	
	glFlush();
	if (yt <= 0.55 && flag==0)	
		{
			yt+=0.05;
			
		}
	else if (yt==0.6 && -xt<0.5 && flag==0)
		{xt-=0.05; cout<<"here elseif ";}
	 if (flag==1)
	{	cout <<" : P :P";
		yt-=0.05;
		flag=1;
		//xt=-0.3;
	}
		
	glutPostRedisplay();
	glFlush();	
   
}

/*void timerfunc(int x)
{
	display(1,3);
	//sleep(1);
	if (yt<=1)
		yt+=0.05;
	glutPostRedisplay();
}
*/
int main (int argc, char **argv)
{
    //Initialize GLUT
    glutInit(&argc, argv);
    //double buffering used to avoid flickering problem in animation
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  
    // window size
    glutInitWindowSize(1000,1000);
    // create the window 
    glutCreateWindow("Teapot Rotating Animation");
    glClearColor(0.0,0.0,0.0,0.0);
    //Assign  the function used in events
    glutDisplayFunc(display);
//	glutTimerFunc(1000,timerfunc,1);
  // glutReshapeFunc(display);
    glutMainLoop();
    return 0;
}
