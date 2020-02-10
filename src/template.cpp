
//standard c++ libs
#include <iostream>

//glfw libs
#include <GLFW/glfw3.h>

#include "core/window.h"

static void error_callback(int, const char*);

int main()
{
	GLFWwindow* window;

	glfwSetErrorCallback(error_callback);

	if (!glfwInit())
	{
		return -1;
	}

	int hints[] = {
		GLFW_CONTEXT_VERSION_MAJOR, 4,
		GLFW_CONTEXT_VERSION_MINOR, 3,
		GLFW_SAMPLES, 8,
		GLFW_RESIZABLE, GLFW_FALSE
	};

	knoxh::Window win(1280, 720);
	//win.setHints(hints);
	win.createWindow(hints, sizeof(hints)/sizeof(hints[0]));

	window = win.getWindow();

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	delete &win;

	glfwTerminate();

	return 0;
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
    _fgetchar();
}
