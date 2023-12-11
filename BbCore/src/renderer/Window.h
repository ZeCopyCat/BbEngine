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
		inline static bool IsOpen() { return s_window->renderWindow.isOpen(); }
		static bool PollEvents(sf::Event& event) { return s_window->renderWindow.pollEvent(event); }

	private:

		sf::RenderWindow renderWindow;

		Window();


		static Window* s_window;

	};

}
