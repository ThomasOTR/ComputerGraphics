#include "EnvironmentBuilder.h"
#include "Skybox.h"

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
#pragma region Houses

	std::cout << "--------------" << std::endl << "Loading Region Houses." << std::endl << "--------------" << std::endl;
	/* Adding Houses*/
	for (int i = -30; i < 20; i += 3) {
		House* house = new House();
		house->Move(glm::vec3(i, 1, 0));
		house->AddComponents();
		entities.push_back(house);
		
		/* Adding some fences between the houses. Adding it within the loop is way easier. */
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

	std::cout << "--------------" << std::endl << "Loading Region Environment..." << std::endl << "--------------" << std::endl;

	std::cout << "Loading Road..." << std::endl;
	/* Adding a road where the Car can drive on.*/
	Plane* road = new Plane(glm::vec3(0.502, 0.502, 0.502));
	road->Move(glm::vec3(-5, 0.01, 5));
	road->Scale(glm::vec3(27, 0, 1));
	entities.push_back(road);

	std::cout << "Loading Sidewalks..." << std::endl;

	/* Adding sidewalks*/
	Sidewalk* sidewalk = new Sidewalk(67,true);	
	sidewalk->Move(glm::vec3(-30, 0, 3.5));
	sidewalk->AddComponents();

	Sidewalk* sidewalk2 = new Sidewalk(67, true);
	sidewalk2->Move(glm::vec3(-30, 0, 6.5));
	sidewalk2->AddComponents();
	entities.insert(entities.end(), { sidewalk,sidewalk2 });


	std::cout << "Loading benches..." << std::endl;
	for (int i = -30; i < 21; i += 5)
	{
		Object* bench = new Object("Objects/MadeInBlender/bench.obj", "Textures/wood.bmp");
		bench->Move(glm::vec3(i, 0, 7.5));
		bench->Scale(glm::vec3(1,1,1));
		bench->Rotate(glm::vec3(0, 1, 0), 90);
		entities.push_back(bench);
	}

	std::cout << "Loading Lampposts..." << std::endl;
	for (int i = -27.5; i < 22.5; i += 5)
	{
		Lamppost* l = new Lamppost();
		l->Move(glm::vec3(i, 0, 7.5));
		l->AddComponents();
		entities.push_back(l);
	}

	/*std::cout << "Loading Trashbins..." << std::endl;
	for (int i = -29; i < 20; i += 10)
	{
		TrashBin* trashbin = new TrashBin();
		trashbin->Move(glm::vec3(i, 0, 7.5));
		trashbin->AddComponents();
		entities.push_back(trashbin);
	}*/
	std::cout << "Loading Trees..." << std::endl;

	for (int i = -30; i < 20; i += 3)
	{
		for (int j = 9; j < 15; j += 2.5)
		{
			Tree* tree = new Tree();
			tree->Move(glm::vec3(i, 0, j));
			tree->AddComponents();
			entities.push_back(tree);
		}
	}
#pragma endregion

#pragma region NecessaryComponents
	std::cout << "--------------" << std::endl << "Loading Region NecessaryComponents..." << std::endl << "--------------" << std::endl;
	std::cout << "Loading Car..." << std::endl;
	/* Adding the car */
	Car* car = new Car();
	car->Move(glm::vec3(-30, 0, 5));
	car->AddComponents();
	car->Scale(glm::vec3(0.5, 0.5, 0.5));
	car->AnimationInLoop = true;
	car->AddAnimations({ 
		new MoveRightAnimation(20,0.01f,false), new RotationAnimation(glm::vec3(0, 1, 0), 180),
		new MoveRightAnimation(-30,0.01f,true), new RotationAnimation(glm::vec3(0, 1, 0), 180)});
	entities.push_back(car);

	std::cout << "Loading Plane..." << std::endl;
	/* Adding a huge plane to have a ground to put everything on*/
	Plane* plane = new Plane(glm::vec3(0.282, 0.435, 0.22));
	plane->Scale(glm::vec3(50, 1, 15));
	entities.push_back(plane);

	std::cout << "Loading Skybox..." << std::endl;
	/* A skybox to have nice surroundings instead of a boring color. */
	Skybox* skybox = new Skybox();
	entities.push_back(skybox);
#pragma endregion

}
void EnvironmentBuilder::BufferAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Buffer(view, projection);
}

void EnvironmentBuilder::RenderAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Render(view, projection);
}


