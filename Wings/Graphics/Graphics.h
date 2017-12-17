#pragma once
#define GLEW_STATIC
#include <GL\glew.h>
#include <GLFW\glfw3.h>
#include <iostream>
#include <string>
#include <fstream>

class Graphics
{
	public:
		Graphics(int windowWidth, int windowHeight, const char* windowTitle);
		virtual ~Graphics();
		GLFWwindow* window;

		/*
		====================
		Update()

		Contains code that updates the graphics and will be used in a "while" loop.
		====================
		*/
		void Update();

		/*
		====================
		Clear(float r, float g, float b, float a)

		Sets the GL clear color and applies it.
		====================
		*/
		void Clear(float r, float g, float b, float a);

	private:
		/*
		====================
		InitializeGLFW()

		Initializes the GLFW library. This function creates the game's window using the size
		and title parameters passed into the constructor and makes the context current. Returns
		false if initialization fails or if the window wasn't created successfully.
		====================
		*/
		bool InitializeGLFW();

		/*
		====================
		InitializeGLEW()

		Initializes the GLEW library. Returns false if initialization fails.
		====================
		*/
		bool InitializeGLEW();

		int mWindowWidth;
		int mWindowHeight;
		const char* mWindowTitle;
};