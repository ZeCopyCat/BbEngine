#pragma once

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Bb {

	class LogManager {

	public:

		static void Initialize();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return s_logger; }

	private:

		static std::shared_ptr<spdlog::logger> s_logger; // Automatic memory management for logger

	};

}