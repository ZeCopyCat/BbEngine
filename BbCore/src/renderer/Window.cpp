#include "Window.h"

#include <SFML/Window/Event.hpp>
#include "../io/SettingsReader.h"
#include "../core/Log.h"
#include "Buffers.h"

namespace Bb {
    
    Window* Window::s_window = nullptr;

    Window::Window() : m_resolution(SettingsReader::GetResolution()),
        m_renderWindow(sf::VideoMode(SettingsReader::GetResolution().x, SettingsReader::GetResolution().y), "BbEngine", sf::Style::Default)
    {

    }

    Window::~Window()
    {

    }

    Window* Bb::Window::OpenWindow()
    {

#ifdef _DEBUG
        if (s_window) {

            LOG_ERROR("Attempting to open window when a window already exists! (Window.cpp)");

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

    bool Window::PollEvents(sf::Event& event)
    { 

        bool output = s_window->m_renderWindow.pollEvent(event);

        if (event.type == sf::Event::Resized)
            s_window->FixLetterboxing();

        return output;

    }

    void Window::RenderVisibleBuffer()
    {

        s_window->m_renderWindow.clear();
        s_window->m_renderWindow.draw(BufferManager::GetBuffer(0).GetRectangleShape());
        s_window->m_renderWindow.display();

    }

    void Window::FixLetterboxing()
    {

        sf::RenderWindow& window = s_window->m_renderWindow;

        sf::View newView = window.getView();

        //First, we get the aspect ratios.
        float determinedAspectRatio = (float)s_window->m_resolution.x / (float)s_window->m_resolution.y;
        float currentAspectRatio = (float)window.getSize().x / (float)window.getSize().y;

        //Then check for if the bars appear on the sides or on top
        bool horizontalSpacing = true;
        if (determinedAspectRatio > currentAspectRatio)
            horizontalSpacing = false;

        sf::FloatRect newViewport(0, 0, 1, 1);

        //Bars on left and right
        if (horizontalSpacing) {
            newViewport.width = determinedAspectRatio / currentAspectRatio;
            newViewport.left = (1 - newViewport.width) / 2.f;
        }
        else {
            newViewport.height = currentAspectRatio / determinedAspectRatio;
            newViewport.top = (1 - newViewport.height) / 2.f;
        }

        newView.setViewport(newViewport);

        window.setView(newView);

    }

    void Window::SetResolution(Vector2u resolution)
    {

        // Set the resolutions
        s_window->m_resolution = resolution;
        BufferManager::SetBufferResolution(0, Vector2u(resolution.x, resolution.y));
        BufferManager::SetBufferResolution(1, Vector2u(resolution.x, resolution.y));
        BufferManager::SetBufferResolution(2, Vector2u(resolution.x, resolution.y));

        // Fix the view of the window
        sf::View newView = s_window->m_renderWindow.getView();

        newView.setSize(sf::Vector2f((float)resolution.x, (float)resolution.y));
        newView.setCenter(sf::Vector2f(resolution.x / 2.f, resolution.y / 2.f));

        s_window->m_renderWindow.setView(newView);

        // Letterbox the final product
        s_window->FixLetterboxing();

    }

    void Window::SetResolution(unsigned int width, unsigned int height)
    {

        SetResolution(Vector2u(width, height));

    }

}