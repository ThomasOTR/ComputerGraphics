#include "environment_builder.h"
#include "Shape Classes/Pyramid.h"
#include "Shape Classes/Cube.h"
#include "Shape Classes/Plane.h"
#include "Shape Classes/House.h"
#include "Skybox.h"

EnvironmentBuilder::EnvironmentBuilder()
{
	LoadAllEntities();
}
void EnvironmentBuilder::LoadAllEntities()
{
	Plane* plane = new Plane(glm::vec3(0.173, 0., 0.8), 0, 0, 0);
	plane->SetScale(30, 1, 30);
	entities.push_back(plane);
	
	Plane* road = new Plane(glm::vec3(0.502, 0.502, 0.502), 5, 0.01, 0);
	road->SetScale(1, 0, 5);
	entities.push_back(road);

	House* house = new House(0,0,0);
	entities.push_back(house);

	Object* fence = new Object("Objects/hek.obj", "Textures/wood.bmp", 0.0f,0.02f,0.0f);
	entities.push_back(fence);

	Object* bench = new Object("Objects/bench.obj", "Textures/wood.bmp", 0.0f, 0.02f, 0.0f);
	entities.push_back(bench);

	Object* trashbin = new Object("Objects/TrashBin.obj", glm::vec3(1, 0, 0), 0.0f, 0.02f, 0.0f);
	entities.push_back(trashbin);

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


