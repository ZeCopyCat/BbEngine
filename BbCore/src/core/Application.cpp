#include "Application.h"

#include <stdio.h>

using namespace Bb;

Application* Application::m_singleton = nullptr;

Application::Application()
{

	printf("Feels good to be king.");
	while (true);

}

Application::~Application()
{

}

void Application::Run()
{

	if (m_singleton)
		return;

	m_singleton = new Application();

}


Application& Application::Get()
{

	return *m_singleton;

}