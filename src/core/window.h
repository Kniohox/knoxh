#ifndef WINDOW_H
#define WINDOW_H

#include <GLFW/glfw3.h>
#include <string>

namespace knoxh
{
	class Window
	{
	private:
		GLFWwindow *window;
		int width;
		int height;
		std::string title;
		//hints
	public:
		Window(int, int);
		void setHints(const int[]);
		void createWindow(const int[], const int);
		GLFWwindow* getWindow();
		~Window();
		void printTitle();
	};

}

#endif
