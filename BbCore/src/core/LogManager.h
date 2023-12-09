#pragma once

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bb {

	class LogManager {

	public:

		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetLog() { return s_Log; }

	private:

		static std::shared_ptr<spdlog::logger> s_Log; //Automatic memory management for logger

	};

}