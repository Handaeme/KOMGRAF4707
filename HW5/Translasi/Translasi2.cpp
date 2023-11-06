#include <GL/glut.h>

// Koordinat awal segitiga pertama (titik A, B, dan C)
float Ax1 = 1.0f, Ay1 = 3.0f;
float Bx1 = 5.0f, By1 = 2.0f;
float Cx1 = 3.0f, Cy1 = 5.0f;

// Koordinat awal segitiga kedua (titik D, E, dan F)
float Dx2 = 7.0f, Dy2 = 3.0f;
float Ex2 = 11.0f, Ey2 = 2.0f;
float Fx2 = 9.0f, Fy2 = 5.0f;

// Vektor pergeseran
float dx = 2.0f;
float dy = -1.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Translasikan titik segitiga pertama (A, B, C)
    Ax1 += dx;
    Ay1 += dy;
    Bx1 += dx;
    By1 += dy;
    Cx1 += dx;
    Cy1 += dy;

    // Translasikan titik segitiga kedua (D, E, F)
    Dx2 += dx;
    Dy2 += dy;
    Ex2 += dx;
    Ey2 += dy;
    Fx2 += dx;
    Fy2 += dy;

    glBegin(GL_TRIANGLES);
    glVertex2f(Ax1, Ay1); // Titik A'
    glVertex2f(Bx1, By1); // Titik B'
    glVertex2f(Cx1, Cy1); // Titik C'
    
    glVertex2f(Dx2, Dy2); // Titik D'
    glVertex2f(Ex2, Ey2); // Titik E'
    glVertex2f(Fx2, Fy2); // Titik F'
    glEnd();

    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Dua Segitiga Translasi");
    glutInitWindowSize(400, 400);
    glutDisplayFunc(display);
    glOrtho(0, 15, 0, 10, -1, 1);
    glutMainLoop();
    return 0;
}
