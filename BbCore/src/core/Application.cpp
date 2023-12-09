#include "Application.h"

#include "LogManager.h"
#include "Log.h" //D

namespace Bb {

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{

		LogManager::Initialize();

		Log("It's great to be a hero!");
		Log("But would it be so bad...", LogLevel::Warning);
		Log("To be the villain for a change?", LogLevel::Error);
		while (true);

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{

		//Don't allow someone to run more than once.
		if (s_Instance)
			return;

		//Throw a singleton onto the heap.
		s_Instance = new Application();

	}


	Application& Application::Get()
	{

		return *s_Instance;

	}

}