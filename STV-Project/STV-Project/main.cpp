#include "MemoryListener.h"
#include <iostream>

#include "VoxelBuilder.h"
#include "GameManager.h"
#include "Model.h"
#include "TexturedModel.h"
#include "Terrain.h"

#include "PlayerController.h"
#include "ResourcePlacer.h"
#include "EllipsoidBody.h"
#include "PlayerHand.h"
#include "DayCycleController.h"
#include "Scene.h"


using namespace std;


void Start(bool smooth_state, int seed) 
{
	GameManager::getMain();
	GameManager::getMain()->voxel_builder->SetSmoothMode(smooth_state);


	Entity* player = new Entity();
	player->AddComponent(new EllipsoidBody(vec3(1,1,1)));
	player->AddComponent(new PlayerController());
	player->AddComponent(new ResourcePlacer());
	player->AddComponent(new PlayerHand());

	Terrain* terrain = new Terrain(seed);
	Entity* day_cycle_controller = new Entity();
	day_cycle_controller->AddComponent(new DayCycleController());
	const float height = terrain->GetChunkLoader()->GetChunk(0, 0, 0)->GetHeight(8, 8);
	player->location = vec3(8, height + 1.5f, 8);

	Scene* scene = new Scene();
	scene->AddToScene(player);
	scene->AddToScene(day_cycle_controller);
	scene->SetTerrain(terrain);
	GameManager::getMain()->SetCurrentScene(scene);

	GameManager::getMain()->MainLoop();
	GameManager::getMain()->SetCurrentScene(nullptr);
	delete scene;
	delete GameManager::getMain();
}

int main(int argc, char **argv)
{
	cout << "Smooth mode? ";
	bool state;
	cin >> state;
	cout << state << endl;
	cout << "Input seed: ";
	int seed;
	cin >> seed;
	cout << seed << endl;

	Start(state, seed);
	
	cout << "Ready to close.." << endl;
	char thro;
	cin >> thro;

	_CrtDumpMemoryLeaks();
	return 0;
}
