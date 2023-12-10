#include "Renderer.h"

#include "Window.h"

namespace Bb {

	void Renderer::Initialize()
	{

		Window::OpenWindow();

	}

	void Renderer::Shutdown()
	{

		Window::CloseWindow();

	}

	void Renderer::Render()
	{

		Window::GetWindow().renderWindow.clear();
		Window::GetWindow().renderWindow.display();

	}

}