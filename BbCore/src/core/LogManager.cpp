#include "LogManager.h"

namespace Bb {

	std::shared_ptr<spdlog::logger> LogManager::s_Log = nullptr;

	void LogManager::Initialize()
	{

		s_Log = spdlog::stdout_color_mt("log");
		s_Log->set_level(spdlog::level::trace);
		s_Log->set_pattern("(%r) : %^[%=9l]%$ : %v");

	}

}