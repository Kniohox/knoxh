#include <knoxh/core/window.h>

#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>

#include <GLFW/glfw3.h>

#include <string>
#include <iostream>

namespace knoxh
{
	void glfwErrorCallback(int error, const char* description)
	{
		fprintf(stderr, "GLFW ERROR\n%s\n", description);
	}

	//static method
	bool Window::init()
	{
		glfwSetErrorCallback(glfwErrorCallback);
		return glfwInit() == GLFW_TRUE ? true : false;
	}

	//static method
	void Window::terminateWindows()
	{
		glfwTerminate();
	}

	bool Window::initGL()
	{
		unsigned int error = glewInit();
		if (error != GLEW_OK)
		{
			fprintf(stderr, "OPENGL ERROR\n%s\n", glewGetErrorString(error));
			return false;
		}
		return true;
	}

	void Window::printTitle()
	{
		std::cout << "Title = " << m_title << std::endl;
	}

	//deconstruction
	Window::~Window()
	{
		if (m_window != nullptr)
		{
			destroy();
		}
	}

	//constructor
	Window::Window(const int width, const int height)
	{
		m_width = width;
		m_height = height;
		m_title = "Knoxh Window";
	}

	Window::Window(const int width, const int height, std::string title)
	{
		m_width = width;
		m_height = height;
		m_title = title;
	}

	void Window::setOpenGLVersion(const int major, const int minor)
	{
		m_versionMajor = major;
		m_versionMinor = minor;
	}

	void Window::setSamples(const int samples)
	{
		m_samples = samples;
	}

	void Window::useProfileCore(const bool use)
	{
		if (use)
		{
			m_profile = GLFW_OPENGL_CORE_PROFILE;
		}
		else
		{
			m_profile = GLFW_OPENGL_COMPAT_PROFILE;
		}
	}

	void Window::forwardsCompatable(const bool forwardsCompatable)
	{
		if (forwardsCompatable)
		{
			m_forwardsCompatable = GLFW_TRUE;
		}
		else
		{
			m_forwardsCompatable = GLFW_FALSE;
		}
	}

	void Window::createWindow()
	{
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, m_versionMajor);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, m_versionMinor);
		glfwWindowHint(GLFW_OPENGL_PROFILE, m_profile);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, m_forwardsCompatable);

		glfwWindowHint(GLFW_SAMPLES, m_samples);
		glfwWindowHint(GLFW_RESIZABLE, m_resizeable);

		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);

	}

	void Window::createWindow(const int hints[], const int hintCount)
	{

		for (int i = 0; i < hintCount; i+=2)
		{
			glfwWindowHint(hints[i], hints[i+1]);
		}
		m_window = glfwCreateWindow(m_width, m_height, m_title.c_str(), NULL, NULL);
	}

	GLFWwindow* Window::getWindow()
	{
		return m_window;
	}

	void Window::makeCurrent()
	{
		glfwMakeContextCurrent(m_window);
	}

	void Window::swapBuffers()
	{
		glfwSwapBuffers(m_window);
	}

	int Window::shouldClose()
	{
		return glfwWindowShouldClose(m_window);
	}

	void Window::shouldClose(const int value)
	{
		glfwSetWindowShouldClose(m_window, value);
	}

	void Window::destroy()
	{
		std::cout << "Deleting window \"" << m_title << "\" at " << m_window << std::endl;
		glfwDestroyWindow(m_window);
		m_window = nullptr;
	}
}
