#include "Graphics.h"

Graphics::Graphics(int windowWidth, int windowHeight, const char* windowTitle)
	: mWindowWidth(windowWidth), mWindowHeight(windowHeight), mWindowTitle(windowTitle)
{
	window = nullptr;

	if (InitializeGLFW())
	{
		InitializeGLEW();
	}
}

Graphics::~Graphics()
{
	glfwDestroyWindow(window);
	glfwTerminate();
}

bool Graphics::InitializeGLFW()
{
	// Initialize GLFW 3.0.4
	if (!glfwInit())
	{
		std::cout << "GLFW initialization failed!" << std::endl;
		return false;
	}

	// Get client video mode to be able to use the device's resolution, refresh rate etc.
	const GLFWvidmode* clientVideoMode = glfwGetVideoMode(glfwGetPrimaryMonitor());

	// Set OpenGL 3.3, core profile and disable window resizing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	// Create the main window using the passed-in values for window size and title and set window position to center
	window = glfwCreateWindow(mWindowWidth, mWindowHeight, mWindowTitle, NULL, NULL);
	glfwSetWindowPos(window, (clientVideoMode->width / 2) - (mWindowWidth / 2), (clientVideoMode->height / 2) - (mWindowHeight / 2));

	if (!window)
	{
		std::cout << "Window creation failed!" << std::endl;
		return false;
	}

	// Create current context
	glfwMakeContextCurrent(window);

	return true;
}

bool Graphics::InitializeGLEW()
{
	glewExperimental = GL_TRUE;

	// Initialize GLEW 1.11.0
	GLenum status = glewInit();

	if (status != GLEW_OK)
	{
		std::cout << "GLEW initialization failed!" << " Error: " << glewGetErrorString(status) << std::endl;
		return false;
	}

	return true;
}

void Graphics::Update()
{
	glfwSwapBuffers(window);
}

void Graphics::Clear(float r, float g, float b, float a)
{
	glClearColor(r, g, b, a);
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(0, 0, mWindowWidth, mWindowHeight);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0f, mWindowWidth, mWindowHeight, 0.0f, -1.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
}