#include <windows.h>
#include <GL/glut.h> 
#include <iostream> 
#include <math.h>
#include <conio.h> 
#include <stdlib.h>

#define _USE_MATH_DEFINES 
#define BITMAP_ID 0x4D42 

GLuint nombres_texturas[4];
int angulo;

void init(void);
void redraw(void);
void reshape(int, int);

BITMAPINFOHEADER bitmapInfoHeader;
unsigned char* bitmapData;

unsigned char* LoadBitmapFile(const char* filename, BITMAPINFOHEADER* bitmapInfoHeader)
{
    FILE* filePtr;
    errno_t err;

    BITMAPFILEHEADER bitmapFileHeader; // bitmap file header
    unsigned char* bitmapImage; // bitmap image data
    int imageIdx = 0; // index de la imagen
    unsigned char tempRGB;

    // Abrimos el archivo en modo binario utilizando fopen_s
    err = fopen_s(&filePtr, filename, "rb");
    if (err != 0) 
    {
        //printf("Error: no se pudo abrir el archivo %s.\n", filename);
        return NULL;
    }

    // Leemos el bitmap file header
    fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, filePtr);

    // Verificamos que esto es un archivo de mapa de bits
    if (bitmapFileHeader.bfType != BITMAP_ID) 
    {
        fclose(filePtr);
        return NULL;
    }

    // Leemos la información del bitmap header
    fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, filePtr);

    // Movemos el puntero al principio del mapa de bits
    fseek(filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

    // Guardamos suficiente memoria para el archivo
    bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

    // Verificamos la memoria
    if (!bitmapImage) 
    {
        free(bitmapImage);
        fclose(filePtr);
        return NULL;
    }

    // Leemos los datos de la imagen
    fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, filePtr);
    if (bitmapImage == NULL) 
    {
        fclose(filePtr);
        return NULL;
    }

    // Convertimos la imagen a formato RGB
    for (imageIdx = 0; imageIdx < (int)bitmapInfoHeader->biSizeImage; imageIdx += 3) 
    {
        tempRGB = bitmapImage[imageIdx];
        bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
        bitmapImage[imageIdx + 2] = tempRGB;
    }

    // Cerramos el archivo y devolvemos la imagen
    fclose(filePtr);
    return bitmapImage;
}

void init(void) 
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // color de fondo de pantalla 
    glEnable(GL_CULL_FACE);
    glEnable(GL_DEPTH_TEST); // test de profundidad
    glShadeModel(GL_SMOOTH); // modo de sombreado de los polígonos 
    glMatrixMode(GL_MODELVIEW);
    gluLookAt(3, -3, 3, 0, 0, 0, 0, 1, 0);
    glEnable(GL_TEXTURE_2D);

    // Generamos las texturas
    glGenTextures(1, &nombres_texturas[0]);
    glBindTexture(GL_TEXTURE_2D, nombres_texturas[0]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    bitmapData = LoadBitmapFile("hierba.bmp", &bitmapInfoHeader);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

    // Textura 2
    glGenTextures(1, &nombres_texturas[1]);
    glBindTexture(GL_TEXTURE_2D, nombres_texturas[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    bitmapData = LoadBitmapFile("carbono.bmp", &bitmapInfoHeader);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

    // Textura 3
    glGenTextures(1, &nombres_texturas[2]);
    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    bitmapData = LoadBitmapFile("caliza_roja.bmp", &bitmapInfoHeader);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);
    
    // Textura 4
    glGenTextures(1, &nombres_texturas[3]);
    glBindTexture(GL_TEXTURE_2D, nombres_texturas[3]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    bitmapData = LoadBitmapFile("diamante.bmp", &bitmapInfoHeader);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bitmapInfoHeader.biWidth, bitmapInfoHeader.biHeight, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);
} 

void animacion(void) 
{
    angulo = (angulo + 1) % 360;
    Sleep(50);
    glutPostRedisplay();
}

void redraw() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glRotatef(angulo, 0, 1, 0);

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[0]);
    // Lado frontal
    glBegin(GL_POLYGON);
    glColor3f(0.0, 0.0, 1.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0, 1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1, 0, 1);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0, 2, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[1]);
    // Lado derecho
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 0.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1, 0, 1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(1, 0, -1);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0, 2, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[3]);
    // Lado izquierdo
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0, -1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1, 0, 1);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0, 2, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    // Lado trasero
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(1, 0, -1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1, 0, -1);
    glTexCoord2f(0.5f, 1.0f);
    glVertex3f(0, 2, 0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    // Base del triángulo
    glBegin(GL_POLYGON);
    glColor3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-1, 0, 1);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-1, 0, -1);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(1, 0, -1);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(1, 0, 1);
    glEnd();
    glPopMatrix();
    

    glPushMatrix();
    glRotatef(angulo, 0, 1, 0);
    glTranslatef(0.0f, -0.7f, 0.0f);

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    glBegin(GL_QUADS);
    // cara frontal
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();


    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    glBegin(GL_QUADS);
    // cara trasera
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    glBegin(GL_QUADS);
    // cara lateral izq
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    glBegin(GL_QUADS);
    // cara derecha
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    glBegin(GL_QUADS);
    // cara superior
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, 0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, 0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, 0.5f, 0.5f);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, nombres_texturas[2]);
    glBegin(GL_QUADS);
    // cara inferior
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(0.5f, -0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(0.5f, -0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-0.5f, -0.5f, 0.5f);
    glEnd();

    glPopMatrix();
    glutSwapBuffers();
}

void reshape(int anchura, int altura) 
{
    glViewport(0, 0, (GLsizei)anchura, (GLsizei)altura);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, (GLfloat)anchura / (GLfloat)altura, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char tecla, int x, int y) 
{
    if (tecla == 27) exit(0);
    if (tecla == 'a') glutIdleFunc(animacion);
    if (tecla == 'p') glutIdleFunc(NULL);
}

int main(int argc, char* argv[]) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(620, 540);
    glutCreateWindow("Texturas");
    init();
    glutDisplayFunc(redraw);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
