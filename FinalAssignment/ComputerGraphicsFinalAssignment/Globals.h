#pragma once
#include "Material.h"
#include "Light.h"

/* 
 * Shader Paths 
 */
extern const char* basicFragPath;
extern const char* basicVertPath;
extern const char* textureFragPath;
extern const char* textureVertPath;
extern const char* phongFragPath;
extern const char* phongVertPath;
extern const char* lambertFragPath;
extern const char* lambertVertPath;
extern const char* skyboxFragPath;
extern const char* skyboxVertPath;

/* 
 * Materials
 */
extern const Material defaultMaterial;

/*
 * Light Sources 
 */

extern const Light defaultLight;

/*
 *  Resource paths
 */

extern const char* blenderObjectPath;
extern const char* objectPath;
extern const char* resourcePath;