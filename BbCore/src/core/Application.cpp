#include "Application.h"

#include <SFML/Window/Event.hpp>

#include "Log.h"
#include "../renderer/Renderer.h"
#include "../renderer/Window.h"
#include "../core/Application.h"
#include "../io/SettingsReader.h"

namespace Bb {

	Application* Application::s_instance = nullptr;

	void Application::Initialize()
	{

		LogManager::Initialize();
		LOG("Reading Settings...");
		SettingsReader::ReadSettings();
		LOG("Starting Renderer...");
		Renderer::Initialize();

	}

	void Application::Shutdown()
	{

		LOG("Closing Renderer...");
		Renderer::Shutdown();

	}

	void Application::Run()
	{

		Initialize();

		Window& window = Window::GetWindow();

		bool queueApplicationClose = false;

		RendereeID backgroundID = Renderer::InstantiateRenderee(); //D
		Renderee& background = Renderer::GetRenderee(backgroundID); //D

		RendereeID myBoxID = Renderer::InstantiateRenderee(); //D
		Renderee& myBox = Renderer::GetRenderee(myBoxID); //D

		background.rectShape.setPosition(sf::Vector2f(-1000.f, -1000.f));
		background.rectShape.setSize(sf::Vector2f(5000.f, 5000.f));
		background.rectShape.setFillColor(sf::Color(52, 52, 56));

		myBox.rectShape.setPosition(sf::Vector2f((float)Window::GetResolution().x / 2.f - 50.f, (float)Window::GetResolution().y / 2.f - 50.f));
		myBox.rectShape.setSize(sf::Vector2f(100.f, 100.f));

		while (window.IsOpen()) {

			sf::Event event;
			while (window.PollEvents(event)) {

				if (event.type == sf::Event::Closed)
					queueApplicationClose = true;

				if (event.type == sf::Event::KeyPressed)
					if (event.key.code == sf::Keyboard::E)
						window.SetResolution(Vector2u(500, 1000));

			}

			myBox.rectShape.setPosition(sf::Vector2f((float)Window::GetResolution().x / 2.f - 50.f, (float)Window::GetResolution().y / 2.f - 50.f));

			Renderer::Render();

			if (queueApplicationClose)
				break;

		}

		Renderer::DestroyRenderee(myBoxID); //D
		Renderer::DestroyRenderee(backgroundID); //D
		
		Shutdown();

		return;

	}

}