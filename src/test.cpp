
//standard c++ libs
#include <iostream>

//glfw libs
#include <GLFW/glfw3.h>

//knoxh engine libs
#include <knoxh/core/window.h>
#include <knoxh/core/engine.h>

#include <knoxh/util/registry.h>
#include <knoxh/util/funclib.h>
#include <knoxh/util/queue.h>

#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))

void printArray(int* array, int size)
{
	std::cout << "[ " << array[0];
	for (int i = 1; i < size; i++)
	{
		std::cout << ", " << array[i];
	}
	std::cout << " ]" << std::endl;
}

int main()
{
	knoxh::Registry reg(8);
	knoxh::Window* windows[reg.getSize()];

	knoxh::Engine engine(1024, 8, 256, 32);

	glfwSetErrorCallback(knoxh::error_callback);

	if (!glfwInit())
	{
		return -1;
	}

	knoxh::Window win(1280, 720, "Knoxh Engine Test");
	win.createWindow();

	win.makeCurrent();

	while (!win.shouldClose())
	{
		glfwPollEvents();
		win.swapBuffers();
	}

	delete &win;

	glfwTerminate();

	return 0;
}
