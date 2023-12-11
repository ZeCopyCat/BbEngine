#pragma once

#include "Macros.h"
#include "Errorcodes.h"

namespace Bb {

	class CORE Application {

	public:

		void Run();

	private:

		void Initialize();
		void Shutdown();

		static Application* s_instance;

	};

}