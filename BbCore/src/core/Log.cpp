#include "Log.h"

#include "LogManager.h"

namespace Bb {

	void Log(const char* message, LogLevel logLevel)
	{

		switch (logLevel) {

		default:
			LogManager::GetLog()->info(message);
			break;

		case LogLevel::Warning:
			LogManager::GetLog()->warn(message);
			break;

		case LogLevel::Error:
			LogManager::GetLog()->error(message);
			break;

		}

	}

}