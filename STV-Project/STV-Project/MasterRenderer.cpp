#include "MasterRenderer.h"
#include <iostream>

#include "Camera.h"
#include "StaticShader.h"
#include "TerrainShader.h"
#include "HandShader.h"
#include "Entity.h"


MasterRenderer::MasterRenderer(GameManager* game_manager) : _GAME_MANAGER(game_manager)
{
	static_shader = new StaticShader();
	terrain_shader = new TerrainShader();
	hand_shader = new HandShader();
}

MasterRenderer::~MasterRenderer()
{
	delete static_shader;
	delete terrain_shader;
	delete hand_shader;
}

void MasterRenderer::Render() 
{
	vec3& clear_colour = GameManager::getMain()->sky_colour;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(clear_colour.x, clear_colour.y, clear_colour.z, 1.0);
	Camera::getMain()->buildViewMatrix();
	Camera::getMain()->frustum.GenerateFrustum();
	Camera::getMain()->frustum.RunTests();

	terrain_shader->Render();
	static_shader->Render();
	hand_shader->Render();

	glutSwapBuffers();
	glutPostRedisplay();
}

