#pragma once
#include <string>

struct GLFWwindow;

namespace Ardor {
	class WinWindows
	{
	public:
		WinWindows();

		bool Init(int width, int height, std::string& title);

	private:
		static void onWindowSizeCallback(GLFWwindow* window, int width, int height);

	private:
		GLFWwindow* mWindows{ nullptr };

		int mWidth{ 0 };
		int mHeight{ 0 };
	};
}

