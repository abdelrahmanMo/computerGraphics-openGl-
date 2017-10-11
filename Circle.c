
#include <GLFW/glfw3.h>
#include <math.h>
#include <time.h>
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius);
void processInput(GLFWwindow *window);
float r = 1.0, g = 0.0, b = 0.0;
float r2 = 0.0, g2 = 1.0, b2 = 0.0;
float r3 = 0.0, g3 = 0.0, b3 = 1.0;
int main(void)
{
	GLFWwindow *window;

	// Initialize the library
	if (!glfwInit())
	{
		return -1;
	}

	// Create a windowed mode window and its OpenGL context
	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	// Make the window's context current
	glfwMakeContextCurrent(window);

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT); 
	glMatrixMode(GL_PROJECTION);  
	glLoadIdentity(); 
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity(); 

					 
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		// render OpenGL here
		glColor3f(r, g, b);
		drawCircle(SCREEN_WIDTH / 3, SCREEN_HEIGHT / 2.9, 0, 100);
		glColor3f(r3, g3, b3);
		drawCircle(SCREEN_WIDTH / 1.9, SCREEN_HEIGHT / 1.5, 0, 100);
		glColor3f(r2, g2, b2);
		drawCircle(SCREEN_WIDTH / 1.37, SCREEN_HEIGHT / 2.87, 0, 100);
		
		// Swap front and back buffers
		glfwSwapBuffers(window);

		// Poll for and process events
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
void drawCircle(GLfloat x, GLfloat y, GLfloat z, GLfloat radius)
{


	GLfloat twicePi = 2.0f * 3.14;

	GLfloat circleVerticesX[363];
	GLfloat circleVerticesY[363];
	GLfloat circleVerticesZ[363];

	circleVerticesX[0] = x;
	circleVerticesY[0] = y;
	circleVerticesZ[0] = z;

	for (int i = 1; i < 363; i++)
	{
		circleVerticesX[i] = x + (radius * cos(i *  twicePi / 360));
		circleVerticesY[i] = y + (radius * sin(i * twicePi / 360));
		circleVerticesZ[i] = z;
	}

	GLfloat allCircleVertices[(363) * 3];

	for (int i = 0; i <363; i++)
	{
		allCircleVertices[i * 3] = circleVerticesX[i];
		allCircleVertices[(i * 3) + 1] = circleVerticesY[i];
		allCircleVertices[(i * 3) + 2] = circleVerticesZ[i];
	}

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 363);
	glDisableClientState(GL_VERTEX_ARRAY);
}
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
	else if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
	{
		if (r == 1.0 && g2 == 1.0&& b3 == 1.0)
		{
			r = 0.0;
			g = 1.0;
			b = 0.0;
			
			r2 = 0.0;
			g2 = 0.0;
			b2 = 1.0;

			r3 = 1.0;
			g3 = 0.0;
			b3 = 0.0;
		}
		else if (r3 == 1.0 &&g == 1.0&&b2 == 1.0)
		{
			r = 0.0;
			g = 0.0;
			b = 1.0;

			r2 = 1.0;
			g2 = 0.0;
			b2 = 0.0;

			r3 = 0.0;
			g3 = 1.0;
			b3 = 0.0;
		}
		else if (r2 == 1.0 &&g3 == 1.0&&b == 1.0)
		{
			r = 1.0;
			g = 0.0;
			b = 0.0;

			r2 = 0.0;
			g2 = 1.0;
			b2 = 0.0;

			r3 = 0.0;
			g3 = 0.0;
			b3 = 1.0;
		}
	}

}
