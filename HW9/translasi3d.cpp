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

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //perspektif
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60.0, 1.0, 1.0, 100.0);

    //kamera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

    drawAxes();

    // Gambar kubus pertama
    glPushMatrix();
    glColor3f(1.0, 0.0, 0.0); // Merah
    glTranslatef(0.0, -1.0, 0.0);
    glutSolidCube(1.0);
    glPopMatrix();

    // Gambar kubus kedua
    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0); // Biru
    glTranslatef(0.0, 0.0, 1.0);
    glutSolidCube(1.0);
    glPopMatrix();

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Translasi 3D");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}
