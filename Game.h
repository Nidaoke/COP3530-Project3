#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/vec2.hpp>
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <SOIL2.h>

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

#include "Shader.h"
#include "Texture.h"
#include "Material.h"
#include "Vertex.h"
#include "Mesh.h"
#include "Primitives.h"
#include "Camera.h"
#include "wallToBuild.h"
#include "Graph.h"
#include <tuple>

//ENUMERATIONS
enum shader_enum{SHADER_CORE_PROGRAM = 0};
enum texture_enum{ TEX_WEIGHT1 = 0, TEX_WEIGHT2, TEX_WEIGHT3, TEX_WEIGHT4, TEX_WORM};
//enum texture_enum{TEX_WORM = 0, TEX_WORM_SPECULAR, TEX_STONE, TEX_STONE_SPECULAR};
enum material_enum{MAT_1 = 0};
enum mesh_enum{MESH_QUAD = 0, MESH_CUBE};

class Game{
private:
//Variables
	//window
	GLFWwindow* window;
	//std::vector<std::tuple<int, int, int>> path;
	std::vector<int> path;
	std::vector<int> pathFinal;
	std::vector<int> aPath;

	int countToRender = 0;
	int aCount = 0;

	const int WINDOW_WIDTH;
	const int WINDOW_HEIGHT;
	int framebufferWidth;
	int framebufferHeight;

	//OpenGL Context
	const int GL_VERSION_MAJOR;
	const int GL_VERSION_MINOR;

	//DeltaTime
	float dt;
	float curTime;
	float lastTime;

	//MouseInput
	double lastMouseX;
	double lastMouseY;
	double mouseX;
	double mouseY;
	double mouseOffsetX;
	double mouseOffsetY;
	bool firstMouse;

	//Camera
	Camera camera;

	//Matrices
	glm::mat4 ViewMatrix;
	glm::vec3 camPosition;
	glm::vec3 worldUp;
	glm::vec3 camFront;
	glm::mat4 ProjectionMatrix;
	float fov;
	float nearPlane;
	float farPlane;

	//Shaders
	std::vector<Shader*> shaders;

	//Textures
	std::vector<Texture*> textures;

	//Materials
	std::vector<Material*> materials;

	//Meshes
	std::vector<Mesh*> meshes;
	std::vector<Mesh*> wormMeshes;
	std::vector<Mesh*> wormMeshesFinal;
	std::vector<Mesh*> aMeshes;

	//Lights
	std::vector<glm::vec3*> lights;

	//Walls
	std::vector<wallToBuild*> walls;


//Private Functions
	void initGLFW();
	void initWindow(const char* title, bool resizable);
	void initGLEW(); //After context creation!
	void initOpenGLOptions();
	void initMatrices();
	void initShaders();
	void initTextures();
	void initMaterials();
	void initMeshes();
	void initLights();
	void initUniforms();

	void updateUniforms();

//Static Variables

public:
//Constructors / Destructors
	Game(
		std::vector<wallToBuild*> walls,
		std::vector<int> path,
		std::vector<int> pathFinal,
		std::vector<int> aPath,
		const char* title,
		const int WINDOW_WIDTH, const int WINDOW_HEIGHT,
		const int GL_VERSION_MAJOR, const int GL_VERSION_MINOR,
		bool resizable);
	virtual ~Game();

	bool showFinal = false;

//Accessors
	int getWindowShouldClose();

//Modifiers
	void setWindowShouldClose();

//Functions
	void updateDt();
	void updateMouseInput();
	void updateKeyboardInput();
	void updateInput();
	void update();
	void render();

//Static Functions
	static void framebuffer_resize_callback(GLFWwindow* window, int fbw, int fbh);
	//static void updateInput(GLFWwindow* window, Mesh& mesh);
};

