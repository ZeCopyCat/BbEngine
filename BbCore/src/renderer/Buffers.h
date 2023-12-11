#pragma once

#include <array>
#include <SFML/Graphics/RenderTexture.hpp>
#include "RenderMask.h"

namespace Bb {

	class Buffer {

	public:

		//void Render();
		//TO CARTER IN THE FUTURE:
		/*
		
		THE STRATEGY IS TO PUT RECTS IN FRONT OF THE MAIN CAMERAS VIEW,
		ALLOWING US TO STACK THEM LITERALLY ON TOP OF EACH OTHER CREATING A NICE LAYER
		SYSTEM WITHOUT MUCH EFFORT AT ALL. THIS MEANS WE CAN HAVE A VIGNETTE, BLOOM, ETC.
		PLUS THIS WOULD ALLOW US TO DO ALL OUR SORTING IN ONE SWEEP WHICH WOULD BE OPTIMAL.
		DON'T FUCK THIS UP BRO.
		
		*/

	private:

		sf::RenderTexture m_texture;

	};

	class BufferManager {

	public:

		inline static Buffer& GetBuffer(unsigned int buffer) { return s_buffers[buffer]; }

	private:

		static std::array<Buffer, 6> s_buffers;

	};

}