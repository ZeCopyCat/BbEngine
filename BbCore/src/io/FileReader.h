#pragma once

#include <fstream>
#include "../core/Macros.h"

namespace Bb {

	class FileReader {

	public:

		static CORE void OpenFile(std::string fileName);
		static CORE bool IsFileOpen();
		static CORE bool AtEndOfFile();
		static CORE bool DoesFileExist(std::string fileName);
		static CORE std::string NextLine();
		static CORE void CloseFile();

	private:

		static std::ifstream s_currentFile;

	};

}