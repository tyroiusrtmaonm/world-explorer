//Get the GLUT libraries
#include <GL/freeglut.h>
#include <GL/glu.h>

//Math
#include <math.h>

//Other includes
#include "camera.h"

#include <iostream>

Camera::Camera () {
  angle = 0;
  camera_x  = camera_z = 1.0f;
  direction_x = 0.0f;
  direction_z = -1.0f;
  
  camera_y = 1.0f;
  direction_y = 0.0f;
}
Camera::~Camera() { }

//Just a wrapper for the gluLookAt function
void Camera::look_at() {
    std::cout << direction_x << '\n';
    gluLookAt(camera_x, 1.0f, camera_z,
              camera_x + direction_x, 0.0f, camera_z + direction_z,
              0.0f, 1.0f, 0.0f);
}
const float fraction = 0.1f;
void Camera::camera_key_press(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            camera_x += direction_x * fraction;
			camera_z += direction_z * fraction;
            break;
        case GLUT_KEY_DOWN:
            //camera_z -= 0.1f;
            camera_x -= direction_x * fraction;
			camera_z -= direction_z * fraction;
            break;
        case GLUT_KEY_RIGHT:
            //camera_x += 0.1f;
            angle += 0.1f;
		    direction_x = sin(angle);
			direction_z = -cos(angle);
            break;
        case GLUT_KEY_LEFT:
            camera_x -= 0.1f;
            angle -= 0.1f;
			direction_x = sin(angle);
			direction_z = -cos(angle);
            break;
        default:
            return;
    }
}

