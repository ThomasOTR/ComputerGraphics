#pragma once
#include <glm/glm.hpp>
#include <vector>
#include "Entity.h"

/// <summary>
/// Class to store an object.
/// </summary>
class Object : public Entity
{
private:
	std::string object_path;
public:
	/* Property which stores the vertices of the Object. This will be set in the LoadObject method */
	std::vector<glm::vec3> vertices;

	/* Property which stores the normals of the Object. This will be set in the LoadObject method */
	std::vector<glm::vec3> normals;

	/* Property which stores the uvs of the Object. This will be set in the LoadObject method */
	std::vector<glm::vec2> uvs;

	/* Property to store the color, which will be retrieved during buffering the Object */
	glm::vec3 color = glm::vec3();

	/* Property which stores the Material, which will be retrieved during buffering the Object*/
	Material material;

	Object() = default;

	/// <summary>
	/// Constructor which will set a Texture.
	/// </summary>
	/// <param name="object_name">: name of the object to fetch the right object</param>
	/// <param name="texture_name">: name of the texture to fetch the right texture</param>
	Object(std::string object_name, std::string texture_name,bool MadeInBlender);

	/// <summary>
	/// Constructor which will set a Color.
	/// </summary>
	/// <param name="object_path">: Path to the object, so it can be accessed during the buffering process.</param>
	/// <param name="color">: The color that will be given to the Object.</param>
	Object(std::string object_path, glm::vec3 color, bool MadeInBlender);

	/// <summary>
	/// A method to load the object
	/// </summary>
	void LoadObject();

	/// <summary>
	/// Method to buffer the Object.
	/// This method overrides the Buffer method of Entity.
	/// <param name="view">: Calculated View Matrix</param>
	/// <param name="projection">: Calculated Projection Matrix</param>
	void Buffer(glm::mat4 view, glm::mat4 projection) override;

	/// <summary>
	/// Method to render the Object
	/// This method overrides the Render method of Entity	
	/// </summary>
	/// <param name="view">: Calculated View Matrix</param>
	/// <param name="projection">: Calculated Projection Matrix</param>
	void Render(glm::mat4 view, glm::mat4 projection) override;
};

