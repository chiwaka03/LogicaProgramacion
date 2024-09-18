#include <Windows.h>
#include <GL/glut.h>


void display(void) {

	glClearColor(0.0, 0.0, 0.0, 0.0); // Color de fondo: negro

	glClear(GL_COLOR_BUFFER_BIT); // Borramos la pantalla

	glMatrixMode(GL_PROJECTION); // Modo proyeccion glLoadIdentity(); 

	//Cargamos la matriz identidad

	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	// Proyeccion ortografica, dentro del cubose�alado

	glMatrixMode(GL_MODELVIEW); // Modo de modelado

	glBegin(GL_TRIANGLES); // Dibujamos un triangulo

	glColor3f(1.0, 0.0, 0.0); // Color rojo
	glVertex3f(0.0, 0.8, 0.0); // Vertice 1

	glColor3f(0.0, 1.0, 0.0);  // Color Verde
	
	glVertex3f(-0.6, -0.2, 0.0); // Vertice 2

	glColor3f(0.0, 0.0, 1.0);  // Color Azul

	glVertex3f(0.6, -0.2, 0.0); // Color del tercer vertice

	glEnd(); // Terminamos de dibujar

	glFlush(); // Forzamos el dibujado

	Sleep(5); // Esperamos 10 segundos exit(0); // Salimos del programa
}





int main(int argc, char* argv) {

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowPosition(20, 20);

	glutInitWindowSize(500, 500);

	glutCreateWindow("OpenGL");

	glutDisplayFunc(display);

	glutMainLoop();

	return 0;
}