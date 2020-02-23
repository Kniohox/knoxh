
//standard c++ libs
#include <iostream>
#include <filesystem>

//glfw and openGL libs
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>

void GLAPIENTRY
MessageCallback( GLenum source,
                 GLenum type,
                 GLuint id,
                 GLenum severity,
                 GLsizei length,
                 const GLchar* message,
                 const void* userParam )
{
  fprintf( stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
           ( type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : "" ),
            type, severity, message );
}

//knoxh engine libs
#include <knoxh/core/window.h>
#include <knoxh/core/engine.h>

#include <knoxh/util/funclib.h>
#include <knoxh/util/queue.h>
#include <knoxh/util/voidregistry.h>

#include <knoxh/graphics/texture.h>
#include <knoxh/graphics/shader.h>

#include "basicshader.h"

void printArray(int* array, int size);

int init();
int loop();
int cleanup();

knoxh::Window* window;
knoxh::Shader* shaderTest;

int main()
{
	if (init() != 0)
	{
		return -1;
	}

	if (loop() != 0)
	{
		return -2;
	}

	if (cleanup() != 0)
	{
		return -3;
	}

	return 0;
}

int init()
{
	if (!knoxh::Window::init())
	{
		return -1;
	}

	window = new knoxh::Window(1280, 720, "Knoxh Engine Test");

	window->setOpenGLVersion(4, 3);
	window->setSamples(0);
	window->forwardsCompatable(true);
	window->useProfileCore(true);

	window->createWindow();

	window->makeCurrent();

	if (!window->initGL())
	{
		return -1;
	}

	glEnable              ( GL_DEBUG_OUTPUT );
	glDebugMessageCallback( MessageCallback, 0 );

	shaderTest = new BasicShader();
	shaderTest->init();

	return 0;
}

int loop()
{

	while (!window->shouldClose())
	{
		//need input manager to replace glfwPollEvents
		glfwPollEvents();
		window->swapBuffers();
	}
	return 0;
}

int cleanup()
{
	delete shaderTest;

	delete window;
	knoxh::Window::terminateWindows();

	return 0;
}

void printArray(int* array, int size)
{
	if (size == 0)
	{
		std::cout << "[ ]" << std::endl;
		return;
	}
	std::cout << "[ " << array[0];
	for (int i = 1; i < size; i++)
	{
		std::cout << ", " << array[i];
	}
	std::cout << " ]" << std::endl;
}
