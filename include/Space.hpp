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

#pragma once

#include <Bit/Build.hpp>
#include <Renderable.hpp>
#include <InputController.hpp>
#include <Planet.hpp>
#include <Player.hpp>

namespace Game
{

	////////////////////////////////////////////////////////////////
	/// \brief Space class
	///
	////////////////////////////////////////////////////////////////
	class BIT_API Space : public Renderable, InputController
	{

	public:

		////////////////////////////////////////////////////////////////
		/// \brief Render everything in space.
		///
		////////////////////////////////////////////////////////////////
		virtual void Render(Bit::GraphicDevice & p_GraphicDevice);

		////////////////////////////////////////////////////////////////
		/// \brief Handle inputs for everything in space.
		///
		////////////////////////////////////////////////////////////////
		virtual void InputEvent(const Bit::Event & p_Event);

	private:

		// Private variables
		Player		m_Player;

	};

}