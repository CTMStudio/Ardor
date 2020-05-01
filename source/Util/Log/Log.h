#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Ardor
{
	class Log
	{
	public:
		static Log* Get();

		void Init();

		void SetLevel(spdlog::level::level_enum level);

		spdlog::logger* GetLogger();

	private:
		Log(){}

	private:
		static Log* sLog;

		spdlog::logger* mLogger{ nullptr };
	};


#define LogDebug(x) Log::Get()->GetLogger()->debug(x)
#define LogInfo(x) Log::Get()->GetLogger()->info(x)
#define LogError(x) Log::Get()->GetLogger()->info(x)

}

