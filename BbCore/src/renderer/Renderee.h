#pragma once

#include <SFML/Graphics/RectangleShape.hpp>

#include "../core/Macros.h"
#include "RenderMask.h"

namespace Bb {

	typedef unsigned int RendereeID;

	struct Renderee {

		Renderee(RendereeID id, bool active) : id(id), active(active), rectShape(sf::RectangleShape(sf::Vector2f(2.0f, 2.0f))) {}
		void Reset(bool active = false) {
		
			this->active = active;
			RenderMask renderMask = RENDER_MASK_VISIBLE;
			rectShape = sf::RectangleShape(sf::Vector2f(2.0f, 2.0f));
			z = 0;
		
		}

		sf::RectangleShape rectShape;
		int z = 0;
		RendereeID id = 0;
		RenderMask renderMask = RENDER_MASK_VISIBLE;
		bool active = false;

	};

}