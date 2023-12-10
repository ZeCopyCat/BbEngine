#include "FileReader.h"

#include "../core/Log.h"
#include <filesystem>

namespace Bb {

    std::ifstream FileReader::s_currentFile = std::ifstream();

    void FileReader::OpenFile(std::string fileName)
    {

#ifdef _DEBUG
        if (s_currentFile.is_open()) {

            Log("Attempting to open a file while the FileReader already has a file currently open. (FileReader.cpp)", LogLevel::Error);
            return;

        }
#endif

        s_currentFile.open(fileName);

        return;

    }

    bool FileReader::IsFileOpen()
    {

        return s_currentFile.is_open();
    
    }

    bool FileReader::AtEndOfFile()
    {

#ifdef _DEBUG
        if (!s_currentFile.is_open()) {

            Log("Attempting to read check if at end of file while the FileReader has no file currently open. (FileReader.cpp)", LogLevel::Error);
            return true;

        }
#endif

        return !s_currentFile.good();

    }

    bool FileReader::DoesFileExist(std::string fileName)
    {

        return std::filesystem::exists(fileName);
    
    }

    std::string FileReader::NextLine()
    {

#ifdef _DEBUG
        if (!s_currentFile.is_open()) {

            Log("Attempting to read a file's line while the FileReader has no file currently open. (FileReader.cpp)", LogLevel::Error);
            return "";

        }
#endif

        std::string output;
        std::getline(s_currentFile, output);

        return output;
    
    }

    void FileReader::CloseFile()
    {

#ifdef _DEBUG
        if (!s_currentFile.is_open()) {

            Log("Attempting to close a file while the FileReader has no file currently open. (FileReader.cpp)", LogLevel::Error);
            return;

        }
#endif

        s_currentFile.close();

        return;
    }

}