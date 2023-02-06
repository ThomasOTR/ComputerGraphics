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
	std::string url = "Textures/uvtemplate.bmp";

	entities.push_back(new Pyramid(url, 1, 1, -10));
	//entities.push_back(new Object("Objects/teapot.obj", url, 0, 0, 0));
	//entities.push_back(new Object("Objects/box.obj", url, 5, 0, -10));
	//entities.push_back(new Cube(glm::vec3(0.173, 0., 0.8), 0, 0, 0));
	entities.push_back(new House(0,0,0));
	entities.push_back(new Skybox());
	entities.push_back(new Object("Objects/hek.obj", url, 1, 1, 1));

	Plane* plane = new Plane(glm::vec3(0.173, 0., 0.8), 0, 0, 0);
	plane->SetScale(30, 1, 30);
	entities.push_back(plane);
	//entities.push_back(new Object("Objects/grass.obj", url, 1, 1, 1));

}
void EnvironmentBuilder::BufferAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Buffer(view, projection);
}

void EnvironmentBuilder::RenderAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Render(view, projection);
}


