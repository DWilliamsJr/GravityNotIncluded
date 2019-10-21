#include "PCH.h"

#include "GravityNotIncluded.h"

int main()
{	
	{
		if (!glfwInit())
		{
			std::cout << "failure to initilize GLFW" << std::endl;
			system("pause");
			return(0);
		}
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

		GravityNotIncluded tempGame;

		if (glewInit() != GLEW_OK)	// must call glewInit after GlfwMakeContextCurrent(window);
		{
			std::cout << "failure to initilize GLEW" << std::endl;
			system("pause");
			return(0);
		}

		tempGame.GameLoop();		
		message::printMessages(_TIMER);
		system("pause");
	}

	delete [] Messages;
}



/*
#include <GLFW/glfw3.h>

int main(void)
{
	GLFWwindow* window;

	if (!glfwInit())
		return -1;

	window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)	// must call glewInit after GlfwMakeContextCurrent(window);
	{
		std::cout << "failure to initilize GLEW" << std::endl;
		system("pause");
		return(0);
	}

	std::cout << glGetString(GL_VERSION) << std::endl;
	
	float data[] =
	{
		-0.5f, -0.5f,
		0.5f, 0.5f,
		0.5f, -0.5f
	};

	unsigned int VBO;
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,  sizeof(data), data, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2, 0);
	std::cout << VBO;
	//glGenBuffers(1, VBO);
	//glBindBuffer(GL_ARRAY_BUFFER, VBO);
	//glBufferData(GL_ARRAY_BUFFER, sizeof(data), data, GL_STATIC_DRAW);

	while (!glfwWindowShouldClose(window))
	{
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		/*glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

		glDrawArrays(GL_TRIANGLES, 0, 3);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}*/