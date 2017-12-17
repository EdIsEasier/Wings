#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp>

class Vertex
{
	public:
		Vertex(const glm::vec2 &pos, const glm::vec2 &texCoord)
			: pos(pos), texCoord(texCoord)
		{}
		inline glm::vec2* GetPos() { return &pos; }
		inline glm::vec2* GetTexCoord() { return &texCoord; }
	private:
		glm::vec2 pos;
		glm::vec2 texCoord;
};

class Mesh
{
	public:
		Mesh(Vertex* vertices, unsigned int numVertices);
		Mesh();
		virtual ~Mesh();
		void Draw();
	private:
		enum
		{
			POSITION_VB,
			TEXCOORD_VB,
			NUM_BUFFERS
		};

		GLuint mVertexArrayObject;
		GLuint mVertexArrayBuffers[NUM_BUFFERS];
		GLuint mIndexArrayBuffer;
		unsigned int mDrawCount;
};