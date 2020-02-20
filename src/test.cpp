
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

#include <knoxh/util/funclib.h>
#include <knoxh/util/queue.h>
#include <knoxh/util/voidregistry.h>

#include <knoxh/graphics/texture.h>

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

//temporary method
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

void delWindow(void* ptr)
{
	delete reinterpret_cast<knoxh::Window*>(ptr);
}

void delTexture(void* ptr)
{
	delete reinterpret_cast<knoxh::Texture*>(ptr);
}

int main()
{
	knoxh::Engine engine(1024, 256, 32);

	glfwSetErrorCallback(knoxh::error_callback);

	if (!glfwInit())
	{
		return -1;
	}

	knoxh::Window* win = new knoxh::Window(1280, 720, "Knoxh Engine Test");

	win->setOpenGLVersion(4, 3);
	win->setSamples(0);
	win->forwardsCompatable(true);
	win->useProfileCore(true);

	win->createWindow();

	win->makeCurrent();

	knoxh::VoidRegistry reg(8, 4);
	short winType = reg.addType(&delWindow);
	int id = reg.addItem(win, winType);
	reinterpret_cast<knoxh::Window*>(reg.getItem(id))->printTitle();

	unsigned int err = glewInit();
	if (err != GLEW_OK)
	{
		fprintf(stderr, "Error: %s\n", glewGetErrorString(err));
	}

	std::cout << glGetString(GL_VERSION) << std::endl;

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);

	knoxh::Texture* t = new knoxh::Texture(knoxh::loadImage("res/coin.png"));
	knoxh::Texture* tt = new knoxh::Texture(knoxh::loadImage("res/cion.png"));

	short texType = reg.addType(&delTexture);

	reg.addItem(t, texType);
	reg.addItem(tt, texType);

	int* lcs = nullptr;
	int size;

	reg.getUsedLocations(lcs, size);
	printArray(lcs, size);
	reg.getFreeLocations(lcs, size);
	printArray(lcs, size);

	while (!win->shouldClose())
	{
		glfwPollEvents();
		win->swapBuffers();
	}

	reg.clear();

	glfwTerminate();

	return 0;
}
