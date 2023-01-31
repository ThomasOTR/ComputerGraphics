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

/// <summary>
/// Method to load a BMP file as texture
/// </summary>
/// <param name=""></param>
/// <returns>Unsigned int which contains the loaded texture</returns>
unsigned int loadBMP(const char*);

/// <summary>
/// method to load a DDS file as texture.
/// </summary>
/// <param name=""></param>
/// <returns>Unsigned int which contains the loaded object</returns>
unsigned int loadDDS(const char*);
#endif

#ifndef OBJLOADER_H
#define OBJLOADER_H

/// <summary>
/// Method to load an object
/// </summary>
/// <param name="">path to objection location</param>
/// <param name="">Memory address to vector of vertices</param>
/// <param name="">Memory address to vector of uvs </param>
/// <param name="">Memory address to vector of normals</param>
/// <returns>Boolean if object is loaded or not.</returns>
bool loadOBJ(
	const char*,
	std::vector<glm::vec3>&,
	std::vector<glm::vec2>&,
	std::vector<glm::vec3>&
);
#endif

/// <summary>
/// Method to load a Cubemap
/// </summary>
/// <param name="">a vector with path of each side of the cubemap</param>
/// <returns>Unsigned int which contains the loaded texture</returns>
unsigned int loadCubemap(std::vector<std::string>);

/// <summary>
/// A method to set a texture
/// </summary>
/// <param name="">Path to texture location</param>
/// <returns>Unsigned int which contains the loaded texture</returns>
unsigned int setTexture(const char*);