#include "RenderWindow.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "Log.h"

namespace Ardor {
	RenderWindow::RenderWindow()
	{

	}

	RenderWindow::~RenderWindow()
	{
		if (nullptr != mWindows)
		{
			glfwDestroyWindow(mWindows);
		}
	}

	bool RenderWindow::Init(int width, int height, std::string& title)
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
		glfwSetErrorCallback(onErrorCallback);
		glfwSetKeyCallback(mWindows, onKeyCallback);

		return true;
	}

	int RenderWindow::GetWidth()
	{
		return mWidth;
	}

	int RenderWindow::GetHeight()
	{
		return mHeight;
	}

	void RenderWindow::onWindowSizeCallback(GLFWwindow* window, int width, int height)
	{
		
	}

	void RenderWindow::onErrorCallback(int error, const char* description)
	{
		LogError("RenderWindows::onErrorCallback error:{}, description:{}", error, description);
	}

	void RenderWindow::onKeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode)
	{

	}

}
