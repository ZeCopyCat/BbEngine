#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

#include "../structures/Vector2.h"

namespace Bb {

	class Window
	{

	public:

		~Window();

		static Window* OpenWindow();
		static void CloseWindow();

		inline static CORE Window& GetWindow() { return *s_window; }
		inline static bool IsOpen() { return s_window->m_renderWindow.isOpen(); }
		static bool PollEvents(sf::Event& event);
		static void RenderVisibleBuffer();

		inline static Vector2u GetResolution() { return s_window->m_resolution; }
		static void SetResolution(Vector2u resolution);
		static void SetResolution(unsigned int width, unsigned int height);

	private:

		sf::RenderWindow m_renderWindow;
		Vector2u m_resolution;

		Window();

		void FixLetterboxing();

		static Window* s_window;

	};

}
