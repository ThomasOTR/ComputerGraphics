#pragma once
#include "Material.h"
#include <string>

/* 
 * Shader Paths 
 */
extern const char* basicFragPath;
extern const char* basicVertPath;
extern const char* phongFragPath;
extern const char* phongVertPath;
extern const char* skyboxFragPath;
extern const char* skyboxVertPath;

/* 
 * Materials
 */
extern Material defaultMaterial;

/*
 * Light Sources 
 */

extern glm::vec3 LightSource;

/*
 *  Resource paths
 */

extern std::string blenderObjectPath;
extern std::string objectPath;
extern std::string resourcePath;