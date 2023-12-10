#include "Log.h"

#include "LogManager.h"

namespace Bb {

	void Log(std::string message, LogLevel logLevel)
	{

		switch (logLevel) {

		default:
			LogManager::GetLogger()->info(message);
			break;

		case LogLevel::Warning:
			LogManager::GetLogger()->warn(message);
			break;

		case LogLevel::Error:
			LogManager::GetLogger()->error(message);
			break;

		}

	}

}