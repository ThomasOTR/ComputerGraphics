#include <GL/glew.h>
#include <GL/freeglut.h>
#include "InputHandler.h"
#include "EnvironmentBuilder.h"


const unsigned int WIDTH = 800, HEIGHT = 600;
unsigned const int DELTA_TIME = 10;

InputHandler IH;
Camera camera;
EnvironmentBuilder EB;

/// <summary>
/// A callback to reshape the window
/// </summary>
/// <param name="width"></param>
/// <param name="height"></param>
void ReshapeCallback(int width, int height)
{
    glViewport(0, 0, width, height);
}

/*

*/

/// <summary>
/// A callback triggered when a key is pressed.
/// This callback will trigger an InputHandler to perform an action based on a key
/// </summary>
/// <param name="key"></param>
/// <param name="a"></param>
/// <param name="b"></param>
void KeyboardCallback(unsigned char key, int a, int b)
{
    camera = IH.processKeyInput(camera, key);
}

/// <summary>
/// A callback triggered when the mouse is moved.
/// This callback will trigger an InputHandler to perform an action based on the movement
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void MouseCallback(int x, int y) 
{
    camera = IH.processMouseInput(camera, x, y);
}

/// <summary>
/// A method to render each part of this project 
/// </summary>
void Render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   camera.CalculateViewMatrix();
   EB.RenderAllEntities(camera.CurrentMode.view, camera.CurrentMode.projection);

    glutSwapBuffers();
}

/// <summary>
/// A method to run the other Render method over and over again
/// </summary>
/// <param name="n"></param>
void Render(int n)
{
    Render();
    glutTimerFunc(DELTA_TIME, Render, 0);
}

/// <summary>
/// A method to buffer everything before rendering it. 
/// </summary>
void Buffer() 
{
    EB.BufferAllEntities(camera.CurrentMode.view,camera.CurrentMode.projection);
}

/// <summary>
/// A method to initialise everything related to Glut and Glew
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
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
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); enable for lines
    glewInit();
}

/// <summary>
/// The method starts everything.
/// </summary>
/// <param name="argc"></param>
/// <param name="argv"></param>
/// <returns></returns>
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