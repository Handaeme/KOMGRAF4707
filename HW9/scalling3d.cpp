#include <GL/glut.h>

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

void drawCube(float scale) {
    glPushMatrix();
    glScalef(scale, scale, scale); // Skala kubus
    glutWireCube(1.0);
    glPopMatrix();
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

    //skala asli
    glPushMatrix();
    glTranslatef(-1.5, 0.0, 0.0); // Geser ke kiri
    drawCube(1.0);
    glPopMatrix();

    // Skala yang ditentukan
    glPushMatrix();
    glTranslatef(1.5, 0.0, 0.0); // Geser ke kanan
    drawCube(2.0); //skala
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Scalling 3D");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
