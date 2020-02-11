#include "window.h"

#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

namespace knoxh
{
	//deconstruction
	Window::~Window()
	{
		std::cout << "Deleting Window \"" << this->title << "\" at " << window << std::endl;
		glfwDestroyWindow(window);
	}

	//constructor
	Window::Window(const int width, const int height)
	{
		this->width = width;
		this->height = height;
		this->title = "Knoxh Window";
	}

	void Window::createWindow(const int hints[], const int hint_count)
	{

		for (int i = 0; i < hint_count; i+=2)
		{
			glfwWindowHint(hints[i], hints[i+1]);
		}
		this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
	}

	void Window::printTitle()
	{
		std::cout << this->title << std::endl;
	}

	GLFWwindow* Window::getWindow()
	{
		return this->window;
	}
}
