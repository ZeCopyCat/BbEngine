#include "Application.h"

#include <SFML/Window/Event.hpp>

#include "Log.h"
#include "LogManager.h"
#include "../renderer/Renderer.h"
#include "../renderer/Window.h"
#include "../core/Application.h"
#include "../io/SettingsReader.h"

namespace Bb {

	Application* Application::s_instance = nullptr;

	Application::Application()
	{

		LogManager::Initialize();
		Log("Reading Settings...");
		SettingsReader::ReadSettings();
		Log("Starting Renderer...");
		Renderer::Initialize();

	}

	Application::~Application()
	{

		Log("Closing Renderer...");
		Renderer::Shutdown();

	}

	void Application::Run()
	{

#ifdef _DEBUG
		// Don't allow someone to run more than once.
		if (s_instance)
			return;
#endif

		// Throw a singleton onto the heap.
		s_instance = new Application();

		Window& window = Window::GetWindow();

		while (window.IsOpen()) {

			sf::Event event;
			while (window.PollEvents(event)) {

				if (event.type == sf::Event::Closed)
					window.renderWindow.close(); //HACK
			
			}

			Renderer::Render();

		}

		delete s_instance;

	}

}