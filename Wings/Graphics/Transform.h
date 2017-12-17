#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

class Transform
{
public:
	Transform(const glm::vec3 &pos = glm::vec3(), const glm::vec3 &rot = glm::vec3(), const glm::vec3 &scale = glm::vec3(1.0, 1.0, 1.0))
		: mPos(pos), mRot(rot), mScale(scale)
	{}

	inline glm::mat4 GetModel() const
	{
		glm::mat4 posMatrix = glm::translate(mPos);
		glm::mat4 rotXMatrix = glm::rotate(mRot.x, glm::vec3(1, 0, 0));
		glm::mat4 rotYMatrix = glm::rotate(mRot.y, glm::vec3(0, 1, 0));
		glm::mat4 scaleMatrix = glm::scale(mScale);

		glm::mat4 rotMatrix = rotYMatrix * rotXMatrix;

		return posMatrix * rotMatrix * scaleMatrix;
	}

	inline glm::vec3 &GetPos() { return mPos; }
	inline glm::vec3 &GetRot() { return mRot; }
	inline glm::vec3 &GetScale() { return mScale; }

	inline void SetPos(const glm::vec3 &pos) { mPos = pos; }
	inline void SetRot(const glm::vec3 &rot) { mRot = rot; }
	inline void SetScale(const glm::vec3 &scale) { mScale = scale; }
private:
	glm::vec3 mPos;
	glm::vec3 mRot;
	glm::vec3 mScale;
};