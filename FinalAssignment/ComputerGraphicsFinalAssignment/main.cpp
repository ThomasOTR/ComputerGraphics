#include <GL/glew.h>
#include <GL/freeglut.h>
#include "InputHandler.h"
#include "Shape Classes/Pyramid.h"
#include "environment_builder.h"

/* */
const unsigned int WIDTH = 800, HEIGHT = 600;
unsigned const int DELTA_TIME = 10;

InputHandler IH;
Camera camera;
EnvironmentBuilder EB;

/*
 * A callback to reshape the window
 */
void ReshapeCallback(int width, int height)
{
    glViewport(0, 0, width, height);
}

/*
* A callback triggered when a key is pressed.
* This callback will trigger an InputHandler to perform an action based on a key
*/
void KeyboardCallback(unsigned char key, int a, int b)
{
    camera = IH.processKeyInput(camera, key);
}
/*
* A callback triggered when the mouse is moved.
* This callback will trigger an InputHandler to perform an action based on the movement
*/
void MouseCallback(int x, int y) 
{
    camera = IH.processMouseInput(camera, x, y);
}

/* 
 * A method to render each part of this project 
 */
void Render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   camera.CalculateViewMatrix();
   EB.RenderAllEntities(camera.CurrentMode.view, camera.CurrentMode.projection);

    glutSwapBuffers();
}

/* 
 * A method to run the other Render method over and over again
 */
void Render(int n)
{
    Render();
    glutTimerFunc(DELTA_TIME, Render, 0);
}

/*
 * A method to buffer everything before rendering it. 
 */
void Buffer() 
{
    EB.BufferAllEntities(camera.CurrentMode.view,camera.CurrentMode.projection);
}

/*
 * A method to initialise everything related to Glut and Glew
 */
void InitGlutGlew(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Thomas CG_FinalAssignment");
    glutDisplayFunc(Render);

    glutKeyboardFunc(KeyboardCallback);
    glutReshapeFunc(ReshapeCallback);
    glutPassiveMotionFunc(MouseCallback);
    glutSetCursor(GLUT_CURSOR_NONE);
    glutTimerFunc(DELTA_TIME, Render, 0);
    glewInit();
}

/*  
 * The method which is initialising everything
 */
int main(int argc, char** argv)
{
    InitGlutGlew(argc, argv);
    camera.CalculateProjectionMatrix();
    Buffer();
    glEnable(GL_DEPTH_TEST);
    glDisable(GL_CULL_FACE);

    HWND hWnd = GetConsoleWindow();
    ShowWindow(hWnd, SW_SHOW);
    glutMainLoop();
    return 0;
}