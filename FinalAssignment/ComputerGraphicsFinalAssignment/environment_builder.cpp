#include "environment_builder.h"
#include "Skybox.h"
#include "PrimitiveMeshes/Plane.h"
#include "Models/House.h"
#include "Models/TrashBin.h"
#include "Color.h"
#include "PrimitiveMeshes/TriangularPrism.h"
#include "Animations/Scale/ScalingAnimation.h"
#include "Animations/Move/TranslateX_Animation.h"
#include <vector>
EnvironmentBuilder::EnvironmentBuilder()
{
	LoadAllEntities();
}
void EnvironmentBuilder::LoadAllEntities()
{
	Plane* plane = new Plane(glm::vec3(0.173, 0., 0.8), glm::vec3(0, 0, 0));
	plane->SetScale(glm::vec3(30, 1, 30));
	
	Plane* road = new Plane(glm::vec3(0.502, 0.502, 0.502), glm::vec3(5, 0.01, 0));
	road->SetScale(glm::vec3(1, 0, 5));

	House* house = new House(glm::vec3(0,1,0));

	Object* fence = new Object("Objects/MadeInBlender/fence.obj", "Textures/wood.bmp", glm::vec3(0.0f, 0.0f, 2.0f));
	//fence->AddAnimation(new ScalingAnimation(-50.0f,0.001f));
	/*std::vector<Animation*> animations = { new TranslateX_Animation(2.0f,0.001f), new ScalingAnimation(-50.0f,0.001f) };
	fence->AddAnimations(animations);*/


	Object* bench = new Object("Objects/MadeInBlender/bench.obj", "Textures/wood.bmp", glm::vec3(0.0f, 0.02f, 5.0f));
	bench->SetScale(glm::vec3(2, 2, 2));

	TrashBin* trashbin = new TrashBin(glm::vec3(0, 0, 3));

	TriangularPrism* TP = new TriangularPrism(glm::vec3(0.173, 0., 0.8), glm::vec3(4, 0, 0), ShadingType::Basic);

	Skybox* skybox = new Skybox();

	entities.insert(entities.end(), {
		/*plane,
		road,
		house,*/
		fence,
		/*bench,
		trashbin,
		TP,
		skybox*/
		});

}
void EnvironmentBuilder::BufferAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Buffer(view, projection);
}

void EnvironmentBuilder::RenderAllEntities(glm::mat4 view, glm::mat4 projection)
{
	for (Entity* e : entities) e->Render(view, projection);
}


