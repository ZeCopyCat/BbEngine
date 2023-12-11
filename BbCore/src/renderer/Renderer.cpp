#include "Renderer.h"

#include "Window.h"
#include "../io/SettingsReader.h"
#include "../core/Errorcodes.h"
#include "../core/Log.h"

namespace Bb {

	std::vector<Renderee> Renderer::s_renderees = std::vector<Renderee>();
	std::vector<RendereeID> Renderer::s_sortedRendereeIDs = std::vector<RendereeID>();
	std::stack<RendereeID> Renderer::s_availableRendereeIDs = std::stack<RendereeID>();

	void Renderer::Initialize()
	{

		// Set up all the renderees
		for (unsigned int i = SettingsReader::GetMaximumRenderees(); i > 0; i--) {

			s_availableRendereeIDs.push(i - 1);

			Renderee newRenderee = Renderee(SettingsReader::GetMaximumRenderees() - i, false);

			s_renderees.push_back(newRenderee);

		}

		Window::OpenWindow();

	}

	void Renderer::Shutdown()
	{

		Window::CloseWindow();

	}

	void Renderer::Render()
	{

		//First, we get all of the objects and sort them. Thanks to our ecs-style array, this should be quick.

		//Then, we clear our buffers.

		//Then draw all of our objects to all the buffers. once again, the ecs-style array makes this a breeze.

		//Render the visible buffer on the window.
		Window::RenderVisibleBuffer();

	}

	RendereeID Renderer::InstantiateRenderee()
	{

		if (s_availableRendereeIDs.empty())
#if _DEBUG
			LOG_ERROR("Renderees exceeds limit. (Renderer.cpp)");
#else
			exit(Errorcode::TooManyRenderees);
#endif

		RendereeID newRendereeID = s_availableRendereeIDs.top();
		s_availableRendereeIDs.pop();

		// OMG MINI CONSTRUCTOR! Prolly should fix this in the future. Or is it so we don't re-allocate? Who knows. Eventually we'll fix this.
		Renderee& newRenderee = s_renderees[newRendereeID];
		newRenderee.Reset(true);

		return newRendereeID;

	}

	void Renderer::DestroyRenderee(RendereeID id)
	{

		Renderee& renderee = s_renderees[id];
		renderee.active = false;
		//TODO: UNSUBSCRIBE FROM TEXTURE MANAGER.

		s_availableRendereeIDs.push(id);

	}

}