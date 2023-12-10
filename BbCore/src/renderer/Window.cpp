#include "Window.h"

#include "../core/Log.h"
#include "../io/SettingsReader.h"

namespace Bb {
    
    Window* Window::s_window = nullptr;

    Window::Window() : renderWindow(sf::VideoMode(SettingsReader::GetResolution().x, SettingsReader::GetResolution().y), "BbEngine", sf::Style::Close)
    {

    }

    Window::~Window()
    {

    }

    Window* Bb::Window::OpenWindow()
    {

#ifdef _DEBUG
        if (s_window) {

            Log("Attempting to open window when a window already exists! (Window.cpp)", LogLevel::Error);

            return nullptr;

        }
#endif

        s_window = new Window();

        return s_window;

    }

    void Bb::Window::CloseWindow()
    {

        delete s_window;

    }

}