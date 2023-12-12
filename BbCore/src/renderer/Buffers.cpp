#include "Buffers.h"

#include "Window.h"

namespace Bb {

	BufferManager* BufferManager::s_instance = nullptr;

	void BufferManager::Initialize()
	{

		s_instance = new BufferManager();

		SetBufferResolution(0, Window::GetResolution()); // Visible Buffer
		GetBuffer(0).CreateTexture(Window::GetResolution());
		SetBufferResolution(1, Window::GetResolution()); // World Buffer
		GetBuffer(1).CreateTexture(Window::GetResolution());
		SetBufferResolution(2, Window::GetResolution()); // UI Buffer
		GetBuffer(2).CreateTexture(Window::GetResolution());

	}

	void BufferManager::Shutdown()
	{

		delete s_instance;

	}

	void BufferManager::SetBufferResolution(unsigned int buffer, Vector2u resolution)
	{

		sf::Vector2f floatResolution((float)resolution.x, (float)resolution.y);

		s_instance->m_buffers[buffer].GetRectangleShape().setSize(floatResolution);
		s_instance->m_buffers[buffer].CreateTexture(resolution);

	}

	void Buffer::CreateTexture(Vector2u resolution)
	{

		m_texture.create(resolution.x, resolution.y);

	}

	void Buffer::Compile()
	{

		m_texture.display();
		m_shape.setTexture(&m_texture.getTexture(), true);

	}

	Buffer::Buffer()
	{

		m_shape.setTexture(&m_texture.getTexture(), true);

	}

}