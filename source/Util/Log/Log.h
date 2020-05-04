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

		~Log();

		void Init();

		void SetLevel(spdlog::level::level_enum level);

		spdlog::logger* GetLogger();

	private:
		Log(){}

	private:
		static Log* sLog;

		spdlog::logger* mLogger{ nullptr };
	};


#define LogDebug(...) Log::Get()->GetLogger()->debug(__VA_ARGS__)
#define LogInfo(...) Log::Get()->GetLogger()->info(__VA_ARGS__)
#define LogError(...) Log::Get()->GetLogger()->error(__VA_ARGS__)
}

