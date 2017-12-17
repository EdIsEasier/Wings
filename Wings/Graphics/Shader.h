#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <string>
#include "Transform.h"

class Shader
{
	public:
		Shader(const std::string &fileName);
		Shader();
		void Create(const std::string &fileName);
		void Bind();
		void Update(const Transform &transform);
		virtual ~Shader();
	private:
		enum
		{
			TRANSFORM_U,
			TEXTURE_U
		};

		static const unsigned int NUM_SHADERS = 2;
		static const unsigned int NUM_UNIFORMS = 2;
		GLuint mProgram;
		GLuint mShaders[NUM_SHADERS];
		GLuint mUniforms[NUM_UNIFORMS];
		GLuint offsetUniform;

		std::string LoadShader(const std::string &fileName);
		void CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string &errorMessage);
		GLuint CreateShader(const std::string &text, GLenum shaderType);
};