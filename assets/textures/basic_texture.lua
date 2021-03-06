-- Pegasus Engine
-- 2017 - Benjamin Carter (bencarterdev@outlook.com)
--
-- This software is provided 'as-is', without any express or implied warranty.
-- In no event will the authors be held liable for any damages arising from the use of this software.
--
-- Permission is granted to anyone to use this software for any purpose,
-- including commercial applications, and to alter it and redistribute it freely,
-- subject to the following restrictions:
--
-- 1. The origin of this software must not be misrepresented;
--    you must not claim that you wrote the original software.
--    If you use this software in a product, an acknowledgement
--    in the product documentation would be appreciated but is not required.
--
-- 2. Altered source versions must be plainly marked as such,
--    and must not be misrepresented as being the original software.
--
-- 3. This notice may not be removed or altered from any source distribution.

-- An example of a serialized texture.
Texture = {
    -- The name of the texture object. Used for debugging purposes.
    name = "Basic Texture",
    -- The type of texture to create.
    texture_type = TextureType.Texture2D,
    -- The file location of the image to use.
    source = "data/textures/image.png",
    -- How the texture will apply to the current bound buffer.
    wrap_mode = WrapType.Clamp,
    -- How the pixels will behave on the bound buffer.
    filter = FilterType.Nearest
}