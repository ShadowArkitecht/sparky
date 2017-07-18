/*
* Pegasus Engine
* 2017 - Benjamin Carter (bencarterdev@outlook.com)
*
* This software is provided 'as-is', without any express or implied warranty.
* In no event will the authors be held liable for any damages arising from the use of this software.
*
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it freely,
* subject to the following restrictions:
*
* 1. The origin of this software must not be misrepresented;
*    you must not claim that you wrote the original software.
*    If you use this software in a product, an acknowledgement
*    in the product documentation would be appreciated but is not required.
*
* 2. Altered source versions must be plainly marked as such,
*    and must not be misrepresented as being the original software.
*
* 3. This notice may not be removed or altered from any source distribution.
*/

#ifndef _PEGASUS_BUFFER_DESCRIPTION_HPP_
#define _PEGASUS_BUFFER_DESCRIPTION_HPP_

//====================
// Library includes
//====================
#include <GL/glew.h> // Defining openGL flags.

namespace pegasus
{
	//====================
	// Enumerations
	//====================
	enum class eBufferType
	{
		/** A buffer that will be constructed as a vertex buffer. */
		VERTEX = GL_ARRAY_BUFFER
	};

	enum class eDrawType
	{
		/** The vertices will be drawn as static (the data will not change). */
		STATIC = GL_STATIC_DRAW,
		/** The vertices will be drawn as dynamic (data is likely to change i.e. sprite batch. */
		DYNAMIC = GL_DYNAMIC_DRAW
	};

	//====================
	// Structures
	//====================
	struct BufferDescription
	{
		/** The type of buffer that is to be bound. */
		eBufferType bufferType;
		/** Whether the drawing command will be static or dynamic. */
		eDrawType drawType;
		/** The size of the data being described. */
		GLuint stride;
		/** The total amount of data to populate the buffer with. */
		GLuint size;
		/** A reference to the data itself being added to the buffer.*/
		void* pData;
	};

} // namespace pegasus

#endif//_PEGASUS_BUFFER_DESCRIPTION_HPP_
