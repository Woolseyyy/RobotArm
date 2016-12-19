#include "stdafx.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct ArmDegreeStruct
{
	int xy = 0;
	int yz = 0;
	int xz = 0;
} ArmDegree ;


ArmDegree armsDegree[3];//to store degrees of arms
GLdouble fovy = 100;

void init(){
	//light set
	GLfloat ambient[] = { 0.5, 0.8, 0.1, 0.1 };
	GLfloat diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat position[] = { -80.0, 50.0, 25.0, 1.0 };
	GLfloat lmodel_ambient[] = { 0.4, 0.4, 0.4, 1.0 };
	GLfloat local_view[] = { 0.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
	
	//light position
	glLightfv(GL_LIGHT0, GL_POSITION, position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
	glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
	
	//start
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
}

void display(void){
	//init
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glLoadIdentity();

	//view
	gluLookAt(-2.0, -1.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glPushMatrix();

	//the first joint
	glutSolidSphere(1, 20, 20);

	//the first degree
	glRotated(armsDegree[0].xy, 0, 0, 1);
	glRotated(armsDegree[0].yz, 1, 0, 0);
	glRotated(armsDegree[0].xz, 0, 0, 1);
	glPushMatrix();
	
	//draw the first arm
	glPushMatrix();
	glTranslated(6, 0, 0);
	glScaled(10, 2, 2);
	glutSolidCube(1);
	glPopMatrix();

	//draw the second joint
	glTranslated(11.8, 0, 0);
	glPushMatrix();
	glutSolidSphere(0.8, 20, 20);

	//the second degree
	glRotated(armsDegree[1].xy, 0, 0, 1);
	glRotated(armsDegree[1].yz, 1, 0, 0);
	glRotated(armsDegree[1].xz, 0, 0, 1);
	glPushMatrix();

	//draw the second arm
	glPushMatrix();
	glTranslated(4.8, 0, 0);
	glScaled(8, 1.5, 1.5);
	glutSolidCube(1);
	glPopMatrix();

	//draw the third joint
	glTranslated(9.4, 0, 0);
	glPushMatrix();
	glutSolidSphere(0.6, 20, 20);

	//the third degree
	glRotated(armsDegree[2].xy, 0, 0, 1);
	glRotated(armsDegree[2].yz, 1, 0, 0);
	glRotated(armsDegree[2].xz, 0, 0, 1);
	glPushMatrix();

	//draw the third arm
	glPushMatrix();
	glTranslated(2.6, 0, 0);
	glScaled(4, 1, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();
}

void keyPressed(unsigned char key, int x, int y) {
	switch (key) {
	case 'a':
		armsDegree[0].xy -= 2;
		break;
	case 'd':
		armsDegree[0].xy += 2;
		break;
	case 'w':
		armsDegree[0].yz += 2;
		break;
	case 's':
		armsDegree[0].yz -= 2;
		break;
	case 'q':
		armsDegree[0].xz += 2;
		break;
	case 'e':
		armsDegree[0].xz -= 2;
		break;
	case 'f':
		armsDegree[1].xy -= 2;
		break;
	case 'h':
		armsDegree[1].xy += 2;
		break;
	case 't':
		armsDegree[1].yz += 2;
		break;
	case 'g':
		armsDegree[1].yz -= 2;
		break;
	case 'r':
		armsDegree[1].xz += 2;
		break;
	case 'y':
		armsDegree[1].xz -= 2;
		break;
	case 'j':
		armsDegree[2].xy -= 2;
		break;
	case 'l':
		armsDegree[2].xy += 2;
		break;
	case 'i':
		armsDegree[2].yz += 2;
		break;
	case 'k':
		armsDegree[2].yz -= 2;
		break;
	case 'u':
		armsDegree[2].xz += 2;
		break;
	case 'o':
		armsDegree[2].xz -= 2;
		break;
	}
	glutPostRedisplay();
}

void reshape(int w, int h) {

	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(fovy, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);

	glutCreateWindow(argv[0]);
	
	init();
	
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);

	glutMainLoop();
	return 0;
}
