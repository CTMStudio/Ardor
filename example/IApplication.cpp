#include "IApplication.h"
#include <iomanip>
#include <sstream>
#include <windows.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

IApplication::IApplication(const std::string& appName)
{
	mName = appName;

	auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	// 转为字符串
	std::stringstream ss;
	ss << std::put_time(std::localtime(&t), "%Y_%m_%d_%H_%M_%S");
	std::string strTime = ss.str();

	std::string logName = appName + "_" + strTime + ".txt";

	auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logName, true);
	mLogger = new spdlog::logger(appName, { console_sink, file_sink });
	mLogger->set_level(spdlog::level::debug);
}

IApplication::~IApplication()
{
	if (mDeleteEngineFunc)
	{
		mDeleteEngineFunc();
		mDeleteEngineFunc = nullptr;
		mCreateEngineFunc = nullptr;
		mEngine = nullptr;
	}
}

bool IApplication::Init()
{
	mLogger->info("Init start");

	if (!PreInit())
	{
		mLogger->error("IApplication::Init preinit failed");
		return false;
	}

	// 初始化Engine
#ifdef _DEBUG
	HMODULE module = LoadLibrary("Ardord.dll");
#else
	HMODULE module = LoadLibrary("Ardor.dll");
#endif
	if (nullptr == module)
	{
		mLogger->error("IApplication::Init load Ardor.dll failed");
		return false;
	}

	mCreateEngineFunc = (CreateEnginePtr)GetProcAddress(module, "CreateEngine");
	mDeleteEngineFunc = (DeleteEnginePtr)GetProcAddress(module, "DeleteEngine");

	if (!mCreateEngineFunc || !mDeleteEngineFunc)
	{
		mLogger->error("IApplication::Init get funcptr failed");
		return false;
	}


	mEngine = mCreateEngineFunc();
	if (nullptr == mEngine)
	{
		mLogger->error("IApplication::Init null engine");
		return false;
	}

	return PostInit();
}
