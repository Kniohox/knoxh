#pragma once

#include <GLFW/glfw3.h>
#include <string>

namespace knoxh
{
	class Window
	{
	private:
		GLFWwindow* m_window = nullptr;
		int m_width;
		int m_height;
		std::string m_title;

		/*
		WINDOW HINTS
		*/

		int m_versionMajor = 4;
		//opengl 4.x
		int m_versionMinor = 3;
		//opengl x.3
		int m_forwardsCompatable = GLFW_FALSE;
		//opengl forwards compatability (true means depreciated functions are disabled)
		int m_profile = GLFW_OPENGL_COMPAT_PROFILE;
		//which opengl profile to use (core disables depreciated functions)

		int m_samples = 0;
		//multisampling samples
		int m_resizeable = GLFW_TRUE;
		//self explanitory
	public:
		void printTitle();

		Window(const int width, const int height);
		/*
		Window constructor, sets with and height
		*/

		Window(const int width, const int height, std::string title);
		/*
		Window constructor, sets width, height, and title
		*/

		void setOpenGLVersion(const int major, const int minor);
		/*
		sets the openGL version to use
		*/

		void setSamples(const int samples);
		/*
		sets the samples to be used in multisampling
		*/

		void useProfileCore(const bool use);
		/*
		sets whether or not to use openGL core or compatability profile
		*/

		void forwardsCompatable(const bool forwardsCompatable);
		/*
		sets whether or not to use forwards compatability (disable depreciated methods)
		*/

		void resizable(const bool resizable);
		/*
		sets whether or not the window will be resizable
		*/

		void createWindow();
		/*
		Creates GLFW window with previously set options
		*/

		void createWindow(const int hints[], const int hintCount);
		/*
		Creates GLFW window with chosen window hints
		*/

		GLFWwindow* getWindow();
		/*
		temporary method to return GLFWwindow pointer
		*/

		void makeCurrent();
		/*
		calls glfwMakeContextCurrent(window);
		*/

		void swapBuffers();
		/*
		calls glfwSwapBuffers(window);
		*/

		int shouldClose();
		/*
		returns glfwWindowShouldClose(window);
		*/

		void shouldClose(const int value);
		/*
		sets the should close property for the window
		*/

		~Window();
		/*
		Window deconstructor, deletes GLFWwindow window
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
		default hints to be used if none are given
		*/
	};

}
