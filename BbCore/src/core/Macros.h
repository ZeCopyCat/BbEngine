#pragma once

// Gets rid of ugly declspec import/export nonsense.
#ifdef Bb_BUILD_CORE
	#define CORE _declspec(dllexport)
#else
	#define CORE _declspec(dllimport)
#endif