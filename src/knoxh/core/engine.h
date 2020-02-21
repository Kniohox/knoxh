#pragma once

#include <knoxh/core/window.h>

#include <knoxh/util/voidregistry.h>
#include <knoxh/util/queue.h>

#include <knoxh/graphics/texture.h>

//may or may not be used
typedef void* (*knoxh_loadFunc)(void* dataType);

namespace knoxh
{
	/*
	class for managing resources
	*/
	class Engine
	{
	private:
		VoidRegistry* m_registry;
		//VoidRegistry for storing items
		Queue* m_queue;
		//queue for items that have yet to be loaded
		//may or may not be used

	public:
		short m_typeid_texture;
		short m_typeid_window;

		~Engine();
		Engine(const int size);

		void deleteItem(const int id);
		/*
		delete item with index "id"
		*/

		void deleteItems(const int* ids, const int size);
		/*
		calls deleteItem(ids[i]) for each id from array "ids" with size "size"
		*/

		/*
		+-------------------+
		| TEXTURE FUNCTIONS |
		+-------------------+
		*/

		int queueTexture(/*Texture Params*/);
		/*
		adds a texture to the texture registry and adds it to the texture queue
		returns the texture registry id
		*/

		int loadTexture(/*Texture Params*/);
		/*
		adds a texture to the texture registry and loads it
		returns the texture registry id
		*/

		void nextTexture();
		/*
		loads the texture that's been in the texture queue the longest
		*/

		/*
		+----------------+
		| FONT FUNCTIONS |
		+----------------+
		*/

		int queueFont(/*Font Params*/);
		/*
		adds a font to the font registry and adds it to the font queue
		returns the font registry id
		*/

		int loadFont(/*Font Params*/);
		/*
		adds a font to the font registry and loads it
		returns the font registry id
		*/

		void nextFont();
		/*
		loads the font that's been in the font queue the longest
		*/

		void loadFonts();
		/*
		loads all the fonts in the font queue
		*/

		/*
		+-----------------+
		| MODEL FUNCTIONS |
		+-----------------+
		*/

		int queueModel(/*Model Params*/);
		/*
		adds a model to the model registry and adds it to the model queue
		returns the model registry id
		*/

		int loadModel(/*Model Params*/);
		/*
		adds a model to the model registry and loads it
		returns the model registry id
		*/

		void nextModel();
		/*
		loads the model that's been in the model queue the longest
		*/

		/*
		+------------------+
		| SHADER FUNCTIONS |
		+------------------+
		*/

		int queueShader(/*Shader Params*/);
		/*
		adds a shader to the shader registry and adds it to the shader queue
		returns the shader registry id
		*/

		int loadShader(/*Shader Params*/);
		/*
		adds a shader to the shader registry and loads it
		returns the shader registry id
		*/

		void nextShader();
		/*
		loads the shader that's been in the model queue the longest
		*/


		void cleanup();
		/*
		deletes all textures, models, and shaders in the registries
		*/

	};
}
