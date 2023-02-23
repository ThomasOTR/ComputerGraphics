#include "environment_builder.h"
#include "Skybox.h"
#include "Color.h"

#include "Models/House.h"
#include "Models/TrashBin.h"
#include "Models/Tree.h"
#include "Models/Sidewalk.h"
#include "Models/Car.h"
#include "Models/Lamppost.h"

#include "PrimitiveMeshes/TriangularPrism.h"
#include "PrimitiveMeshes/Plane.h"
#include "PrimitiveMeshes/Cube.h"

#include "Animations/Rotate/RotationAnimation.h"
#include "Animations/Move/MoveRightAnimation.h"
#include "Animations/Move/TranslateZ_Animation.h"

#include "Animations/Scale/ScalingAnimation.h"

#include <vector>
EnvironmentBuilder::EnvironmentBuilder()
{
	LoadAllEntities();
}
void EnvironmentBuilder::LoadAllEntities()
{
	//Car* bla = new Car();
	//bla->Move(glm::vec3(-30, 15, 0));
	//entities.push_back(bla);
#pragma region BuildingHouses

	for (int i = -10; i < 10; i += 3) {
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
	road->Move(glm::vec3(-1, 0.01, 5));
	road->Scale(glm::vec3(14, 0, 1));
	entities.push_back(road);

	Plane* road2 = new Plane(glm::vec3(0.502, 0.502, 0.502), ShadingType::Basic);
	road2->Move(glm::vec3(12, 0.01, -8));
	road2->Scale(glm::vec3(1, 0, 14));
	entities.push_back(road2);

	Plane* road3 = new Plane(glm::vec3(0.502, 0.502, 0.502), ShadingType::Basic);
	road3->Move(glm::vec3(-14, 0.01, -8));
	road3->Scale(glm::vec3(1, 0, 14));
	entities.push_back(road3);

	Plane* road4 = new Plane(glm::vec3(0.502, 0.502, 0.502), ShadingType::Basic);
	road4->Move(glm::vec3(-1, 0.01, -23));
	road4->Scale(glm::vec3(14, 0, 1));
	entities.push_back(road4);


	Sidewalk* sidewalk = new Sidewalk(31,true);	
	sidewalk->Move(glm::vec3(-12.6, 0, 3.5));
	Sidewalk* sidewalk2 = new Sidewalk(37, true);
	sidewalk2->Move(glm::vec3(-14.7, 0, 6.5));

	Sidewalk* sidewalk3 = new Sidewalk(25, false);
	sidewalk3->Move(glm::vec3(-12.6, 0, -21.5));

	Sidewalk* sidewalk4 = new Sidewalk(31, true);
	sidewalk4->Move(glm::vec3(-12.6, 0, -21.5));

	Sidewalk* sidewalk5 = new Sidewalk(25, false);
	sidewalk5->Move(glm::vec3(11, 0, -21.5));

	entities.insert(entities.end(), { sidewalk,sidewalk2, sidewalk3, sidewalk4, sidewalk5 });

	for (int i = -30; i < 0; i += 5)
	{
		glm::vec3 sidewalkPos = sidewalk2->GetPosition();
		Object* bench = new Object("Objects/MadeInBlender/bench.obj", "Textures/wood.bmp");
		bench->Move(glm::vec3(sidewalkPos.x - i, sidewalkPos.y, sidewalkPos.z + 1));
		bench->Scale(glm::vec3(1,1,1));
		bench->Rotate(glm::vec3(0, 1, 0), 90);
		entities.push_back(bench);
		/*TrashBin* trashbin = new TrashBin();
		trashbin->Move(glm::vec3(sidewalkPos.x - (i + 0.8), sidewalkPos.y, sidewalkPos.z + 1));
		entities.push_back(trashbin);*/
	}
	for (int i = -30; i < 0; i += 6)
	{
		glm::vec3 sidewalkPos = sidewalk2->GetPosition();
		Tree* tree = new Tree();
		tree->Move(glm::vec3(sidewalkPos.x - i, sidewalkPos.y, sidewalkPos.z + 2));;
		entities.push_back(tree);
	}
	Lamppost* l = new Lamppost();
	l->Move(glm::vec3(0, 0, 15));
	entities.push_back(l);
	
	Car* car = new Car();
	car->Move(glm::vec3(-30, 0, 5));
	car->Scale(glm::vec3(0.5, 0.5, 0.5));
	car->AnimationInLoop = true;
	car->AddAnimations({ 
		new MoveRightAnimation(12,0.01f,false), new RotationAnimation(glm::vec3(0, 1, 0), 180),
		new MoveRightAnimation(-15,0.01f,true), new RotationAnimation(glm::vec3(0, 1, 0), 180)});

	Plane* plane = new Plane(glm::vec3(0.282, 0.435, 0.22), ShadingType::Basic);
	plane->Scale(glm::vec3(50, 1, 50));

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


