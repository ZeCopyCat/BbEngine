#pragma once

#include "Macros.h"

namespace Bb {

	enum LogLevel {

		Error, //This is for stuff that shouldn't happen and will break the shit.
		Warning, //This is to let you know you should fix something.
		Info //This is just for information. Duh.

	};

	CORE void Log(const char*, LogLevel = LogLevel::Info);

}