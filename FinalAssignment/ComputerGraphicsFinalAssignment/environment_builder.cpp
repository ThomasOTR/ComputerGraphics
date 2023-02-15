#include "environment_builder.h"
#include "Skybox.h"
#include "Color.h"

#include "Models/House.h"
#include "Models/TrashBin.h"
#include "Models/Tree.h"
#include "Models/Sidewalk.h"
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
		House* house = new House(glm::vec3(i, 1, 0));
		entities.push_back(house);

		for (int i = 0; i <= 4; i++) {
			Object* fence = new Object("Objects/MadeInBlender/fence.obj", "Textures/wood.bmp");
			glm::vec3 housePosition = house->GetPosition();
			fence->SetPosition(glm::vec3(housePosition.x + 1.5f, 0.0f, housePosition.z + 2.5f - (i*0.9)));
			fence->SetScale(glm::vec3(0.75, 0.75, 0.75));
			fence->SetRotation(glm::vec3(0, 1, 0), 90);
			entities.push_back(fence);
		}

	}
#pragma endregion

	Plane* road = new Plane(glm::vec3(0.502, 0.502, 0.502), ShadingType::Basic);
	road->SetPosition(glm::vec3(-8, 0.01, 5));
	//road->SetRotation(glm::vec3(0, 1, 0), 180);
	road->SetScale(glm::vec3(22, 0, 1));
	entities.push_back(road);

	Sidewalk* sidewalk = new Sidewalk(glm::vec3(-30,0,3.5),55,true);	
	Sidewalk* sidewalk2 = new Sidewalk(glm::vec3(-30, 0, 6.5), 55, true);
	entities.insert(entities.end(), { sidewalk,sidewalk2 });

	for (int i = -30; i < 0; i += 5)
	{
		glm::vec3 sidewalkPos = sidewalk2->GetPosition();
		Object* bench = new Object("Objects/MadeInBlender/bench.obj", "Textures/wood.bmp");
		bench->SetPosition(glm::vec3(sidewalkPos.x - i, sidewalkPos.y, sidewalkPos.z + 1));
		bench->SetScale(glm::vec3(1,1,1));
		bench->SetRotation(glm::vec3(0, 1, 0), 90);
		entities.push_back(bench);

		TrashBin* trashbin = new TrashBin(glm::vec3(sidewalkPos.x - (i + 0.8),sidewalkPos.y,sidewalkPos.z + 1));
		entities.push_back(trashbin);
	}
	for (int i = -30; i < 0; i += 6)
	{
		glm::vec3 sidewalkPos = sidewalk2->GetPosition();
		Tree* tree = new Tree(glm::vec3(sidewalkPos.x - i, sidewalkPos.y, sidewalkPos.z + 2));
		entities.push_back(tree);
	}

	


	Plane* plane = new Plane(glm::vec3(0.282, 0.435, 0.22), ShadingType::Basic);
	plane->SetPosition(glm::vec3(0, 0, 0));
	plane->SetScale(glm::vec3(30, 1, 30));

	Skybox* skybox = new Skybox();
	
	entities.insert(entities.end(), { plane, skybox });

	
	//fence->AddAnimation(new ScalingAnimation(-50.0f,0.001f));
/*std::vector<Animation*> animations = { new TranslateX_Animation(2.0f,0.001f), new ScalingAnimation(-50.0f,0.001f) };
fence->AddAnimations(animations);*/
}
void EnvironmentBuilder::BufferAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Buffer(view, projection);
}

void EnvironmentBuilder::RenderAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Render(view, projection);
}


