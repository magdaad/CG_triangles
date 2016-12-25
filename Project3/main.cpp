/*
When creating your project, uncheck OWL,
uncheck Class Library, select Static
instead of Dynamic and change the target
model to Console from GUI.
Also link glut.lib to your project once its done.
*/

#include <windows.h>   // Standard Header For Most Programs
#include <gl/gl.h>     // The GL Header File
#include <gl/glut.h>   // The GL Utility Toolkit (Glut) Header

float	rtri = 0.0f;							// Angle For The Triangle
float	revrtri = 360.0f;
void singleTriangle(float a, float b, float c, float d, float red = 1.0, float green = 1.0, float blue = 1.0) {
	glBegin(GL_TRIANGLES);								// Drawing Using Triangles
		glColor3f(red, green, blue);						// Set The Color To Red
		glVertex3f(a, b, 0.0f);					// Top
		glVertex3f(c, b, 0.0f);					// Bottom Left
		glVertex3f(a, d, 0.0f);					// Bottom Right
	glEnd();
}

void rotate(float scale = 0, float scaleY = 0, float x_avg = 0, float y_avg = 0, float angle = rtri) {
	glTranslatef(0, 0, -6.0f);
	glTranslatef(scale + x_avg, scaleY + y_avg, -6.0f);
	glRotatef(angle, 0.0, 0.0, 1);
	glTranslatef(-scale - x_avg, -scaleY - y_avg, -6.0f);
}

void drawTriangle(float a, float b, float c, float d, float red = 1.0, float green = 1.0, float blue = 1.0, float scale = 0, float scaleY = 0, float angle = 1) {
	GLfloat x_avg, y_avg;
	x_avg = (2 * a + c) / 3;
	y_avg = (2 * b + d) / 3;

	glPushMatrix();
	rotate(scale, scaleY, x_avg, y_avg, angle);
	singleTriangle(a, b, c, d, red, green, blue);
	glPopMatrix();	
}

GLfloat scale =  0.5f;
GLint counter = 0;

void display(void)   // Create The Display Function
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
								// Reset The Current Modelview Matrix
	glPushMatrix();
	glRotatef(3*rtri, 0, 0, 1.0);
	//blue
	drawTriangle(0.0f, 0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f, -scale, scale, -revrtri);
	drawTriangle(0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f, scale, scale, -revrtri);
	drawTriangle(0.0f, 0.0f, -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, -scale, -scale, -revrtri);
	drawTriangle(0.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, scale, -scale, -revrtri);
	glPopMatrix();

	glPushMatrix();
	glRotatef(-2*rtri, 0, 0, 1.0);
	//orange
	drawTriangle(0.0f, -1.0f, 1.0f, -2.0f, 1.0, 0.5, 0.0, scale, -2*scale, -revrtri);
	drawTriangle(-1.0f, 0.0f, -2.0f, -1.0f, 1.0, 0.5, 0.0, -2*scale, -scale, -revrtri);
	drawTriangle(0.0f, 1.0f, -1.0f, 2.0f, 1.0, 0.5, 0.0, -scale, 2*scale, -revrtri);
	drawTriangle(1.0f, 0.0f, 2.0f, 1.0f, 1.0, 0.5, 0.0, 2*scale, scale, -revrtri);
	//green
	drawTriangle(0.0f, -1.0f, -1.0f, -2.0f, 0.0f, 1.0f, 0.0f, -scale, -2 * scale, -revrtri);
	drawTriangle(-1.0f, 0.0f, -2.0f, 1.0f, 0.0f, 1.0f, 0.0f, -2 * scale, scale, -revrtri);
	drawTriangle(0.0f, 1.0f, 1.0f, 2.0f, 0.0f, 1.0f, 0.0f, scale, 2 * scale, -revrtri);
	drawTriangle(1.0f, 0.0f, 2.0f, -1.0f, 0.0f, 1.0f, 0.0f, 2 * scale, -scale, -revrtri);
	glPopMatrix();

	glPushMatrix();
	glRotatef(rtri, 0.0f, 0.0f, 1.0f);
	//violet
	drawTriangle(0.0f, -2.0f, 1.0f, -3.0f, 1.0, 0.0, 1.0, scale, -3*scale, revrtri);
	drawTriangle(-2.0f, 0.0f, -3.0f, -1.0f, 1.0, 0.0, 1.0, -3*scale, -scale, revrtri);
	drawTriangle(0.0f, 2.0f, -1.0f, 3.0f, 1.0, 0.0, 1.0, -scale, 3*scale, revrtri);
	drawTriangle(2.0f, 0.0f, 3.0f, 1.0f, 1.0, 0.0, 1.0, 3*scale, scale, revrtri);
	//red
	drawTriangle(0.0f, -2.0f, -1.0f, -3.0f, 1.0f, 0.0f, 0.0f, -scale, -3*scale, revrtri);
	drawTriangle(-2.0f, 0.0f, -3.0f, 1.0f, 1.0f, 0.0f, 0.0f, -3*scale, scale, revrtri);
	drawTriangle(0.0f, 2.0f, 1.0f, 3.0f, 1.0f, 0.0f, 0.0f, scale, 3*scale, revrtri);
	drawTriangle(2.0f, 0.0f, 3.0f, -1.0f, 1.0f, 0.0f, 0.0f, 3*scale, -scale, revrtri);
	//yellow
	drawTriangle(-1.0f, -1.0f, -2.0f, -2.0f, 1.0, 1.0, 0.0, -2.0* scale, -2.0* scale, revrtri);
	drawTriangle(-1.0f, 1.0f, -2.0f, 2.0f, 1.0, 1.0, 0.0, -2.0* scale, 2.0* scale, revrtri);
	drawTriangle(1.0f, 1.0f, 2.0f, 2.0f, 1.0, 1.0, 0.0, 2.0* scale, 2.0* scale, revrtri);
	drawTriangle(1.0f, -1.0f, 2.0f, -2.0f, 1.0, 1.0, 0.0, 2.0* scale, -2.0* scale, revrtri);
	glPopMatrix();

	glutSwapBuffers();
	// Swap The Buffers To Not Be Left With A Clear Screen
}

void update(int value)
{
	if (rtri < 360.0f){
		rtri += 0.125f;
		revrtri -= 0.5f;
	}
	else{
		rtri = 0.0f;
		revrtri = 360.0f;
	}

	//rtri += 4.0f;
	glutPostRedisplay();
	glutTimerFunc(2, update, 0);
}

void init(GLvoid)     // Create Some Everyday Functions
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glEnable(GL_COLOR_MATERIAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void reshape(int w, int h)   // Create The Reshape Function (the viewport)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);  // Select The Projection Matrix
	glLoadIdentity();                // Reset The Projection Matrix
	if (h == 0)  // Calculate The Aspect Ratio Of The Window
		gluPerspective(80, (float)w, 1.0, 5000.0);
	else
		gluPerspective(80, (float)w / (float)h, 1.0, 5000.0);
	glMatrixMode(GL_MODELVIEW);  // Select The Model View Matrix
	glLoadIdentity();    // Reset The Model View Matrix
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {
	case 27:        // When Escape Is Pressed...
		exit(0);   // Exit The Program
		break;        // Ready For Next Case
	default:        // Now Wrap It Up
		break;
	}
}

void arrow_keys(int a_keys, int x, int y)  // Create Special Function (required for arrow keys)
{
	switch (a_keys) {
	case GLUT_KEY_UP:     // When Up Arrow Is Pressed...
		glutFullScreen(); // Go Into Full Screen Mode
		break;
	case GLUT_KEY_DOWN:               // When Down Arrow Is Pressed...
		glutReshapeWindow(500, 500); // Go Into A 500 By 500 Window
		break;
	default:
		break;
	}
}

void main(int argc, char** argv)   // Create Main Function For Bringing It All Together
{
	glutInit(&argc, argv); // Erm Just Write It =)
	init();
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); // Display Mode
	glutInitWindowSize(500, 500); // If glutFullScreen wasn't called this is the window size
	glutCreateWindow("NeHe's OpenGL Framework"); // Window Title (argv[0] for current directory as title)
	glutFullScreen();          // Put Into Full Screen
	glutDisplayFunc(display);  // Matching Earlier Functions To Their Counterparts
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(arrow_keys);
	glutIdleFunc(display);
	glutTimerFunc(25, update, 0);
	glutMainLoop();          // Initialize The Main Loop
}