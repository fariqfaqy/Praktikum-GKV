#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

float posisiX = -0.5;
float kecepatan = 0.03;
float sudut = 0;

void gambarLingkaran(float x, float y, float r) {
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 3.14159f / 180;
        glVertex2f(x + cos(theta) * r, y + sin(theta) * r);
    }
    glEnd();
}

void gambarJalan() {
    glColor3f(0.3f, 0.3f, 0.3f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.2f);
    glVertex2f(1.0f, -0.2f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(-1.0f, -0.8f);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    for (float i = -1.0f; i < 1.0f; i += 0.2f) {
        glBegin(GL_QUADS);
        glVertex2f(i, -0.48f);
        glVertex2f(i + 0.1f, -0.48f);
        glVertex2f(i + 0.1f, -0.52f);
        glVertex2f(i, -0.52f);
        glEnd();
    }
}

void gambarRumput() {
    glColor3f(0.0f, 0.8f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-1.0f, -0.8f);
    glVertex2f(1.0f, -0.8f);
    glVertex2f(1.0f, -1.0f);
    glVertex2f(-1.0f, -1.0f);
    glEnd();
}

void gambarMatahari() {
    glColor3f(1.0f, 1.0f, 0.0f);
    gambarLingkaran(0.8f, 0.8f, 0.1f);
}

void gambarAwan(float x, float y) {
    glColor3f(0.9f, 0.9f, 0.9f);
    gambarLingkaran(x, y, 0.05f);
    gambarLingkaran(x + 0.05f, y, 0.05f);
    gambarLingkaran(x - 0.05f, y, 0.05f);
}

void gambarMobil() {
    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.35f, -0.08f);
    glVertex2f(0.35f, -0.08f);
    glVertex2f(0.32f, 0.08f);
    glVertex2f(-0.32f, 0.08f);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.8f);
    glBegin(GL_QUADS);
    glVertex2f(-0.18f, 0.08f);
    glVertex2f(0.18f, 0.08f);
    glVertex2f(0.14f, 0.15f);
    glVertex2f(-0.14f, 0.15f);
    glEnd();

    glColor3f(0.5f, 0.8f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.05f, 0.1f);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(0.0f, 0.13f);
    glVertex2f(-0.05f, 0.13f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(0.0f, 0.1f);
    glVertex2f(0.05f, 0.1f);
    glVertex2f(0.05f, 0.13f);
    glVertex2f(0.0f, 0.13f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(0.32f, -0.02f);
    glVertex2f(0.35f, -0.02f);
    glVertex2f(0.35f, 0.02f);
    glVertex2f(0.32f, 0.02f);
    glEnd();

    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(-0.35f, -0.02f);
    glVertex2f(-0.32f, -0.02f);
    glVertex2f(-0.32f, 0.02f);
    glVertex2f(-0.35f, 0.02f);
    glEnd();

    glPushMatrix();
    glTranslatef(-0.22f, -0.12f, 0.0f);
    glRotatef(sudut, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    gambarLingkaran(0.0f, 0.0f, 0.06f);
    glColor3f(0.7f, 0.7f, 0.7f);
    gambarLingkaran(0.0f, 0.0f, 0.03f);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.22f, -0.12f, 0.0f);
    glRotatef(sudut, 0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    gambarLingkaran(0.0f, 0.0f, 0.06f);
    glColor3f(0.7f, 0.7f, 0.7f);
    gambarLingkaran(0.0f, 0.0f, 0.03f);
    glPopMatrix();
}

void tampilan() {
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    gambarRumput();
    gambarJalan();
    gambarMatahari();
    gambarAwan(-0.6f, 0.7f);
    gambarAwan(0.4f, 0.6f);

    glPushMatrix();
    glTranslatef(posisiX, -0.3f, 0.0f);
    gambarMobil();
    glPopMatrix();

    glutSwapBuffers();
}

void tombol(unsigned char key, int x, int y) {
    if (key == 'a') posisiX -= kecepatan;
    if (key == 'd') posisiX += kecepatan;
    glutPostRedisplay();
}

void utama() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Mobil Balap");

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f);
    gluOrtho2D(-1.0f, 1.0f, -1.0f, 1.0f);

    glutDisplayFunc(tampilan);
    glutKeyboardFunc(tombol);
    glutMainLoop();
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    utama();
    return 0;
}

