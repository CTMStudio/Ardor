#include "Log.h"
namespace Ardor
{
	Log* Ardor::Log::sLog = nullptr;

	Log* Log::Get()
	{
		if (nullptr == sLog)
		{
			sLog = new Log;
			sLog->Init();
			return sLog;
		}

		return sLog;
	}

	void Log::Init()
	{
		auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>("EngineLog.txt", true);
		mLogger = new spdlog::logger("multi_sink", { console_sink, file_sink });
		mLogger->set_level(spdlog::level::debug);
	}

	void Log::SetLevel(spdlog::level::level_enum level)
	{
		mLogger->set_level(level);
	}

	spdlog::logger* Log::GetLogger()
	{
		return mLogger;
	}

}
