#include <knoxh/core/window.h>

#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

namespace knoxh
{
	//deconstruction
	Window::~Window()
	{
		std::cout << "Deleting Window \"" << this->title << "\" at " << this << std::endl;
		glfwDestroyWindow(window);
	}

	//constructor
	Window::Window(const int width, const int height)
	{
		this->width = width;
		this->height = height;
		this->title = "Knoxh Window";
	}

	Window::Window(const int width, const int height, std::string title)
	{
		this->width = width;
		this->height = height;
		this->title = title;
	}

	void Window::createWindow()
	{
		this->createWindow(Window::DEFAULT_HINTS, sizeof(Window::DEFAULT_HINTS)/4);
	}

	void Window::createWindow(const int hints[], const int hint_count)
	{

		for (int i = 0; i < hint_count; i+=2)
		{
			glfwWindowHint(hints[i], hints[i+1]);
		}
		this->window = glfwCreateWindow(this->width, this->height, this->title.c_str(), NULL, NULL);
	}

	GLFWwindow* Window::getWindow()
	{
		return this->window;
	}

	void Window::makeCurrent()
	{
		glfwMakeContextCurrent(this->window);
	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(this->window);
	}

	int Window::shouldClose()
	{
		return glfwWindowShouldClose(this->window);
	}

	void Window::shouldClose(const int value)
	{
		glfwSetWindowShouldClose(this->window, value);
	}
}
