#pragma once

#include <string>
#include "Macros.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bb {

	enum LogLevel {

		Error, // This is for stuff that shouldn't happen and will break the shit.
		Warning, // This is to let you know you should fix something.
		Info // This is just for information. Duh.

	};


	class LogManager {

	public:

		static void Initialize();

		static CORE void LogToConsole(std::string, LogLevel = LogLevel::Info);

	private:

		static std::shared_ptr<spdlog::logger> s_logger; // Automatic memory management for logger

	};

#ifdef _DEBUG
	#define LOG(string) LogManager::LogToConsole(string)
	#define LOG_WARNING(string) LogManager::LogToConsole(string, LogLevel::Warning)
	#define LOG_ERROR(string) LogManager::LogToConsole(string, LogLevel::Error)
#else
	#define LOG(string) // No Log needed, we don't have a console :)
	#define LOG_WARNING(string) // No Log needed, we don't have a console :)
	#define LOG_ERROR(string) // No Log needed, we don't have a console :)
#endif

}