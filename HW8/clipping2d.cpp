#include <stdio.h>
#include <GL/glut.h>

int x_min = 50, y_min = 50, x_max = 250, y_max = 250; // Batas clipping window

int computeCode(double x, double y) {
    int code = 0;

    if (x < x_min) {
        code |= 1; // Kode untuk kiri
    }
    else if (x > x_max) {
        code |= 2; // Kode untuk kanan
    }

    if (y < y_min) {
        code |= 4; // Kode untuk bawah
    }
    else if (y > y_max) {
        code |= 8; // Kode untuk atas
    }

    return code;
}

void cohenSutherland(double x1, double y1, double x2, double y2) {
    int code1 = computeCode(x1, y1);
    int code2 = computeCode(x2, y2);
    double m;

    while ((code1 | code2) != 0) {
        if (code1 & code2) {
            // Kedua titik berada di luar window, keluar dari loop
            return;
        }

        double x, y;

        // Pilih titik yang di luar window
        int code_out = (code1 != 0) ? code1 : code2;

        // Hitung titik potong dengan window
        if (code_out & 1) {
            // Potong dengan sisi kiri
            y = y1 + (y2 - y1) * (x_min - x1) / (x2 - x1);
            x = x_min;
        }
        else if (code_out & 2) {
            // Potong dengan sisi kanan
            y = y1 + (y2 - y1) * (x_max - x1) / (x2 - x1);
            x = x_max;
        }
        else if (code_out & 4) {
            // Potong dengan sisi bawah
            x = x1 + (x2 - x1) * (y_min - y1) / (y2 - y1);
            y = y_min;
        }
        else {
            // Potong dengan sisi atas
            x = x1 + (x2 - x1) * (y_max - y1) / (y2 - y1);
            y = y_max;
        }

        // Ganti titik yang di luar window dengan titik potong
        if (code_out == code1) {
            x1 = x;
            y1 = y;
            code1 = computeCode(x1, y1);
        }
        else {
            x2 = x;
            y2 = y;
            code2 = computeCode(x2, y2);
        }
    }

    // Gambar garis yang sudah di-clip
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar window
    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x_min, y_min);
    glVertex2i(x_max, y_min);
    glVertex2i(x_max, y_max);
    glVertex2i(x_min, y_max);
    glEnd();

    // Gambar garis sebelum di-clip merah
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_LINES);
    glVertex2i(10,10);
    glVertex2i(300, 800);
    glEnd();

    // Panggil fungsi cohenSutherland untuk clip garis putih
    cohenSutherland(10, 10, 300, 800);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 400, 0, 300);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(400, 300);
    glutCreateWindow("Clipping Garis - Cohen-Sutherland");

    init();
    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}