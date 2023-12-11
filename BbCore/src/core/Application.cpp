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

		RendereeID myBoxID = Renderer::InstantiateRenderee(); //D
		Renderee& myBox = Renderer::GetRenderee(myBoxID); //D

		while (window.IsOpen()) {

			sf::Event event;
			while (window.PollEvents(event)) {

				if (event.type == sf::Event::Closed)
					queueApplicationClose = true;

			}

			if (queueApplicationClose)
				break;

		}

		Renderer::DestroyRenderee(myBoxID); //D
		
		Shutdown();

		return;

	}

}