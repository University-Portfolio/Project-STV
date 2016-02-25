#pragma once
#include "Dependencies\glm\vec3.hpp"
#include "Dependencies\glm\mat4x4.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"

#define NEAR_CLIPPING_PLANE 0.1f
#define FAR_CLIPPING_PLANE 100.0f

using namespace glm;

class Camera
{
public:
	Camera();
	~Camera();


	void setFoV(float fov) 
	{
		if (fov > 0 && fov <= 300)
			_FoV = fov;
	}

	void setPosition(float x, float y, float z)
	{
		_position->x = x;
		_position->y = y;
		_position->z = z;
	}
	vec3* getPosition()
	{
		return _position;
	}

	void setOffset(float x, float y, float z)
	{
		_offset->x = x;
		_offset->y = y;
		_offset->z = z;
	}
	vec3* getOffset()
	{
		return _offset;
	}

	void buildViewMatrix();
	void rebuildProjectionMatrix();
	void rebuildProjectionMatrix(float aspect_ratio);

	mat4 getViewMatrix() { return _view_matrix; }
	mat4 getProjectionMatrix() { return _projection_matrix; }

	static Camera* getMain()
	{
		static Camera* MAIN = new Camera();
		return MAIN;
	}

private:
	vec3* _position;
	vec3* _offset;

	//Projection Matrix
	float _last_aspect_ratio = 1;
	float _FoV = 70;
	mat4 _projection_matrix;
	mat4 _view_matrix;
};
