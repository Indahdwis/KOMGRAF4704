#ifdef __APPLE_CC__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <iostream>

using namespace std;

int xa = 14, ya = 2, xb = 2, yb = 10;

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

int maximum(int a, int b) {
    return (a > b) ? a : b;
}

void drawLineDDA(int xa, int ya, int xb, int yb) {
    int dx = xb - xa;
    int dy = yb - ya;
    int steps = maximum(abs(dx), abs(dy));
    float xIncrement = dx / static_cast<float>(steps);
    float yIncrement = dy / static_cast<float>(steps);
    float x = xa;
    float y = ya;

    for (int i = 0; i < steps; i++) {
        drawPixel(static_cast<int>(x), static_cast<int>(y));
        x += xIncrement;
        y += yIncrement;
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Warna putih

    drawLineDDA(xa, ya, xb, yb);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 20, 0, 20, -1, 1); // Menggunakan glOrtho untuk mengatur proyeksi
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
