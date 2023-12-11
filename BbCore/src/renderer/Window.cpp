#include "Window.h"

#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp> //D
#include "../core/Log.h"
#include "../io/SettingsReader.h"
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

        sf::RectangleShape rect(sf::Vector2f(3000.f, 3000.f));
        rect.setPosition(00.f, 00.f);
        rect.setFillColor(sf::Color(52, 52, 56));
        s_window->m_renderWindow.draw(rect);
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

        s_window->m_resolution = resolution;
        s_window->FixLetterboxing();

    }

    void Window::SetResolution(unsigned int width, unsigned int height)
    {

        SetResolution(Vector2u(width, height));

    }

}