#include "environment_builder.h"
#include "Skybox.h"
#include "PrimitiveMeshes/Plane.h"
#include "Models/House.h"
#include "Models/TrashBin.h"
#include "Color.h"

EnvironmentBuilder::EnvironmentBuilder()
{
	LoadAllEntities();
}
void EnvironmentBuilder::LoadAllEntities()
{
	Color c = Color(RGB{ 10,10,10 });
	c.ToVec3();
	//Color c2 = Color(glm::vec3(0.502, 0.502, 0.502));
	//Plane* plane = new Plane(glm::vec3(0.173, 0., 0.8), 0, 0, 0);
	//plane->SetScale(30, 1, 30);
	//entities.push_back(plane);
	//
	//Plane* road = new Plane(glm::vec3(0.502, 0.502, 0.502), 5, 0.01, 0);
	//road->SetScale(1, 0, 5);
	//entities.push_back(road);

	//House* house = new House(0,1,0);
	//entities.push_back(house);

	//
	//Object* fence = new Object("Objects/MadeInBlender/fence.obj", "Textures/wood.bmp", 0.0f, 0.0f, 2.0f);
	//entities.push_back(fence);

	//Object* bench = new Object("Objects/MadeInBlender/bench.obj", "Textures/wood.bmp", 0.0f, 0.02f, 5.0f);
	//bench->SetScale(2, 2, 2);
	//entities.push_back(bench);

	//TrashBin* trashbin = new TrashBin(0, 0, 3);
	//entities.push_back(trashbin);

	entities.push_back(new Skybox());

}
void EnvironmentBuilder::BufferAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Buffer(view, projection);
}

void EnvironmentBuilder::RenderAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Render(view, projection);
}


