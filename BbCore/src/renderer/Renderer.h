#pragma once

#include <stack>
#include <vector>
#include <set>
#include "Renderee.h"

namespace Bb {

	class Renderer
	{

	public:

		static void Initialize();
		static void Shutdown();

		static void Render();

		static RendereeID InstantiateRenderee();
		inline static Renderee& GetRenderee(RendereeID id) { return s_renderees[id]; }
		static void DestroyRenderee(RendereeID id);

	private:

		static std::vector<Renderee> s_renderees;
		static std::vector<RendereeID> s_sortedRendereeIDs;
		static std::stack<RendereeID> s_availableRendereeIDs;
		static std::set<RendereeID> s_unavailableRendereeIDs;

	};

}