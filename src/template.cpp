
//standard c++ libs
#include <iostream>

//glfw libs
#include <GLFW/glfw3.h>

static void error_callback(int, const char*);

int main()
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(1280, 720, "GLFW Template", NULL, NULL);

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwTerminate();

	return 0;
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
    _fgetchar();
}
