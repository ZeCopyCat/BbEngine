#pragma once

#include "Macros.h"

namespace Bb {

	class CORE Application {

	public:

		static void Run();
		static Application& Get();

	private:

		Application();
		~Application();

		static Application* s_Instance;

	};

}