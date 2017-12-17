#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <string>

class Texture
{
	public:
		Texture(const std::string &fileName);
		Texture();
		void Load(const std::string &fileName);
		void Bind(unsigned int unit);
		~Texture();
	private:
		GLuint mTexture;
};