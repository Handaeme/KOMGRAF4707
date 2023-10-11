#include <GL/glut.h>
#include <cmath>

// Koordinat titik awal dan akhir (statis)
static int x1 = 100, y1_coord = 100, x2 = 400, y2_coord = 400;

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

void setPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void DDA(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    int dx = x2 - x1;
    int dy = y2_coord - y1_coord; // Menggunakan y1_coord dan y2_coord
    int steps = std::max(abs(dx), abs(dy));

    float xIncrement = dx / (float)steps;
    float yIncrement = dy / (float)steps;

    float x = x1;
    float y = y1_coord; // Menggunakan y1_coord

    for (int i = 0; i <= steps; i++) {
        setPixel(round(x), round(y));
        x += xIncrement;
        y += yIncrement;
    }

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Line Drawing Algorithm");
    init();

    glutDisplayFunc(DDA);
    glutMainLoop();

    return 0;
}
