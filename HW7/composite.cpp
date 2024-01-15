#include <GL/glut.h>

float translateX = 0.0f;
float translateY = 0.0f;
float rotateAngle = 0.0f;
float scale = 1.0f;
float speed = 0.1f;
float rotateSpeed = 5.0f;
float scaleSpeed = 0.1f;

//warna background
void initialize() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glEnable(GL_DEPTH_TEST);
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Transformasi: translasi, rotasi, dan scaling
    glTranslatef(translateX, translateY, 0.0f);
    glRotatef(rotateAngle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, scale);

    // Menggambar kotak
    glBegin(GL_QUADS);
        glColor3f(1.0, 0.0, 0.0); glVertex2f(-0.5, -0.5);
        glColor3f(0.0, 1.0, 0.0); glVertex2f(0.5, -0.5);
        glColor3f(0.0, 0.0, 1.0); glVertex2f(0.5, 0.5);
        glColor3f(1.0, 1.0, 0.0); glVertex2f(-0.5, 0.5);
    glEnd();

    glFlush();
    glutSwapBuffers();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':
        case 'A':
            translateX -= speed;
            break;
        case 'd':
        case 'D':
            translateX += speed;
            break;
        case 'w':
        case 'W':
            translateY += speed;
            break;
        case 's':
        case 'S':
            translateY -= speed;
            break;
        case 'r':
            rotateAngle += rotateSpeed;
            break;
        case 'R':
            rotateAngle -= rotateSpeed;
            break;
        case '+':
            scale += scaleSpeed;
            break;
        case '-':
            if (scale > scaleSpeed) { // Hindari scaling negatif
                scale -= scaleSpeed;
            }
            break;
        case 27: // ESC key
            exit(0);
    }

    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutCreateWindow(" OpenGL Composite");

    initialize();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
