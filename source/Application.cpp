// Copyright (C) 2013 Jimmie Bergmann - jimmiebergmann@gmail.com
//
// This software is provided 'as-is', without any express or
// implied warranty. In no event will the authors be held
// liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute
// it freely, subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but
//    is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any
//    source distribution.
// ///////////////////////////////////////////////////////////////////////////

#include <Application.hpp>
#include <iostream>
#include <Bit/System/MemoryLeak.hpp>

namespace Game
{

	Application::Application() :
		m_pRenderWindow( NULL ),
		m_pRenderer(NULL),
		m_pSpace( NULL )
	{
	}

	int Application::Run(const int p_Argc, char ** p_Argv)
	{
		// Load the application
		if (!Load(p_Argc, p_Argv))
		{
			std::cout << "Can't load the application." << std::endl;
			Unload();
			return 0;
		}

		// Run the applicaiton while the window is open.
		while (m_pRenderWindow->IsOpen())
		{
			// Update the window
			m_pRenderWindow->Update();

			// Check the window events.
			Bit::Event e;
			while (m_pRenderWindow->PollEvent(e))
			{
				HandleInputs(e);
			}

			// Render to the applications window.
			Render();
		}


		// Unload the application
		if (!Unload())
		{
			std::cout << "Could not unload the application." << std::endl;
		}

		// Exit the applicaiton.
		return 0;
	}

	Bit::Bool Application::Load(const int p_Argc, char ** p_Argv)
	{
		// Window properties
		const Bit::Vector2u32 windowSize(800, 600);
		const Bit::Uint32 depth = 32;

		// Create the window mode.
		Bit::VideoMode videoMode(windowSize, depth);

		// Create the render window.
		m_pRenderWindow = new Bit::RenderWindow(videoMode, "Space game");

		if (!m_pRenderWindow->IsOpen())
		{
			std::cout << "Could not create the window." << std::endl;
			return false;
		}

		// Create the graphic device
		m_pRenderer = new Renderer(*m_pRenderWindow, Bit::Version(3, 1));
		if (!m_pRenderer->IsOpen())
		{
			std::cout << "Could not create the graphic device." << std::endl;
			return false;
		}
		
		// Set clear color
		m_pRenderer->SetClearColor(0, 0, 0, 255);

		// Create the space
		m_pSpace = new Space;

		// Succeeded.
		return true;
	}

	Bit::Bool Application::Unload()
	{
		// Unload the graphic device
		if (m_pRenderer)
		{
			delete m_pRenderer;
			m_pRenderer = NULL;
		}

		// Unload the render window
		if (m_pRenderWindow)
		{
			delete m_pRenderWindow;
			m_pRenderWindow = NULL;
		}

		// Unload the space
		if (m_pSpace)
		{
			delete m_pSpace;
			m_pSpace = NULL;
		}

		// Clear the input controllers
		m_InputControllers.clear();

		// Unload succeeded.
		return true;
	}

	void Application::Render()
	{
		// Render the space.
		m_pRenderer->Render(*m_pSpace);

		// Swap the buffers.
		m_pRenderer->Present();
	}

	void Application::HandleInputs(const Bit::Event & p_Event)
	{
		switch (p_Event.Type)
		{
			// Closed the window
			case Bit::Event::Closed:
				m_pRenderWindow->Close();
				break;

			// Mouse inputs.
			case Bit::Event::MouseJustPressed:
				CallAllInputControllers(p_Event);
				break;
			case Bit::Event::MouseJustReleased:
				CallAllInputControllers(p_Event);
				break;
			case Bit::Event::MouseMoved:
				CallAllInputControllers(p_Event);
				break;
			case Bit::Event::MousePressed:
				CallAllInputControllers(p_Event);
				break;

			// Key inputs.
			case Bit::Event::KeyJustPressed:
				CallAllInputControllers(p_Event);
				break;
			case Bit::Event::KeyJustReleased:
				CallAllInputControllers(p_Event);
				break;
			case Bit::Event::KeyPressed:
				CallAllInputControllers(p_Event);
				break;
			default:
				break;
		}
	}

	void Application::CallAllInputControllers(const Bit::Event & p_Event)
	{
		for (InputControllerVector::size_type i = 0; i < m_InputControllers.size(); i++)
		{
			m_InputControllers[i]->InputEvent(p_Event);
		}
	}

}