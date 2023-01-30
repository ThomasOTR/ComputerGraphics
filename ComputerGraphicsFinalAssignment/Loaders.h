#pragma once
#include <GL/glew.h>
#include <stdio.h>
#include <vector>
#include <glm/glm.hpp>
#include <string>
#include <iostream>

#include "stb_image.h"

#define FOURCC_DXT1 0x31545844 // Equivalent to "DXT1" in ASCII
#define FOURCC_DXT3 0x33545844 // Equivalent to "DXT3" in ASCII
#define FOURCC_DXT5 0x35545844 // Equivalent to "DXT5" in ASCII

#ifndef TEXTURE_HPP
#define TEXTURE_HPP
unsigned int loadBMP(const char* imagepath);
unsigned int loadDDS(const char* imagepath);
#endif

#ifndef OBJLOADER_H
#define OBJLOADER_H
bool loadOBJ(
	const char* path,
	std::vector<glm::vec3>&,
	std::vector<glm::vec2>&,
	std::vector<glm::vec3>&
);
#endif

unsigned int loadCubemap(std::vector<std::string> faces);
unsigned int setTexture(const char*);