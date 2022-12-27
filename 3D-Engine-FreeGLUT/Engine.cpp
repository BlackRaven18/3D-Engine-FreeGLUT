#include "Engine.h"

Engine* Engine::instance = nullptr;
const int Engine::WINDOW_WIDTH = 1280;
const int Engine::WINDOW_HEIGHT = 720;
const char* Engine::APP_TITLE = "3D Game Engine!";

Engine::Engine() {
}

Engine::~Engine() {
}



Engine* Engine::getInstance() {
	if (instance == nullptr) {
		instance = new Engine();
	}
	return instance;
}


void Engine::init(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(glutGet(GLUT_SCREEN_WIDTH)/ 2 - WINDOW_WIDTH / 2, glutGet(GLUT_SCREEN_HEIGHT)/ 2 - WINDOW_HEIGHT / 2);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow(APP_TITLE);

	glutIdleFunc(update);
	glutDisplayFunc(render);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(keyboard);


}

void Engine::start() {
	glutMainLoop();
}


void Engine::update(void) {
	glLoadIdentity();

	/*gluLookAt(2.0f, 1.0f, z - 3,
		x + 1.5 + lx, 1.0f, z - 3 + lz,
		0.0f, 1.0f, 0.0f);*/
}


void Engine::render(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0, 0, -8);

	EasyFreeGLUTShapesDrawer shapesDrawer;
	//glColor3f(1, 0, 0);
	glColor3f(0, 1, 0);
	shapesDrawer.drawWireTeapot(4);
	//shapesDrawer.drawSolidSphere(2, 10, 10);

	/*glBegin(GL_TRIANGLES);
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);

	glColor3f(0, 1, 0);
	glVertex3f(-1, 0, 0);

	glColor3f(0, 0, 1);
	glVertex3f(1, 0, 0);
	glEnd();
	glFlush();*/

	glutSwapBuffers();
}



void Engine::changeSize(int w, int h) {

	if (h == 0)
		h = 1;

	float ratio = w * 1.0 / h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glViewport(0, 0, w, h);

	gluPerspective(45.0f, ratio, 0.1f, 100.0f);

	glMatrixMode(GL_MODELVIEW);
}

void Engine::keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case 27: // kod klawisza Esc
		exit(0);
		break;
	default:
		break;
	}
}