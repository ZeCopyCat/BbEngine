#pragma once

#include "Macros.h"

namespace Bb {

	class CORE Application {

	public:

		static void Run();
		inline static Application& Get() { return *s_instance; };

	private:

		Application();
		~Application();

		static Application* s_instance;

	};

}