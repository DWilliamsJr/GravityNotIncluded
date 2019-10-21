#include "PCH.h"
#include "Renderer.h"

Renderer::Renderer()
{
	window = glfwCreateWindow(420, 360, "GRAVITY NOT INCLUDED", NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// GRAPHICS STUFF
	init(window);	// need to make VertexShaderProgram and FragmentShaderProgram before calling this
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
}
void Renderer::printShaderLog(unsigned int T_Shader)
{
	int length = 0;
	int charWidth = 0;
	char *log;
	glGetShaderiv(T_Shader, GL_INFO_LOG_LENGTH, &length);
	if (length > 0)
	{
		log = (char*)malloc(sizeof(char) * length);
		glGetShaderInfoLog(T_Shader, length, &charWidth, log);
		message(_ERROR, log, __FILE__, __LINE__);
		free(log);
	}
	}

void  Renderer::printProgramLog(unsigned int T_Program)
{
	int length = 0;
	int charWidth = 0;
	char *log;
	glGetProgramiv(T_Program, GL_INFO_LOG_LENGTH, &length);
	if (length > 0)
	{
		log = (char*)malloc(sizeof(char) * length);
		glGetProgramInfoLog(T_Program, length, &charWidth, log);
		message(_ERROR, log, __FILE__, __LINE__);
		free(log);
	}
	}

bool  Renderer::checkError()
{
	bool foundError = false;
	int glError = glGetError();
	std::string tempString;
	while (glError != GL_NO_ERROR)
	{

		std::cout << " glError: " << glError << std::endl;
		glError = glGetError();
		foundError = true;
	}
	return foundError;
	}

unsigned int  Renderer::CreateProgram(char* vShaderProgram, char* fShaderProgram)
{
	unsigned int vShader = glCreateShader(GL_VERTEX_SHADER);
	unsigned int fShader = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vShader, 1, &vShaderProgram, NULL);
	glShaderSource(fShader, 1, &fShaderProgram, NULL);

	glCompileShader(vShader);
	glCompileShader(fShader);

	unsigned int program = glCreateProgram();
	glAttachShader(program, vShader);
	glAttachShader(program, fShader);
	glLinkProgram(program);
	return program;
	}

void  Renderer::init(GLFWwindow *window)
{

	}

GLFWwindow* Renderer::getWindow()
{
	return window;
}

Renderer::~Renderer()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

void Renderer::RenderLoop(GameObject **PlanetList)
{
	
	glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
	// GRAPHICS STUFF
	glClear(GL_DEPTH_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int x = 0; x < NumPlanet; x++)
	{
		PlanetList[x]->getGraphics()->update();
		//glDrawArrays(GL_TRIANGLES, 0, 6);
	}
	glfwSwapBuffers(window);
	glfwPollEvents();
	
}
