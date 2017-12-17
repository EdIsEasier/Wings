#pragma once
#include "Graphics\Shader.h"
#include "Graphics\Texture.h"
#include "Graphics\Mesh.h"
#include "Input.h"
#include <glm/glm.hpp>
#include <string>

class Sprite
{
	public:
		Sprite(const std::string &fileDir);
		void Update();
		void Draw(glm::vec2 position);
		~Sprite();
	private:
		Shader shader;
		Texture texture;
		Mesh mesh;
		Transform transform;
};