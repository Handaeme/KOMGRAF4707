#include <GL/glut.h>
#include <math.h>

// Koordinat awal titik A
float ax = 2.0f;
float ay = 5.0f;

// Koordinat titik B
float bx = 5.0f;
float by = 3.0f;

// Sudut rotasi dalam derajat
float rotationAngle = 0.0f;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Hitung perpindahan dari A ke B dengan rotasi
    float deltaX = bx - ax;
    float deltaY = by - ay;
    float distance = sqrt(deltaX * deltaX + deltaY * deltaY);
    
    // Hitung sudut rotasi
    float angle = atan2(deltaY, deltaX) * 180.0 / M_PI;

    glPushMatrix();
    
    // Terapkan transformasi rotasi
    glTranslatef(ax, ay, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    
    // Gambar garis A ke B
    glBegin(GL_LINES);
    glVertex2f(0.0, 0.0);
    glVertex2f(distance, 0.0);
    glEnd();
    
    glPopMatrix();
    
    glFlush();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 8, 0, 8);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 400);
    glutCreateWindow("OpenGL Rotation Transformation");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glutMainLoop();
    return 0;
}
