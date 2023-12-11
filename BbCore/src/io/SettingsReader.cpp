#include "SettingsReader.h"

#include "../core/Log.h"
#include "FileReader.h"
#include "FileWriter.h"

namespace Bb {

    Vector2u SettingsReader::s_resolution = DEFAULT_RESOLUTION;
    unsigned int SettingsReader::s_maximumRenderees = DEFAULT_MAXIMUM_RENDEREES;

    void SettingsReader::ReadSettings()
    {

        // Load the settings from EngineSettings.ini, or make a new EngineSettings.ini
        if (!FileReader::DoesFileExist("EngineSettings.ini")) {

            LOG_WARNING("EngineSettings.ini could not be found. Creating defaults now.");

            WriteCurrentSettings();

        }
        else {

            FileReader::OpenFile("EngineSettings.ini");

            FileReader::NextLine();
            s_resolution.x = std::stoi(FileReader::NextLine().substr(12)); // Substring is for "ResolutionX="
            s_resolution.y = std::stoi(FileReader::NextLine().substr(12)); // Substring is for "ResolutionY="
            s_maximumRenderees = (unsigned int)std::stoi(FileReader::NextLine().substr(17)); // Substring is for "MaximumRenderees="

            FileReader::CloseFile();

        }

    }

    void SettingsReader::WriteCurrentSettings()
    {

        FileWriter::OpenFile("EngineSettings.ini");

        FileWriter::WriteLine("[Settings]");
        FileWriter::WriteLine("ResolutionX=" + std::to_string(s_resolution.x));
        FileWriter::WriteLine("ResolutionY=" + std::to_string(s_resolution.y));
        FileWriter::Write("MaximumRenderees=" + std::to_string(s_maximumRenderees));

        FileWriter::CloseFile();

    }

}