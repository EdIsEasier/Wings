#include "Shader.h"
#include <fstream>
#include <iostream>

Shader::Shader(const std::string& fileName)
{
	mProgram = glCreateProgram();
	mShaders[0] = CreateShader(LoadShader(fileName + ".vert"), GL_VERTEX_SHADER);
	mShaders[1] = CreateShader(LoadShader(fileName + ".frag"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(mProgram, mShaders[i]);

	//glBindAttribLocation(mProgram, 0, "position");
	//glBindAttribLocation(mProgram, 1, "texCoord");

	glLinkProgram(mProgram);
	CheckShaderError(mProgram, GL_LINK_STATUS, true, "Error: Program linking failed");

	glValidateProgram(mProgram);
	CheckShaderError(mProgram, GL_VALIDATE_STATUS, true, "Error: Program is invalid");

	mUniforms[TRANSFORM_U] = glGetUniformLocation(mProgram, "transform");
	mUniforms[TEXTURE_U] = glGetUniformLocation(mProgram, "tex");
	//offsetUniform = glGetUniformLocation(mProgram, "offset");
}

Shader::Shader()
{

}

Shader::~Shader()
{
	glDeleteProgram(mProgram);
}

void Shader::Create(const std::string &fileName)
{
	mProgram = glCreateProgram();
	mShaders[0] = CreateShader(LoadShader(fileName + ".vert"), GL_VERTEX_SHADER);
	mShaders[1] = CreateShader(LoadShader(fileName + ".frag"), GL_FRAGMENT_SHADER);

	for (unsigned int i = 0; i < NUM_SHADERS; i++)
		glAttachShader(mProgram, mShaders[i]);

	//glBindAttribLocation(mProgram, 0, "position");
	//glBindAttribLocation(mProgram, 1, "texCoord");

	glLinkProgram(mProgram);
	CheckShaderError(mProgram, GL_LINK_STATUS, true, "Error: Program linking failed");

	glValidateProgram(mProgram);
	CheckShaderError(mProgram, GL_VALIDATE_STATUS, true, "Error: Program is invalid");

	mUniforms[TRANSFORM_U] = glGetUniformLocation(mProgram, "transform");
	mUniforms[TEXTURE_U] = glGetUniformLocation(mProgram, "tex");
	//offsetUniform = glGetUniformLocation(mProgram, "offset");
}

GLuint Shader::CreateShader(const std::string& text, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);

	if (shader == 0)
		std::cerr << "Error: Shader creation failed!" << std::endl;

	const GLchar* shaderSourceString[1];
	//GLint shaderSourceStringLengths[1];

	shaderSourceString[0] = text.c_str();
	//shaderSourceStringLengths[0] = text.length();

	glShaderSource(shader, 1, shaderSourceString, NULL);
	glCompileShader(shader);

	CheckShaderError(shader, GL_COMPILE_STATUS, false, "Error: Shader compilation failed");

	return shader;
}

void Shader::Bind()
{
	for (unsigned int i = 0; i < NUM_SHADERS; i++)
	{
		glDetachShader(mProgram, mShaders[i]);
		glDeleteShader(mShaders[i]);
	}
	//glUniform2f(offsetUniform, 0.5f, 0.25f);
	glUseProgram(mProgram);

}

void Shader::Update(const Transform &transform)
{
	glm::mat4 model = transform.GetModel();

	glUniformMatrix4fv(mUniforms[TRANSFORM_U], 1, GL_FALSE, &model[0][0]);
	glUniform1i(mUniforms[TEXTURE_U], 0);
}

std::string Shader::LoadShader(const std::string& fileName)
{
	std::ifstream file;
	file.open((fileName).c_str());
	std::string output;
	std::string line;
	if (file.is_open())
	{
		while (file.good())
		{
			getline(file, line);
			output.append(line + "\n");
		}
	}
	else
	{
		std::cerr << "Unable to load shader: " << fileName << std::endl;
	}
	return output;
}

void Shader::CheckShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
	GLint success = 0;
	GLchar error[1024] = { 0 };
	if (isProgram)
		glGetProgramiv(shader, flag, &success);
	else
		glGetShaderiv(shader, flag, &success);
	if (success == GL_FALSE)
	{
		if (isProgram)
			glGetProgramInfoLog(shader, sizeof(error), NULL, error);
		else
			glGetShaderInfoLog(shader, sizeof(error), NULL, error);
		std::cerr << errorMessage << ": '" << error << "'" << std::endl;
	}
}