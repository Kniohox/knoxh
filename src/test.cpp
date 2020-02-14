
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

	knoxh::Engine engine;

	//queue functionality test
	knoxh::Queue queue(4);

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5); //doesn't get added as queue is full
	queue.pop();
	queue.pop();
	queue.push(6);
	queue.push(7);
	queue.expand(1);
	queue.push(8);

	int* q;
	int s;

	queue.getQueue(q, s);
	std::cout << std::endl;
	printArray(q, s);
	std::cout << "Queue is working as expected if numbers are in order" << std::endl << std::endl;
	//end of queue test

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
