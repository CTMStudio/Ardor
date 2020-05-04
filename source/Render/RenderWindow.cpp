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
