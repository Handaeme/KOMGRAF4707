#include <GL/glut.h>
#include <iostream>

int startX = 300, startY = 500; // Koordinat titik awal
int endX = 500, endY = 200; // Koordinat titik akhir

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void bresenhamLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int p = 2 * dy - dx;
    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int x, y;

    if (x1 > x2) {
        x = x2;
        y = y2;
        x2 = x1;
    } else {
        x = x1;
        y = y1;
    }

    drawPixel(x, y);

    while (x < x2) {
        x++;
        if (p < 0) {
            p += twoDy;
        } else {
            if ((x2 > x1 && y2 > y1) || (x2 < x1 && y2 < y1)) {
                y++;
            } else {
                y--;
            }
            p += twoDyMinusDx;
        }
        drawPixel(x, y);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);

    bresenhamLine(startX, startY, endX, endY);

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glOrtho(0, 500, 0, 500, -1, 1);
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
