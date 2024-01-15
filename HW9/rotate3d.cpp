#include <GL/glut.h>
#include <cmath>

float angle = 0.0; // Variabel untuk sudut rotasi

void init() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0, 0.0, 0.0, 1.0);
}

void drawAxes() {
    glBegin(GL_LINES);
        // Sumbu X (Merah)
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(-100.0, 0.0, 0.0);
        glVertex3f(100.0, 0.0, 0.0);

        // Sumbu Y (Hijau)
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(0.0, -100.0, 0.0);
        glVertex3f(0.0, 100.0, 0.0);

        // Sumbu Z (Biru)
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(0.0, 0.0, -100.0);
        glVertex3f(0.0, 0.0, 100.0);
    glEnd();
}

void drawCube() {
    glutWireCube(1.0);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0, 3.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawAxes();

    // Gambar kubus yang berotasi
    glPushMatrix();
    glRotatef(angle, 1.0, 1.0, 0.0); // Rotasi pada sumbu x dan y
    drawCube();
    glPopMatrix();

    glutSwapBuffers();
}

void update(int value) {
    angle += 2.0f;
    if (angle > 360) {
        angle -= 360;
    }

    glutPostRedisplay(); // Meminta GLUT untuk memanggil fungsi display lagi
    glutTimerFunc(16, update, 0); // Setel timer sekitar 60 fps
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Rotate 3D");

    init();
    glutDisplayFunc(display);
    glutTimerFunc(25, update, 0); // Setel timer untuk rotasi

    glutMainLoop();
    return 0;
}
