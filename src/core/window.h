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
	public:
		Window(int width, int height);
		/*
		Window constructor, sets with and height
		*/

		void createWindow(const int hints[], const int hint_count);
		/*
		Creates GLFW window with chosen window hings
		*/

		GLFWwindow* getWindow();
		/*
		temporary method to return GLFWwindow pointer
		*/

		~Window();
		/*
		Window deconstructor
		*/

		void printTitle();
		/*
		test method, to be removed
		*/

		static constexpr int DEFAULT_HINTS[] = {
			//basic opengl info, can't be changed after opengl context creation
			GLFW_CONTEXT_VERSION_MAJOR, 4,
			GLFW_CONTEXT_VERSION_MINOR, 3,
			GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE, //forward compatability removes use of depreciated methods
			GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE, //compatability or core, compatability enables use of depreciated methods

			//window properties, can't be changed after window creation
			GLFW_RESIZABLE, GLFW_FALSE,

			//framebuffer properties, can't be changed after window creation
			GLFW_SAMPLES, 4, //0 disables multisampling
			GLFW_REFRESH_RATE, 0 //only applies to fullscreen, 0 says to use highest refresh rate available (monitor native refresh rate)
		};
		/*
		default hints to be used if none are given or if there as a simple standard for most openGL features to be available
		*/
	};

}

#endif
