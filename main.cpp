// If you are using glew then change <glad/glad.h> to <GL/glew.h>

#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <stb_image.h>
#include <iostream>


int main()
{
	/* Initialize GLFW */
	glfwInit();

	/* Initialize Version 3.3 */
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__

	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

	// Create a window
	GLFWwindow* window = glfwCreateWindow(1200, 800, "OpenGL 3.3", NULL, NULL);

    // Create an image
    GLFWimage image;
    image.pixels = stbi_load("res/awesomeface.png", &image.width, &image.height, 0, 4);

	// Check window
	if (!window)
	{
		std::cout << "Failed to create a window\n";
		glfwTerminate();
	}

	/* The most important part */
	glfwMakeContextCurrent(window);
    glfwSetWindowIcon(window, 1, &image);

	// Check Glew
    // if u use glew then instead this condition use if(glewInit() != GLEW_OK)
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) 
	{
		std::cout << "Failed to initialize Glew\n";
		glfwTerminate();
	}

    // Load Image
    stbi_image_free(&image.pixels);

	/* Game Loop */
	while (!glfwWindowShouldClose(window))
	{
		/* Update */

		/* Render */
		glClearColor(0.1f, 0.2f, 0.3f, 1.0f); // 0.0f - 1.0f
		glClear(GL_COLOR_BUFFER_BIT);

		// Display 
		glfwSwapBuffers(window);

		// Pollevents
		glfwPollEvents();
	}

	/* Clear */
	glfwDestroyWindow(window);
	glfwTerminate();
}