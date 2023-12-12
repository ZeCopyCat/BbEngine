#include "Renderer.h"

#include "Window.h"
#include "../io/SettingsReader.h"
#include "../core/Errorcodes.h"
#include "../core/Log.h"
#include "Buffers.h"

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
		BufferManager::Initialize();

	}

	void Renderer::Shutdown()
	{

		Window::CloseWindow();
		BufferManager::Shutdown();

	}

	void Renderer::Render()
	{

		std::array<Buffer, 7>& buffers = BufferManager::GetBuffers();

		s_sortedRendereeIDs.clear();

		// First, we get all of the objects and sort them. Thanks to our ecs-style array, this should be quick.
		for (int i = 0; i < s_renderees.size(); i++) {

			if (!s_renderees[i].active)
				continue;

			s_sortedRendereeIDs.push_back(s_renderees[i].id);

		} //TODO: IMPLEMENT SORTING ALG

		// Then, we clear our buffers.
		for (int i = 0; i < buffers.size(); i++)
			if (i != 2) // Is not the UI layer, should be opaque. If it is it should be clear.
				buffers[i].GetRenderTexture().clear(sf::Color::Black);
			else
				buffers[i].GetRenderTexture().clear(sf::Color(0, 0, 0, 0));

		// Then draw all of our objects to the buffers they wish. once again, the ecs-style array makes this a breeze.
		for (int i = 0; i < s_sortedRendereeIDs.size(); i++) {

			if (DOES_MASK_HAVE_FLAGS(s_renderees[i].renderMask, RENDER_MASK_WORLD))
				buffers[1].GetRenderTexture().draw(s_renderees[i].rectShape);

			if (DOES_MASK_HAVE_FLAGS(s_renderees[i].renderMask, RENDER_MASK_UI))
				buffers[2].GetRenderTexture().draw(s_renderees[i].rectShape);

			if (DOES_MASK_HAVE_FLAGS(s_renderees[i].renderMask, RENDER_MASK_CUSTOM_1))
				buffers[3].GetRenderTexture().draw(s_renderees[i].rectShape);

			if (DOES_MASK_HAVE_FLAGS(s_renderees[i].renderMask, RENDER_MASK_CUSTOM_2))
				buffers[4].GetRenderTexture().draw(s_renderees[i].rectShape);

			if (DOES_MASK_HAVE_FLAGS(s_renderees[i].renderMask, RENDER_MASK_CUSTOM_3))
				buffers[5].GetRenderTexture().draw(s_renderees[i].rectShape);

			if (DOES_MASK_HAVE_FLAGS(s_renderees[i].renderMask, RENDER_MASK_CUSTOM_4))
				buffers[6].GetRenderTexture().draw(s_renderees[i].rectShape);

		}

		// Compile the buffers
		for (int i = 1; i <= 6; i++)
			buffers[i].Compile();

		// Draw our newly compiled buffers to the visible buffer.
		buffers[0].GetRenderTexture().draw(buffers[1].GetRectangleShape());
		buffers[0].GetRenderTexture().draw(buffers[2].GetRectangleShape());

		// Compile the visible buffer
		buffers[0].Compile();

		// Render the visible buffer on the window.
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

		// Get the next available renderee ID and discard it.
		RendereeID newRendereeID = s_availableRendereeIDs.top();
		s_availableRendereeIDs.pop();

		// Reset the renderee in the case it has shit we don't want.
		Renderee& newRenderee = s_renderees[newRendereeID];
		newRenderee.Reset(true);

		// Return the new rendereeID
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