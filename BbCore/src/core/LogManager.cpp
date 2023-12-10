#include "LogManager.h"

namespace Bb {

	std::shared_ptr<spdlog::logger> LogManager::s_logger = nullptr;

	void LogManager::Initialize()
	{

		s_logger = spdlog::stdout_color_mt("log");
		s_logger->set_level(spdlog::level::trace);
		s_logger->set_pattern("(%r) : %^[%=9l]%$ : %v");

	}

}