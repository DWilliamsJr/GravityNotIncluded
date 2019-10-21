#include "PCH.h"

#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "GO/GameObject.h"



class Renderer
{
private:
	GLFWwindow *window;

public:

	Renderer();

	void printShaderLog(unsigned int T_Shader);

	void printProgramLog(unsigned int T_Program);

	bool checkError();

	unsigned int CreateProgram(char* vShaderProgram, char* fShaderProgram);

	void init(GLFWwindow *window);

	void RenderLoop(GameObject **PlanetList);

	GLFWwindow* getWindow();

	~Renderer();
};