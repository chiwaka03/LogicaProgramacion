#include <GL/glut.h>
#include <iostream>
#include <map>
// Utilizar lo que necesito asi bajando el tiempo de compilacion, C++ 17 para arriba
using std::cout, std::cin; 

void displayPoints(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	// Coordenadas aproximadas para las estrellas de la Osa Menor
	glVertex2f(0.0, 0.5);
	glVertex2f(-0.2, 0.3);
	glVertex2f(-0.4, 0.2);
	glVertex2f(-0.6, 0.1);
	glVertex2f(-0.4, -0.1);
	glVertex2f(-0.2, -0.3);
	glVertex2f(-0.5, -0.4);

	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayLines(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(50, 50, 0);
	glVertex3f(50, 100, 0);
	glVertex3f(0, 100, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 50, 50);

	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayLineStrip(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	glVertex3f(-0.5f, -0.5f, 0.0f); 
	glVertex3f(0.0f, 0.5f, 0.0f);   
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.8f, 0.8f, 0.0f);
	
	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayLineLoop(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.8f, 0.8f, 0.0f);
	
	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayTriangles(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.7);
	glBegin(GL_TRIANGLES);
	//Primer triangulo
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	// Segundo triangulo
	glVertex3f(0.6f, -0.4f, 0.0f);  
	glVertex3f(1.1f, 0.6f, 0.0f);   
	glVertex3f(1.6f, -0.4f, 0.0f);

	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayTrianglesStrip(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.7);
	glBegin(GL_TRIANGLE_STRIP);
	// Primer triangulo
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	// Segundo triangulo
	glVertex3f(0.6f, -0.4f, 0.0f);
	glVertex3f(1.1f, 0.6f, 0.0f);
	glVertex3f(1.6f, -0.4f, 0.0f);

	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayTriangleFan(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.7);
	glBegin(GL_TRIANGLE_FAN);
	// Primer triangulo
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.0f, 0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	// Segundo triangulo
	glVertex3f(0.6f, -0.4f, 0.0f);
	glVertex3f(1.1f, 0.6f, 0.0f);
	glVertex3f(1.6f, -0.4f, 0.0f);

	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayQuads(void) 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.7);
	glBegin(GL_QUADS);
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glEnd();
	glFlush(); // Forzamos el dibujado
}
void displayQuadsStrip(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.6, 0.2);

	glBegin(GL_QUAD_STRIP);
	// Icono de Kotlin
	glVertex3f(-0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, -0.5f, 0.0f);
	glVertex3f(0.5f, 0.5f, 0.0f);
	glVertex3f(-0.5f, 0.5f, 0.0f);

	glEnd();
	glFlush();	// Forzamos el dibujado
}
void displayPolygon(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.6, 0.2);

	glBegin(GL_POLYGON);
	
	glVertex3f(-0.5f, -0.1f, 0.0f);
	glVertex3f(0.5f, -0.9f, 0.0f);
	glVertex3f(0.5f, 0.34f, 0.0f);
	glVertex3f(-0.5f, 0.2f, 0.0f);

	glEnd();
	glFlush();	// Forzamos el dibujado
}


int main()
{
	int selection;
	// Creamos el mapa que asocia enteros con punteros a funciones
	std::map<int, void(*)()> functionMap;
	// Llenando el mapa
	functionMap[1] = displayPoints;
	functionMap[2] = displayLines;
	functionMap[3] = displayLineStrip;
	functionMap[4] = displayLineLoop;
	functionMap[5] = displayTriangles;
	functionMap[6] = displayTrianglesStrip;
	functionMap[7] = displayTriangleFan;
	functionMap[8] = displayQuads;
	functionMap[9] = displayQuadsStrip;
	functionMap[10] = displayPolygon;


	cout << "**************************************\n";
	cout << "Elige el tipo de objeto forma \n";
	cout << "geometrica primitiva que quieras ver:\n";
	cout << "1.- Gl_Points\n";
	cout << "2.- Gl_Lines\n";
	cout << "3.- Gl_Line_Strip\n";
	cout << "4.- Gl_Line_Loop\n";
	cout << "5.- Gl_Triangles\n";
	cout << "6.- Gl_Triangles_Strip\n";
	cout << "7.- Gl_Triangle_Fan\n";
	cout << "8.- Gl_Quads\n";
	cout << "9.- Gl_Quads_Strip\n";
	cout << "10.- Gl_Polygon\n";
	cout << "**************************************\n";
	
	cin >> selection;
	if (functionMap.find(selection) != functionMap.end())
	{
		glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
		glutInitWindowPosition(20, 20);
		glutInitWindowSize(500, 500);
		glutCreateWindow("OpenGL");
		glutDisplayFunc(functionMap[selection]);
		glutMainLoop();
		
	}
	else 
	{
		cout << "Elige una opcion valida entre el 1-10";
	}
	return 0;
}