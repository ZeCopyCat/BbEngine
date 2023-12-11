#include "Log.h"

namespace Bb {

	std::shared_ptr<spdlog::logger> LogManager::s_logger = nullptr;

	void LogManager::Initialize()
	{

		s_logger = spdlog::stdout_color_mt("log");
		s_logger->set_level(spdlog::level::trace);
		s_logger->set_pattern("(%r) : %^[%=9l]%$ : %v");

	}

	void LogManager::LogToConsole(std::string message, LogLevel logLevel)
	{

		switch (logLevel) {

		default:
			s_logger->info(message);
			break;

		case LogLevel::Warning:
			s_logger->warn(message);
			break;

		case LogLevel::Error:
			s_logger->error(message);
			break;

		}

	}

}