#include "EnvironmentBuilder.h"
#include "Skybox.h"

#include "Models/House.h"
#include "Models/TrashBin.h"
#include "Models/Tree.h"
#include "Models/Sidewalk.h"
#include "Models/Lamppost.h"

#include "PrimitiveMeshes/TriangularPrism.h"
#include "PrimitiveMeshes/Plane.h"
#include "PrimitiveMeshes/Cube.h"

#include "Animations/MoveRightAndTurnAroundAnimation.h"
#include "Animations/TakeOffAndFlyAndDescendAnimation.h"
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
	for (int i = -18; i <= 18; i += 3) {
		House* house = new House();
		house->Move(glm::vec3(i, 1, 0));
		house->AddComponents();
		entities.push_back(house);
		
		/* Adding some fences between the houses. Adding it within the loop is way easier. */
		for (int i = 0; i <= 4; i++) {
			Object* fence = new Object("fence.obj", "wood.bmp",true);
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
	road->Move(glm::vec3(0, 0.01, 5));
	road->Scale(glm::vec3(20, 0, 1));
	entities.push_back(road);

	std::cout << "Loading Sidewalks..." << std::endl;

	/* Adding sidewalks*/
	Sidewalk* sidewalk = new Sidewalk(53,true);	
	sidewalk->Move(glm::vec3(-20, 0, 3.5));
	sidewalk->AddComponents();

	Sidewalk* sidewalk2 = new Sidewalk(53, true);
	sidewalk2->Move(glm::vec3(-20, 0, 6.5));
	sidewalk2->AddComponents();
	entities.insert(entities.end(), { sidewalk,sidewalk2,});

	std::cout << "Loading benches..." << std::endl;
	for (int i = -18; i < 18; i += 5)
	{
		Object* bench = new Object("bench.obj", "wood.bmp",true);
		bench->Move(glm::vec3(i, 0, 7.5));
		bench->Scale(glm::vec3(1,1,1));
		bench->Rotate(glm::vec3(0, 1, 0), 90);
		entities.push_back(bench);
	}

	std::cout << "Loading Lampposts..." << std::endl;
	for (double i = -19.5; i < 19.5; i += 5)
	{
		Lamppost* l = new Lamppost();
		l->Move(glm::vec3(i, 0, 7.5));
		l->AddComponents();
		entities.push_back(l);
	}

	std::cout << "Loading Trashbins..." << std::endl;
	for (int i = -19; i < 19; i += 10)
	{
		TrashBin* trashbin = new TrashBin();
		trashbin->Move(glm::vec3(i, 0, 7.5));
		trashbin->AddComponents();
		entities.push_back(trashbin);
	}
	std::cout << "Loading Trees..." << std::endl;

	//for (int i = -17; i <= 17; i += 3)
	//{
	//	Tree* tree = new Tree();
	//	tree->Move(glm::vec3(i, 0, 9));
	//	tree->AddComponents();
	//	entities.push_back(tree);

	//	Tree* tree2 = new Tree();
	//	tree2->Move(glm::vec3(i, 0, -3));
	//	tree2->AddComponents();
	//	entities.push_back(tree2);
	//}
	//for (int i = -15; i <= 15; i += 3)
	//{
	//	Tree* tree = new Tree();
	//	tree->Move(glm::vec3(i, 0, 11));
	//	tree->AddComponents();
	//	entities.push_back(tree);

	//	Tree* tree2 = new Tree();
	//	tree2->Move(glm::vec3(i, 0, -5));
	//	tree2->AddComponents();
	//	entities.push_back(tree2);
	//}
	std::cout << "Loading Animable Objects..." << std::endl;
	/* Adding the car */
	Object* car = new Object("car.obj", glm::vec3(0., 0.588, 1.), false);
	car->Move(glm::vec3(-19, 0, 5));
	car->Scale(glm::vec3(0.5, 0.5, 0.5));
	car->AnimationInLoop = true;
	car->AddAnimation(
		new MoveRightAndTurnAroundAnimation(20, 0.05f));

	Object* heli = new Object("helicopter.obj", glm::vec3(0., 0.588, 1.), false);
	heli->Move(glm::vec3(0, 0.6, 15.5));
	heli->Scale(glm::vec3(0.3, 0.3, 0.3));
	heli->AddAnimation(
		new TakeOffAndFlyAndDescendAnimation(-7.5f, 0.1f, 15.0f, true)
	);

	Object* helipad = new Object("helipad.obj", glm::vec3(0.871, 0.871, 0.871), false);
	helipad->Move(glm::vec3(0, 0, 15));
	helipad->Scale(glm::vec3(.3,.3,.3));
	Object* helipad2 = new Object("helipad.obj", glm::vec3(0.871, 0.871, 0.871), false);
	helipad2->Move(glm::vec3(0, 0, -8));
	helipad2->Scale(glm::vec3(.3, .3, .3));

	entities.insert(entities.end(), { helipad,helipad2, car, heli });
#pragma endregion

#pragma region NecessaryComponents
	std::cout << "--------------" << std::endl << "Loading Region NecessaryComponents..." << std::endl << "--------------" << std::endl;

	std::cout << "Loading Plane..." << std::endl;
	/* Adding a huge plane to have a ground to put everything on*/
	Plane* plane = new Plane(glm::vec3(0.282, 0.435, 0.22));
	plane->Move(glm::vec3(0, 0, 3));
	plane->Scale(glm::vec3(21, 1, 15));
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


