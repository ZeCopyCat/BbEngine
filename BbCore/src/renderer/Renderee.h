#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "../core/Macros.h"
#include "RenderMask.h"

namespace Bb {

	typedef unsigned int RendereeID;

	struct Renderee {

		sf::RectangleShape rectShape;
		int z = 0;
		RendereeID id = 0;
		RenderMask renderMask = RENDER_MASK_VISIBLE;
		bool active = false;

	};

}