#include<gl/freeglut.h>
#include<math.h>
// angle of rotation for the camera direction
float angle = 0.0;
// actual vector representing the camera's direction
float lx = 0.0f, lz = -1.0f;
// XZ position of the camera
float x = 0.0f, z = 5.0f;

void changeSize(int w, int h)
{
	// Prevent a divide by zero, when window is too short
	// (you cant make a window of zero width).
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, w, h);

	// Set the correct perspective.
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);
}

void drawTree()
{

	glColor3f(0.4f, 0.2f, 0.0f);
	// Draw Trunk
	glPushMatrix();
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	GLUquadricObj* quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.2f, 0.2f, 1.0f, 32, 32);
	glPopMatrix();

	// Draw Branches
	glPushMatrix();
	glColor3f(0.0f, 0.6f, 0.0f);
	glTranslatef(0.0f, 0.5f, 0.0f);
	glutSolidSphere(0.5f, 8, 8);
	glTranslatef(0.0f, 0.5f, 0.0f);
	glutSolidSphere(0.4f, 8, 8);
	glTranslatef(0.0f, 0.5f, 0.0f);
	glutSolidSphere(0.3f, 8, 8);
	glPopMatrix();


}
void drawApple()
{
	// Draw stem
	glColor3f(0.5f, 0.3f, 0.0f); // brown color
	glPushMatrix();
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	GLUquadricObj* quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.05f, 0.05f, 0.4f, 32, 32);
	glPopMatrix();
	// Draw apple
	glColor3f(1.0f, 0.0f, 0.0f); // red color
	glPushMatrix();
	glTranslatef(0.0f, 0.3f, 0.0f);
	glutSolidSphere(0.3f, 32, 32);
	glTranslatef(0.1f, 0.1f, 0.2f);
	glutSolidSphere(0.1f, 32, 32);
	glTranslatef(-0.2f, 0.0f, 0.0f);
	glutSolidSphere(0.1f, 32, 32);
	glTranslatef(0.1f, -0.1f, -0.2f);
	glutSolidSphere(0.1f, 32, 32);
	glPopMatrix();
}

void drawFlower()
{
	// Draw stem
	glColor3f(0.0f, 0.8f, 0.0f);
	glPushMatrix();
	glRotatef(-90, 1.0f, 0.0f, 0.0f);
	GLUquadricObj* quadratic = gluNewQuadric();
	gluCylinder(quadratic, 0.1f, 0.1f, 1.0f, 32, 32);
	glPopMatrix();

	// Draw petals
	glColor3f(1.0f, 1.0f, 0.0f);
	glPushMatrix();
	glTranslatef(0.0f, 0.8f, 0.0f);
	glutSolidSphere(0.4f, 8, 8);
	glTranslatef(0.2f, 0.0f, 0.0f);
	glutSolidSphere(0.4f, 8, 8);
	glTranslatef(-0.4f, 0.0f, 0.0f);
	glutSolidSphere(0.4f, 8, 8);
	glTranslatef(0.2f, -0.2f, 0.0f);
	glutSolidSphere(0.4f, 8, 8);
	glTranslatef(0.0f, 0.4f, 0.0f);
	glutSolidSphere(0.4f, 8, 8);
	glPopMatrix();
}

void drawSun()
{
	glPushMatrix();

	// Set sun color to yellow
	glColor3f(1.0f, 1.0f, 0.0f);

	// Translate to sun position
	glTranslatef(0.0f, 10.0f, -10.0f);

	// Rotate sun around Y axis
	glRotatef(angle, 0.0f, 1.0f, 0.0f);

	// Draw sun as a sphere
	GLUquadricObj* quadratic = gluNewQuadric();
	gluSphere(quadratic, 1.0f, 32, 32);

	glPopMatrix();
}
int menu_id;

void menu(int choice) {
	switch (choice) {
	case 1:
		// Reset the game
		x = 0.0f;
		z = 5.0f;
		lx = 0.0f;
		lz = -1.0f;
		angle = 0.0f;
		break;
	case 2:
		// Quit the game
		exit(0);
		break;
	case 3:
		break;
	}
	glutPostRedisplay();
}

void createMenu() {
	menu_id = glutCreateMenu(menu);
	glutAddMenuEntry("Reset", 1);
	glutAddMenuEntry("Quit", 2);
	glutAddMenuEntry("About", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
}

void drawRoad()
{
	glColor3f(0.2f, 0.2f, 0.2f); // Set color to gray

	
	glPushMatrix();
	glScalef(50.0f, 0.09f, 4.0f); // Setează dimensiunile dreptunghiului
	glutSolidCube(1.0f); // Desenează dreptunghiul
	glPopMatrix();
	for (int i = 0; i <= 50; i++)
	{
		
		glColor3f(1.0f, 1.0f, 1.0f); // Set color to gray

		
		glPushMatrix();
		glTranslatef(25.0f - i, 0.0f, 0.0f);
		glScalef(0.5f, 0.1f, 0.3f); // Setează dimensiunile dreptunghiului
		glutSolidCube(1.0f); // Desenează dreptunghiul
		glPopMatrix();
	}
}

void drawPoliceCar()
{


	// Set car color
	glColor3f(1.0f, 1.0f, 1.0f);

	// Draw car body
	glPushMatrix();
	glTranslatef(12.0f, 0.6f, 0.0f);
	glScalef(2.0f, 0.5f, 1.0f);
	glutSolidCube(1.0f);
	glPopMatrix();


	glColor3f(0.0f, 0.0f, 1.0f);
	glPushMatrix();
	glTranslatef(12.8f, 1.1f, 0.0f);
	glScalef(0.5f, 0.5f, 1.0f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(12.8f, 1.4f, 0.0f);
	glScalef(0.1f, 0.1f, 1.0f);
	glutSolidCube(1.0f);
	glPopMatrix();


	// Set window color
	glColor3f(0.8f, 0.8f, 1.0f);



	glPushMatrix();
	glTranslatef(12.5f, 0.9f, 0.0f);
	glScalef(0.01f, 0.6f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Far
	glColor3f(0.8f, 0.8f, 0.8f);



	glPushMatrix();
	glTranslatef(11.0f, 0.7f, 0.0f);
	glScalef(0.01f, 0.2f, 0.5f);
	glutSolidCube(1.0f);
	glPopMatrix();

	/*
	// Draw front window
	glPushMatrix();
	glTranslatef(12.0f, 0.9f, 0.5f);
	glScalef(1.4f, 0.6f, 0.01f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Draw side windows
	glPushMatrix();
	glTranslatef(11.5f, 0.9f, 0.0f);
	glScalef(0.01f, 0.6f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12.5f, 0.9f, 0.0f);
	glScalef(0.01f, 0.6f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Draw back window
	glPushMatrix();
	glTranslatef(12.0f, 0.9f, -0.5f);
	glScalef(1.4f, 0.6f, 0.01f);
	glutSolidCube(1.0f);
	glPopMatrix();*/

	// Draw car wheels
	glColor3f(0.0f, 0.0f, 0.0f); // Set wheel color to black

	// Front left wheel
	glPushMatrix();
	glTranslatef(11.2f, 0.5f, 0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();

	// Front right wheel
	glPushMatrix();
	glTranslatef(12.8f, 0.5f, 0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();

	// Back left wheel
	glPushMatrix();
	glTranslatef(11.2f, 0.5f, -0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();

	// Back right wheel
	glPushMatrix();
	glTranslatef(12.8f, 0.5f, -0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();
}


void drawCar()
{
	

	// Set car color
	glColor3f(1.0f, 0.5f, 0.0f);

	// Draw car body
	glPushMatrix();
	glTranslatef(12.0f, 0.6f, 0.0f);
	glScalef(2.0f, 0.5f, 1.0f);
	glutSolidCube(1.0f);
	glPopMatrix();


	glColor3f(0.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(12.8f, 1.1f, 0.0f);
	glScalef(0.5f, 0.5f, 1.0f);
	glutSolidCube(1.0f);
	glPopMatrix();


	// Set window color
	glColor3f(0.8f, 0.8f, 1.0f);



	glPushMatrix();
	glTranslatef(12.5f, 0.9f, 0.0f);
	glScalef(0.01f, 0.6f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Far
	glColor3f(0.8f, 0.8f, 0.8f);



	glPushMatrix();
	glTranslatef(11.0f, 0.7f, 0.0f);
	glScalef(0.01f, 0.2f, 0.5f);
	glutSolidCube(1.0f);
	glPopMatrix();

	/*
	// Draw front window
	glPushMatrix();
	glTranslatef(12.0f, 0.9f, 0.5f);
	glScalef(1.4f, 0.6f, 0.01f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Draw side windows
	glPushMatrix();
	glTranslatef(11.5f, 0.9f, 0.0f);
	glScalef(0.01f, 0.6f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(12.5f, 0.9f, 0.0f);
	glScalef(0.01f, 0.6f, 0.8f);
	glutSolidCube(1.0f);
	glPopMatrix();

	// Draw back window
	glPushMatrix();
	glTranslatef(12.0f, 0.9f, -0.5f);
	glScalef(1.4f, 0.6f, 0.01f);
	glutSolidCube(1.0f);
	glPopMatrix();*/

	// Draw car wheels
	glColor3f(0.0f, 0.0f, 0.0f); // Set wheel color to black

	// Front left wheel
	glPushMatrix();
	glTranslatef(11.2f, 0.5f, 0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();

	// Front right wheel
	glPushMatrix();
	glTranslatef(12.8f, 0.5f, 0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();

	// Back left wheel
	glPushMatrix();
	glTranslatef(11.2f, 0.5f, -0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();

	// Back right wheel
	glPushMatrix();
	glTranslatef(12.8f, 0.5f, -0.6f);
	glutSolidTorus(0.2f, 0.3f, 16, 16);
	glPopMatrix();
}



void renderScene(void)
{
	
	glClearColor(0.5f, 0.5f, 1.0f, 1.0f);
	// Clear Color and Depth Buffers
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Reset transformations
	glLoadIdentity();
	// Set the camera
	gluLookAt(x, 1.0f, z,
		x + lx, 1.0f, z + lz,
		0.0f, 1.0f, 0.0f);


	drawRoad(); // Desenează strada
	// Draw ground
	glColor3f(0.6f, 0.8f, 0.6f);
	glBegin(GL_QUADS);
	glVertex3f(-100.0f, 0.0f, -100.0f);
	glVertex3f(-100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, 100.0f);
	glVertex3f(100.0f, 0.0f, -100.0f);
	glEnd();

	drawSun();
	glPushMatrix();
	glTranslatef(-10.0f, 0.0f, 0.0f);
	drawCar();
	glPopMatrix();
	drawPoliceCar();
	// Draw 36 Tree and flowers
	for (int i = -3; i < 3; i++)
		for (int j = -3; j < 3; j++)
		{
			glPushMatrix();
			glTranslatef(i * 10.0+16, 0, j * 10.0 - 5);
			drawTree();
			glPopMatrix();

			glPushMatrix();
			glTranslatef(i * 10.0 + 5, 0, j * 10.0 - 7);
			glScalef(0.5f, 0.5f, 0.5f);
			drawFlower();
			glPopMatrix();


			glPushMatrix();
			glTranslatef(i * 10.0 + 10, 0, j * 10.0 + 6);
			glScalef(0.8f, 0.8f, 0.8f);
			drawApple();
			glPopMatrix();
		}
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	float fraction = 0.1f;
	switch (key)
	{
	case 'a':
		angle -= 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
		break;
	case 'd':
		angle += 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case 'w':
		x += lx * fraction;
		z += lz * fraction;
		break;
	case 's':
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}

	if (key == 27)
		exit(0);
}

void processSpecialKeys(int key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key)
	{
	case GLUT_KEY_LEFT:
		angle -= 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_RIGHT:
		angle += 0.01f;
		lx = sin(angle);
		lz = -cos(angle);
		break;
	case GLUT_KEY_UP:
		x += lx * fraction;
		z += lz * fraction;
		break;
	case GLUT_KEY_DOWN:
		x -= lx * fraction;
		z -= lz * fraction;
		break;
	}
}

int main(int argc, char** argv)
{

	// init GLUT and create window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Scena 3D cu oameni de zapada");

	// register callbacks
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// OpenGL init
	glEnable(GL_DEPTH_TEST);

	// Create the menu
	createMenu();

	// enter GLUT event processing cycle
	glutMainLoop();

	return 1;
}