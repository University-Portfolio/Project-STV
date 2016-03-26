#pragma once
#include "Component.h"
#include "Keyboard.h"

#include <iostream>

class TestRotationComponent : public Component
{
public:
	~TestRotationComponent() 
	{
		cout << "TTTTTTEEEEEEEEEESSSSSSSSSSTTTTTTTTTTTTTT" << endl;
	}
	void Start()
	{
		cout << "START" << endl;
	}


	void VisualUpdate() 
	{
		if (Keyboard::isKeyDown('a'))
			parent->rotation += vec3(0.0f, 0.05f, 0.0f);

		if (Keyboard::isKeyDown('d'))
			parent->rotation -= vec3(0.0f, 0.05f, 0.0f);

		if (Keyboard::isKeyDown('w'))
			parent->location -= vec3(0.0f, 0.5f, 0.0f);

		if (Keyboard::isKeyDown('s'))
			parent->location += vec3(0.0f, 0.5f, 0.0f);

		if (Keyboard::isKeyDown('q'))
			parent->location -= vec3(0.0f, 0.0f, 0.5f);

		if (Keyboard::isKeyDown('e'))
			parent->location += vec3(0.0f, 0.0f, 0.5f);

		/*if (Keyboard::isKeyDown('a'))
			Camera::getMain()->setPosition(Camera::getMain()->getPosition() + vec3(-0.5f, 0.0f, 0.0f));

		if (Keyboard::isKeyDown('d'))
			Camera::getMain()->setPosition(Camera::getMain()->getPosition() + vec3(0.5f, 0.0f, 0.0f));

		if (Keyboard::isKeyDown('w'))
			Camera::getMain()->setPosition(Camera::getMain()->getPosition() + vec3(0.0f, 0.0f, -0.5f));

		if (Keyboard::isKeyDown('s'))
			Camera::getMain()->setPosition(Camera::getMain()->getPosition() + vec3(0.0f, 0.0f, 0.5f));

		if (Keyboard::isKeyDown('q'))
			Camera::getMain()->setPosition(Camera::getMain()->getPosition() + vec3(0.0f, 0.5f, 0.0f));

		if (Keyboard::isKeyDown('e'))
			Camera::getMain()->setPosition(Camera::getMain()->getPosition() + vec3(0.0f, -0.5f, 0.0f));


		if (Keyboard::isKeyDown('j'))
			Camera::getMain()->setOffset(Camera::getMain()->getOffset() + vec3(0.5f, 0.0f, 0.0f));

		if (Keyboard::isKeyDown('l'))
			Camera::getMain()->setOffset(Camera::getMain()->getOffset() + vec3(-0.5f, 0.0f, 0.0f));

		if (Keyboard::isKeyDown('i'))
			Camera::getMain()->setOffset(Camera::getMain()->getOffset() + vec3(0.0f, 0.0f, 0.5f));

		if (Keyboard::isKeyDown('k'))
			Camera::getMain()->setOffset(Camera::getMain()->getOffset() + vec3(0.0f, 0.0f, -0.5f));

		if (Keyboard::isKeyDown('u'))
			Camera::getMain()->setOffset(Camera::getMain()->getOffset() + vec3(0.0f, -0.5f, 0.0f));

		if (Keyboard::isKeyDown('o'))
			Camera::getMain()->setOffset(Camera::getMain()->getOffset() + vec3(0.0f, 0.5f, 0.0f));
*/
	};
};

