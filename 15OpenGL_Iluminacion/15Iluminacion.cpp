#include <GL/glut.h>

GLint ancho = 400;
GLint alto = 400;

// Caracteristicas de la LUZ
float light_ambient[] = { 0.0, 0.2, 0.0, 1.0 };
float light_diffuse_specular[] = { 0.8, 0.8, 0.8, 1.0 };
float light_pos[] = { 0.0, 0.0, 2.0, 1.0 };
float spot_dir[] = { 0.0, 0.0, -1.0 };
float spot_cutoff = 30.0;
float spot_exponent = 1.0;


// Material de la esfera
float mat_ambient_diffuse[] = { 0.0, 0.8, 1.0, 1.0 };
float mat_specular[] = { 0.7, 0.0, 0.0, 1.0 };
float mat_emission[] = { 0.0, 0.0, 0.0, 1.0 };
float mat_shininess = 0.4;

// Emision del foco y rotacion
float focus_emission[] = { 0.8, 0.8, 0.8, 1.0 };
float rot_angle_y = 0.0;
float rot_angle_x = 0.0;

void init() {
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);

	// Activar las luces
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	// Propiedades de la luz
	glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, GL_FALSE);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse_specular);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_diffuse_specular);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, spot_cutoff);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, spot_exponent);
	
	// Material de la esfera
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_ambient_diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialf(GL_FRONT, GL_SHININESS, mat_shininess);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	// Posicionia y rota la luz
	glPushMatrix();
	glRotatef(30.0, 0.0, 0.0, 1.0);
	glRotatef(rot_angle_y, 0.0, 1.0, 0.0);
	glRotatef(rot_angle_x, 1.0, 0.0, 0.0);

	glLightfv(GL_LIGHT0, GL_POSITION, light_pos);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, spot_dir);
	
	// Dibujar cono de luz
	glTranslatef(light_pos[0], light_pos[1], light_pos[2]);

	// Emision para el cono
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT, GL_EMISSION);
	glColor4fv(focus_emission);
	glutSolidCone(0.2, 0.5, 7, 7);

	// Restaurar el color de emisión de la esfera
	glColor4fv(mat_emission);
	glDisable(GL_COLOR_MATERIAL);
	glPopMatrix();

	// Dibujar la esfera
	glutSolidSphere(1.0, 20, 20);

	glFlush();
	glutSwapBuffers();
}

void update() {
	rot_angle_y += 0.1f;
	if (rot_angle_y > 360.0f) rot_angle_y -= 360.0f;

	rot_angle_x += 0.05f;
	if (rot_angle_x > 360.0f) rot_angle_x -= 360.0f;

	glutPostRedisplay();
}

int main (int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowPosition(300, 300);
	glutInitWindowSize(ancho, alto);
	glutCreateWindow("Cubo Iluminado");

	init();
	glutDisplayFunc(display);
	glutIdleFunc(update);
	glutMainLoop();
	return 0;
}