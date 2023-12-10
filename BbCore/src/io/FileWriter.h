#pragma once

#include <fstream>
#include "../core/Macros.h"

namespace Bb {

	class FileWriter {

	public:

		static CORE void OpenFile(std::string fileName);
		static CORE bool IsFileOpen();
		static CORE void Write(std::string text);
		static CORE void WriteLine(std::string line);
		static CORE void CloseFile();

	private:
		
		static std::ofstream s_currentFile;

	};

}