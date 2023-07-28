/* Copyright (C) 2022 Wildfire Games.
 * This file is part of 0 A.D.
 *
 * 0 A.D. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * 0 A.D. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 0 A.D.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDED_RENDERER_BACKEND_GL_DEVICEFORWARD
#define INCLUDED_RENDERER_BACKEND_GL_DEVICEFORWARD

#include <memory>

typedef struct SDL_Window SDL_Window;

namespace Renderer
{

namespace Backend
{

class IDevice;

namespace GL
{

class CDevice;

std::unique_ptr<IDevice> CreateDevice(SDL_Window* window, const bool arb);

} // namespace GL

} // namespace Backend

} // namespace Renderer

#endif // INCLUDED_RENDERER_BACKEND_GL_DEVICEFORWARD
