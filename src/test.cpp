
//standard c++ libs
#include <iostream>
#include <filesystem>

//glfw and openGL libs
#ifndef GLEW_STATIC
#define GLEW_STATIC
#endif
#include <GL/glew.h>
#include <GLFW/glfw3.h>


//knoxh engine libs
#include <knoxh/core/window.h>
#include <knoxh/core/engine.h>

#include <knoxh/util/registry.h>
#include <knoxh/util/funclib.h>
#include <knoxh/util/queue.h>

#include <knoxh/graphics/texture.h>

//#define ARRAYSIZE(a) (sizeof(a)/sizeof(a[0]))

void printArray(int* array, int size)
{
	std::cout << "[ " << array[0];
	for (int i = 1; i < size; i++)
	{
		std::cout << ", " << array[i];
	}
	std::cout << " ]" << std::endl;
}

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

int main()
{
	knoxh::Registry reg(8);
	knoxh::Window* windows[reg.getSize()];

	std::cout << GL_R8 << ", " << GL_RG8 << ", " << GL_RGB8 << ", " << GL_RGBA8 << std::endl;

	knoxh::Engine engine(1024, 8, 256, 32);

	glfwSetErrorCallback(knoxh::error_callback);

	if (!glfwInit())
	{
		return -1;
	}

	knoxh::Window win(1280, 720, "Knoxh Engine Test");
	win.createWindow();

	win.makeCurrent();

	GLenum err = glewInit();
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	// During init, enable debug output
	glEnable              ( GL_DEBUG_OUTPUT );
	glDebugMessageCallback( MessageCallback, 0 );

	knoxh::Texture* t = new knoxh::Texture(knoxh::loadImage("res/coin.png"));

	delete t;

	while (!win.shouldClose())
	{
		glfwPollEvents();
		win.swapBuffers();
	}

	delete &win;

	glfwTerminate();

	return 0;
}
