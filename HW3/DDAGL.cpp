#include <GL/glut.h>

int x0 = 4, y0 = 1;
int x1 = 8, y1 = 12;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0); // Warna garis (putih)
    glBegin(GL_LINES);
    glVertex2i(x0, y0);
    glVertex2i(x1, y1);
    glEnd();
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500); // Ukuran jendela
    glutInitWindowPosition(100, 100); // Posisi jendela
    glutCreateWindow("OpenGL Line"); // Judul jendela

    glOrtho(0, 20, 0, 20, -1, 1); // Mengatur koordinat jendela

    glutDisplayFunc(display); // Fungsi tampilan
    glutMainLoop();
    return 0;
}
