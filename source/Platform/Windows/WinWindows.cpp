#include "WinWindows.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <Log.h>
#include <functional>

namespace Ardor {
	WinWindows::WinWindows()
	{

	}

	bool WinWindows::Init(int width, int height, std::string& title)
	{
		// 初始化glfw
		glfwInit();

		// 初始化ogl版本 TODO by stl：支持ogl配置和其他平台
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// 创建窗口
		mWindows = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (nullptr == mWindows)
		{
			LogError("WinWindows::Init glfw init failed");
			glfwTerminate();
			return false;
		}

		// 设置ogl上下文
		glfwMakeContextCurrent(mWindows);

		// 初始化glad
		// load glad
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			LogError("WinWindows::Init glad load failed");
			return false;
		}

		glfwSetFramebufferSizeCallback(mWindows, onWindowSizeCallback);

		return true;
	}

	void WinWindows::onWindowSizeCallback(GLFWwindow* window, int width, int height)
	{
		
	}

}
