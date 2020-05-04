#include "Log.h"
#include <iomanip>
#include <sstream>
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

	Log::~Log()
	{
		if (nullptr != mLogger)
		{
			delete mLogger;
			mLogger = nullptr;
		}
	}

	void Log::Init()
	{
		auto t = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

		// ×ªÎª×Ö·û´®
		std::stringstream ss;
		ss << std::put_time(std::localtime(&t), "%Y_%m_%d_%H_%M_%S");
		std::string strTime = ss.str();

		std::string logName = "Engine_" + strTime + ".txt";

		auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto file_sink = std::make_shared<spdlog::sinks::basic_file_sink_mt>(logName, true);
		mLogger = new spdlog::logger("Engine", { console_sink, file_sink });
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
