#include <GL/glut.h>
#include <cstdlib>
#include <stdio.h>

GLfloat anguloCubo = 0.0f;

GLint ancho = 400;
GLint alto = 400;
int hazPerspectiva = 0;
int angulo = 0;
int ratonX = 0, ratonY = 0, anguloFiguraY = 0;
float rotacionNoria = 0.2f;
bool clicIzquierdoPresionado = false;

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (hazPerspectiva)
        gluPerspective(60.0f, (GLfloat)width / (GLfloat)height, 1.0f, 20.0f);
    else
        glOrtho(-4, 4, -4, 4, 1, 10);

    glMatrixMode(GL_MODELVIEW);
    ancho = width;
    alto = height;
}

void drawCube(void) {
    glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS); // cara frontal
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS); // cara trasera
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glEnd();

    glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); // cara lateral izq
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS); // cara lateral derecha
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glEnd();

    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS); // cara superior
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glEnd();

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); // cara inferior
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glRotatef(anguloFiguraY, 1.0f, 0.0f, 0.0f);

    for (int i = 0; i < 8; i++)
    {
        glPushMatrix();
        glRotatef(anguloCubo + angulo, 0.0f, 0.0f, 1.0f);
        glTranslatef(3.0f, 0.0f, 0.0f);
        // Para conseguir el efecto noria simplemente rotarlo hacia el lado contrario en su eje
        glRotatef(-(anguloCubo + angulo), 0.0f, 0.0f, 1.0f);
        drawCube();
        glPopMatrix();
        angulo += 45;
    }

    glFlush();
    glutSwapBuffers();
    anguloCubo += rotacionNoria;
}

void init() {
    glClearColor(0, 0, 0, 0);
    glEnable(GL_DEPTH_TEST);
    ancho = 400;
    alto = 400;
}

void idle() {
    display();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'p':
    case 'P':
        hazPerspectiva = 1;
        reshape(ancho, alto);
        break;
    case 'o':
    case 'O':
        hazPerspectiva = 0;
        reshape(ancho, alto);
        break;
    case 'r':
    case 'R':
        if (rotacionNoria < 0.0f)
        {
            rotacionNoria = 0.2f;
        }
        else 
        {
            rotacionNoria = -0.2f;
        }
        break;
    case 27: // escape
        exit(0);
        break;
    }
}

void raton(int Button, int State, int x, int y) {
    ratonX = x;
    ratonY = y;
}

void moverRaton(int x, int y) {
    printf("Moviendo raton en posicion (%d, %d)\n", x, y);
    anguloFiguraY += (x - ratonX);
    ratonX = x;
    ratonY = y;
    display();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(300, 300);
    glutInitWindowSize(ancho, alto);
    glutCreateWindow("Noria");

    
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(raton);
    glutMotionFunc(moverRaton);
    glutMainLoop();
    return 0;
}