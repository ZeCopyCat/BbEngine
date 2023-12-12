#pragma once

#include <array>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "../structures/Vector2.h"
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

		inline sf::RectangleShape& GetRectangleShape() { return m_shape; }
		inline sf::RenderTexture& GetRenderTexture() { return m_texture; }

		void CreateTexture(Vector2u resolution);
		void Compile();

		Buffer();

	private:
		sf::RenderTexture m_texture;
		sf::RectangleShape m_shape;

	};

	class BufferManager {

	public:

		~BufferManager() = default;

		static void Initialize();
		static void Shutdown();
		static void SetBufferResolution(unsigned int buffer, Vector2u resolution);
		inline static Buffer& GetBuffer(unsigned int buffer) { return s_instance->m_buffers[buffer]; }
		inline static std::array<Buffer, 7>& GetBuffers() { return s_instance->m_buffers; }

	private:

		BufferManager() = default;

		static BufferManager* s_instance;
		std::array<Buffer, 7> m_buffers;

	};

}