#include "Sprite.h"
#include "Input.h"

Sprite::Sprite(const std::string &fileDir)
{
	shader.Create("./Shaders/basicShader");
	texture.Load(fileDir);
}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
	
}

void Sprite::Draw(glm::vec2 position)
{
	glLoadIdentity();
	glTranslatef(position.x, position.y, 0.0f);
	shader.Bind();
	texture.Bind(0);
	shader.Update(transform);
	//mesh.Draw;
}