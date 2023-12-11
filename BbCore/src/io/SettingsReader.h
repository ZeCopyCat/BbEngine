#pragma once

#include "../structures/Vector2.h"

#define DEFAULT_RESOLUTION Vector2u(1280, 720)
#define DEFAULT_MAXIMUM_RENDEREES 10000

namespace Bb {

	class SettingsReader {

	public:

		static void ReadSettings();

		inline static Vector2u GetResolution() { return s_resolution; }
		inline static unsigned int GetMaximumRenderees() { return s_maximumRenderees; }

	private:

		static Vector2u s_resolution;
		static unsigned int s_maximumRenderees;

	};

}