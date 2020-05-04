#pragma once
#include <string>
#include "Engine.h"

namespace spdlog {
	class logger;
}

typedef DLL_API Ardor::IEngine* (*CreateEnginePtr)();
typedef DLL_API void (*DeleteEnginePtr)();

class IApplication
{
public:
	IApplication(const std::string &appName);

	virtual ~IApplication();

	virtual bool PreInit() { return true; }

	virtual bool Init();

	virtual bool PostInit() { return true; }

	Ardor::IEngine* GetEngine() { return mEngine; }

private:
	CreateEnginePtr mCreateEngineFunc{ nullptr };
	DeleteEnginePtr mDeleteEngineFunc{ nullptr };

	Ardor::IEngine* mEngine{ nullptr };

	std::string mName;
	spdlog::logger* mLogger{ nullptr };
};

