#pragma once

#include "../structures/Vector2.h"

namespace Bb {

	class SettingsReader {

	public:

		static void ReadSettings();

		inline static Vector2u GetResolution() { return s_resolution; }

	private:

		static Vector2u s_resolution;

	};

}