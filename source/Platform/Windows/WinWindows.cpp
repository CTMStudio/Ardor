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
		// ��ʼ��glfw
		glfwInit();

		// ��ʼ��ogl�汾 TODO by stl��֧��ogl���ú�����ƽ̨
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		// ��������
		mWindows = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);
		if (nullptr == mWindows)
		{
			LogError("WinWindows::Init glfw init failed");
			glfwTerminate();
			return false;
		}

		// ����ogl������
		glfwMakeContextCurrent(mWindows);

		// ��ʼ��glad
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
