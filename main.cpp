//Standard libraries
#include <iostream>
#include <stdlib.h>

//GLUT
#include <GL/freeglut.h>

//Local includes
#include "camera.h"

//Set up the namespace
using namespace std;

//Function prototypes
void render_scene(void);
void normal_keypress_wrapper(unsigned char key, int x, int y);
void special_keypress_wrapper(int key, int x, int y);

Camera global_cam;



int main(int argc, char **argv) {
    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(640,480);
	glutCreateWindow("World Explorer");
	
	//Create a camera object
	global_cam = Camera();
	
	// register callbacks
	glutDisplayFunc(render_scene);
	glutIdleFunc(render_scene);
	
	
	glutKeyboardFunc(normal_keypress_wrapper);
	glutSpecialFunc(special_keypress_wrapper);


    glEnable(GL_DEPTH_TEST);
	// enter GLUT event processing cycle
	glutMainLoop();
	
	return 0;
}
void drawSnowMan() {

	glColor3f(1.0f, 1.0f, 1.0f);

// Draw Body
	glTranslatef(0.0f ,0.75f, 0.0f);
	glutSolidSphere(0.75f,20,20);

// Draw Head
	glTranslatef(0.0f, 1.0f, 0.0f);
	glutSolidSphere(0.25f,20,20);

// Draw Eyes
	glPushMatrix();
	glColor3f(0.0f,0.0f,0.0f);
	glTranslatef(0.05f, 0.10f, 0.18f);
	glutSolidSphere(0.05f,10,10);
	glTranslatef(-0.1f, 0.0f, 0.0f);
	glutSolidSphere(0.05f,10,10);
	glPopMatrix();

// Draw Nose
	glColor3f(1.0f, 0.5f , 0.5f);
	glRotatef(0.0f,1.0f, 0.0f, 0.0f);
	glutSolidCone(0.08f,0.5f,10,2);
}


void render_scene(void) {
    //Reset everything
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    //Move to the camera
    global_cam.look_at();

	// Draw ground
	glColor3f(0.9f, 0.9f, 0.9f);
	glBegin(GL_QUADS);
		glVertex3f(-100.0f, 0.0f, -100.0f);
		glVertex3f(-100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f,  100.0f);
		glVertex3f( 100.0f, 0.0f, -100.0f);
	glEnd();

        // Draw 36 SnowMen
	for(int i = -3; i < 3; i++)
		for(int j=-3; j < 3; j++) {
			glPushMatrix();
			glTranslatef(i*10.0,0,j * 10.0);
			drawSnowMan();
			glPopMatrix();
		}
    glutSwapBuffers();
}

void normal_keypress_wrapper(unsigned char key, int x, int y) {
    
}

void special_keypress_wrapper(int key, int x, int y) {
    global_cam.camera_key_press(key, x, y);
}
