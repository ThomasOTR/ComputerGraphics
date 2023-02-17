#include "environment_builder.h"
#include "Skybox.h"
#include "Color.h"

#include "Models/House.h"
#include "Models/TrashBin.h"
#include "Models/Tree.h"
#include "Models/Sidewalk.h"
#include "Models/Car.h"

#include "PrimitiveMeshes/TriangularPrism.h"
#include "PrimitiveMeshes/Plane.h"

#include "Animations/Scale/ScalingAnimation.h"
#include "Animations/Move/TranslateX_Animation.h"

#include <vector>
EnvironmentBuilder::EnvironmentBuilder()
{
	LoadAllEntities();
}
void EnvironmentBuilder::LoadAllEntities()
{

#pragma region BuildingHouses

	for (int i = -30; i < 10; i += 3) {
		House* house = new House();
		house->Move(glm::vec3(i, 1, 0));
		entities.push_back(house);

		for (int i = 0; i <= 4; i++) {
			Object* fence = new Object("Objects/MadeInBlender/fence.obj", "Textures/wood.bmp");
			glm::vec3 housePosition = house->GetPosition();
			fence->Move(glm::vec3(housePosition.x + 1.5f, 0.0f, housePosition.z + 2.5f - (i*0.9)));
			fence->Scale(glm::vec3(0.75, 0.75, 0.75));
			fence->Rotate(glm::vec3(0, 1, 0), 90);
			entities.push_back(fence);
		}

	}
#pragma endregion

#pragma region Environment
	Plane* road = new Plane(glm::vec3(0.502, 0.502, 0.502), ShadingType::Basic);
	road->Move(glm::vec3(-8, 0.01, 5));
	//road->SetRotation(glm::vec3(0, 1, 0), 180);
	road->Scale(glm::vec3(22, 0, 1));
	entities.push_back(road);

	Sidewalk* sidewalk = new Sidewalk(55,true);	
	sidewalk->Move(glm::vec3(-30, 0, 3.5));
	Sidewalk* sidewalk2 = new Sidewalk(55, true);
	sidewalk2->Move(glm::vec3(-30, 0, 6.5));
	entities.insert(entities.end(), { sidewalk,sidewalk2 });

	for (int i = -30; i < 0; i += 5)
	{
		glm::vec3 sidewalkPos = sidewalk2->GetPosition();
		Object* bench = new Object("Objects/MadeInBlender/bench.obj", "Textures/wood.bmp");
		bench->Move(glm::vec3(sidewalkPos.x - i, sidewalkPos.y, sidewalkPos.z + 1));
		bench->Scale(glm::vec3(1,1,1));
		bench->Rotate(glm::vec3(0, 1, 0), 90);
		entities.push_back(bench);

		TrashBin* trashbin = new TrashBin();
		trashbin->Move(glm::vec3(sidewalkPos.x - (i + 0.8), sidewalkPos.y, sidewalkPos.z + 1));
		entities.push_back(trashbin);
	}
	for (int i = -30; i < 0; i += 6)
	{
		glm::vec3 sidewalkPos = sidewalk2->GetPosition();
		Tree* tree = new Tree();
		tree->Move(glm::vec3(sidewalkPos.x - i, sidewalkPos.y, sidewalkPos.z + 2));
		entities.push_back(tree);
	}
#pragma endregion
	
	Car* car = new Car();
	car->Move(glm::vec3(-30, 0, 5));
	car->Scale(glm::vec3(0.5, 0.5, 0.5));
	car->Rotate(glm::vec3(0, 1, 0), 90);
	car->AddAnimation(new TranslateX_Animation(4.0f,0.1f));

	Plane* plane = new Plane(glm::vec3(0.282, 0.435, 0.22), ShadingType::Basic);
	plane->Move(glm::vec3(0, 0, 0));
	plane->Scale(glm::vec3(30, 1, 30));

	Skybox* skybox = new Skybox();
	
	entities.insert(entities.end(), { plane, skybox, car });

}
void EnvironmentBuilder::BufferAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Buffer(view, projection);
}

void EnvironmentBuilder::RenderAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Render(view, projection);
}


