#include "SettingsReader.h"

#include "../core/Log.h"
#include "FileReader.h"
#include "FileWriter.h"

namespace Bb {

    Vector2u SettingsReader::s_resolution = Vector2u(1280, 720);

    void SettingsReader::ReadSettings()
    {

        // Load the settings from EngineSettings.ini, or make a new EngineSettings.ini
        if (!FileReader::DoesFileExist("EngineSettings.ini")) {

            Log("EngineSettings.ini could not be found. Creating defaults now.", LogLevel::Info);

            FileWriter::OpenFile("EngineSettings.ini");

            FileWriter::WriteLine("[Settings]");
            FileWriter::WriteLine("ResolutionX=1280");
            FileWriter::Write("ResolutionY=720");

            FileWriter::CloseFile();

        }
        else {

            FileReader::OpenFile("EngineSettings.ini");

            FileReader::NextLine();
            s_resolution.x = std::stoi(FileReader::NextLine().substr(12)); // Substring is for "ResolutionX="
            s_resolution.y = std::stoi(FileReader::NextLine().substr(12)); // Substring is for "ResolutionY="

            FileReader::CloseFile();

        }

    }

}