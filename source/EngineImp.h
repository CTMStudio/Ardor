#pragma once
#include "Engine.h"

namespace Ardor {
	class EngineImp : public IEngine
	{
	public:
		EngineImp();
		virtual ~EngineImp();

		virtual void Test();
	};
}

