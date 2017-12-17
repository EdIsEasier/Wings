#pragma once
#include "Graphics\Graphics.h"
#include "Globals.h"

class Input
	{
	public:
		static Input& GetInstance()
		{
			static Input instance;
			return instance;
		}

		static void Keyboard_Callback(GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			GetInstance().Keyboard_Callback_Impl(key, action);
			if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
			{
				glfwSetWindowShouldClose(window, GL_TRUE);
				pressedKey = "escape";
			}
			else if (key == GLFW_KEY_A && action == GLFW_PRESS)
			{
				pressedKey = "A";
			}


		}

		void Keyboard_Callback_Impl(int key, int action)
		{
			switch (action)
			{
			case GLFW_PRESS:
				switch (key)
				{
				case GLFW_KEY_UP:
					pressedKey = "up";
					break;
				case GLFW_KEY_DOWN:
					pressedKey = "down";
					break;
				case GLFW_KEY_LEFT:
					pressedKey = "left";
					break;
				case GLFW_KEY_RIGHT:
					pressedKey = "right";
					break;
				default:
					break;
				}
				break;
			case GLFW_RELEASE:
				pressedKey = "";
			default:
				break;
			}
		}

		static void Mouse_Button_Callback(GLFWwindow* window, int button, int action, int mods)
		{

		}

	private:
		Input()
		{}
		Input(Input const&);
		void operator=(Input const&);
};