#pragma once

#include <knoxh/core/window.h>

#include <knoxh/util/registry.h>
#include <knoxh/util/queue.h>

#include <knoxh/graphics/texture.h>

namespace knoxh
{
	/*
	class for managing resources
	*/
	class Engine
	{
	private:
		Registry* m_textureReg;
		//registry for textures
		Queue* m_textureQueue;
		//queue for textures;
		Texture** m_textures;
		//texture array
		int m_textureCap;
		//size of texture array


		Registry* m_modelReg;
		//registry for models
		Queue* m_modelQueue;
		//queue for models
		/*Model** models;*/
		//model array
		int m_modelCap;
		//size of model array

		Registry* m_shaderReg;
		//registry for shaders
		Queue* m_shaderQueue;
		//queue for shaders
		/*Shader** shaders;*/
		//shader array
		int m_shaderCap;
		//size of shader array


	public:
		~Engine();
		Engine(const int textureCap, const int modelCap, const int shaderCap);

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

		void loadTextures();
		/*
		loads all the textures in the texture queue
		*/

		void deleteTexture(const int id);
		/*
		removes the texture with id id in the texture registry
		*/

		void deleteTextures(const int* ids, const int count);
		/*
		removes the textures with ids ids in the texture registry
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

		void deleteFont(const int id);
		/*
		removes the font with id id in the font registry
		*/

		void deleteFonts(const int* ids, const int count);
		/*
		removes the fonts with ids ids in the font registry
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

		void deleteModel(const int id);
		/*
		removes the model with id id in the model registry
		*/

		void deleteModels(const int* ids, const int count);
		/*
		removes the models with ids ids in the model registry
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

		void deleteShader(const int id);
		/*
		removes the shader with id id in the shader registry
		*/

		void deleteShaders(const int* ids, const int count);
		/*
		removes the shaders with ids ids in the shader registry
		*/

		void cleanup();
		/*
		deletes all textures, models, and shaders in the registries
		*/

	};
}
