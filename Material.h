#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SOIL2.h>

#include "Shader.h"

class Material{
private:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	GLint diffuseTex;
	GLint specularTex;
	GLfloat alpha;
public:
	Material(glm::vec3 ambient,
			 glm::vec3 diffuse,
			 glm::vec3 specular,
			 GLint diffuseTex,
			 GLint specularTex,
			 GLfloat alpha)
	{
		this->ambient = ambient;
		this->diffuse = diffuse;
		this->specular = specular;
		this->diffuseTex = diffuseTex;
		this->specularTex = specularTex; 
		this->alpha = alpha;
	}

	~Material(){}

	void sendToShader(Shader& program){
		program.setVec3f(this->ambient, "material.ambient");
		program.setVec3f(this->diffuse, "material.diffuse");
		program.setVec3f(this->specular, "material.specular");
		program.set1i(this->diffuseTex, "material.diffuseTex");
		program.set1i(this->specularTex, "material.specularTex");
		program.setVec1f(this->alpha, "material.alpha");
	}
};