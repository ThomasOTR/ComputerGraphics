#pragma once
#include <glm/glm.hpp>
#include <string>

struct RGB
{
	int R;
	int G;
	int B;
};

class Color
{

private:
	RGB rgb;
public:
	Color(glm::vec3);
	Color(std::string);
	Color(RGB);

	glm::vec3 ToVec3();
	std::string ToHex();

};

