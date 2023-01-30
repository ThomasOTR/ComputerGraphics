#include <GL/glew.h>
#include <GL/freeglut.h>
#include "InputHandler.h"
#include "Shape Classes/Pyramid.h"
#include "environment_builder.h"

const unsigned int WIDTH = 800, HEIGHT = 600;
unsigned const int DELTA_TIME = 10;

InputHandler IH;
Camera camera;
EnvironmentBuilder EB;

void ReshapeCallback(int width, int height)
{
    glViewport(0, 0, width, height);
}
void KeyboardCallback(unsigned char key, int a, int b)
{
    camera = IH.processKeyInput(camera, key);
}
void MouseCallback(int x, int y) {
    camera = IH.processMouseInput(camera, x, y);
}

void Render() {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

   camera.CalculateViewMatrix();
   EB.RenderAllEntities(camera.currentMode.view, camera.currentMode.projection);

    glutSwapBuffers();
}
void Render(int n)
{
    Render();
    glutTimerFunc(DELTA_TIME, Render, 0);
}
void Buffer() {
    EB.BufferAllEntities(camera.currentMode.view,camera.currentMode.projection);
}

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
