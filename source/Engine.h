#pragma once

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

namespace Ardor
{
	class IEngine
	{
	public:
		virtual ~IEngine() {}

		virtual void Test() = 0;

	};

	extern "C" {
		DLL_API IEngine* CreateEngine();
		DLL_API void DeleteEngine();
	}
}

