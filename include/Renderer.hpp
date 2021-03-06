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
#include <Bit/Graphics/OpenGL/OpenGLGraphicDevice.hpp>
#include <Renderable.hpp>

namespace Game
{

	////////////////////////////////////////////////////////////////
	/// \brief Renderer class.
	///
	////////////////////////////////////////////////////////////////
	class BIT_API Renderer : public Bit::OpenGLGraphicDevice
	{

	public:

		////////////////////////////////////////////////////////////////
		/// \brief Constructor.
		///
		/// \param p_RenderOutput The output window.
		/// \param p_Version The version of the graphic device context
		///		that you would like to open.
		///		Using the newest as possible by default.
		///
		////////////////////////////////////////////////////////////////
		Renderer(	const Bit::RenderWindow & p_RenderOutput,
					const Bit::Version & p_Version = Bit::Version::Default);

		////////////////////////////////////////////////////////////////
		/// \brief Render 
		///
		////////////////////////////////////////////////////////////////
		void Render(const Renderable & p_Renderable);

	};

}