
//standard c++ libs
#include <iostream>

//glfw libs
#include <GLFW/glfw3.h>

#include "core/window.h"
#include "core/util.h"

#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))

int main()
{
	GLFWwindow* window;

	glfwSetErrorCallback(knoxh::error_callback);

	if (!glfwInit())
	{
		return -1;
	}

	int hints[] = {
		//basic opengl info, can't be changed after opengl context creation
		GLFW_CONTEXT_VERSION_MAJOR, 4,
		GLFW_CONTEXT_VERSION_MINOR, 3,
		GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE, //forward compatability removes use of depreciated methods
		GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE, //compatability or core, compatability enables use of depreciated methods

		//window properties, can't be changed after window creation
		GLFW_RESIZABLE, GLFW_FALSE,

		//framebuffer properties, can't be changed after window creation
		GLFW_SAMPLES, 8, //0 disables multisampling
		GLFW_REFRESH_RATE, 0 //only applies to fullscreen, 0 says to use highest refresh rate available (monitor native refresh rate)
	};

	knoxh::Window win(1280, 720);
	//win.setHints(hints);
	win.createWindow(win.DEFAULT_HINTS, ARRAYSIZE(hints));

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
