#include "EngineImp.h"
#include "Log.h"
#include <new.h>

namespace Ardor
{
	IEngine* sEngine = nullptr;

	EngineImp::EngineImp()
	{

	}

	EngineImp::~EngineImp()
	{

	}

	void EngineImp::Test()
	{
		LogInfo("test");
	}

	IEngine* CreateEngine()
	{
		if (nullptr == sEngine)
		{
			_set_new_mode(1);
			sEngine = new EngineImp();
		}

		return sEngine;
	}

	void DeleteEngine()
	{
		if (nullptr != sEngine)
		{
			delete sEngine;
			sEngine = nullptr;
		}
	}
}
