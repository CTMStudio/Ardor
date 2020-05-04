#pragma once
#include <string>

struct GLFWwindow;

namespace Ardor {
	class RenderWindow
	{
	public:
		RenderWindow();

		~RenderWindow();

		bool Init(int width, int height, std::string& title);

		int GetWidth();

		int GetHeight();

	private:
		static void onWindowSizeCallback(GLFWwindow* window, int width, int height);

		static void onErrorCallback(int error, const char* description);

		static void onKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);

	private:
		GLFWwindow* mWindows{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}

