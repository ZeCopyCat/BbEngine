#include "FileWriter.h"

#ifdef _DEBUG
#include "../core/Log.h"
#endif

namespace Bb {

	std::ofstream FileWriter::s_currentFile = std::ofstream();

	void FileWriter::OpenFile(std::string fileName)
	{

#ifdef _DEBUG
		if (s_currentFile.is_open()) {

			LOG_ERROR("Attempting to open a file while the FileWriter already has a file currently open. (FileWriter.cpp)");
			return;

		}
#endif

		s_currentFile.open(fileName);

	}

	bool FileWriter::IsFileOpen()
	{

		return s_currentFile.is_open();

	}

	void FileWriter::Write(std::string text)
	{

#ifdef _DEBUG
		if (!s_currentFile.is_open()) {

			LOG_ERROR("Attempting to write to a file while the FileWriter has no file currently open. (FileWriter.cpp)");
			return;

		}
#endif

		s_currentFile << text;

	}

	void FileWriter::WriteLine(std::string line)
	{

#ifdef _DEBUG
		if (!s_currentFile.is_open()) {

			LOG_ERROR("Attempting to write a line to a file while the FileWriter has no file currently open. (FileWriter.cpp)");
			return;

		}
#endif

		s_currentFile << line << "\n";

	}

	void FileWriter::CloseFile()
	{

#ifdef _DEBUG
		if (!s_currentFile.is_open()) {

			LOG_ERROR("Attempting to close a file while the FileWriter has no file currently open. (FileWriter.cpp)");
			return;

		}
#endif

		s_currentFile.close();

	}

}