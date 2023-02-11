#include "Color.h"
#include <iostream>

Color::Color(glm::vec3 glslColor)
{

}

Color::Color(std::string hexColor)
{
}

Color::Color(RGB rgbColor)
{
	rgb = rgbColor;
}

glm::vec3 Color::ToVec3()
{
	float x = round(rgb.R);

	//vec4(${ round(rgb.r).toFixed(2) }, ${ round(rgb.g).toFixed(2) }, ${ round(rgb.b).toFixed(2) }, 1.0)
	return glm::vec3();
}

std::string Color::ToHex()
{
	char hex[20];

	
	sprintf(hex, "%X", rgb.R); //convert number to hex
	std::cout << hex;

	return " ";
}
