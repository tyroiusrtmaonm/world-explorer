//Standard libraries
#include <iostream>
#include <stdlib.h>

//GLUT
#include <GL/freeglut.h>

//Set up the namespace
using namespace std;
void render_scene(void);

int main(int argc, char **argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("World Explorer");
	
	// register callbacks
	glutDisplayFunc(render_scene);

	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0;
}


void render_scene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glBegin(GL_TRIANGLES);
		glVertex3f(-0.5,-0.5,0.0);
		glVertex3f(0.5,0.0,0.0);
		glVertex3f(0.0,0.5,0.0);
	glEnd();

    glutSwapBuffers();
}

