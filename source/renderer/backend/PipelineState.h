/* Copyright (C) 2022 Wildfire Games.
 * This file is part of 0 A.D.
 *
 * 0 A.D. is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * 0 A.D. is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with 0 A.D.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef INCLUDED_RENDERER_BACKEND_PIPELINESTATE
#define INCLUDED_RENDERER_BACKEND_PIPELINESTATE

#include "graphics/Color.h"

class CStr;

namespace Renderer
{

namespace Backend
{

enum class CompareOp
{
	// Never passes the comparison.
	NEVER,
	// Passes if the source value is less than the destination value.
	LESS,
	// Passes if the source depth value is equal to the destination value.
	EQUAL,
	// Passes if the source depth value is less than or equal to the destination value.
	LESS_OR_EQUAL,
	// Passes if the source depth value is greater than the destination value.
	GREATER,
	// Passes if the source depth value is not equal to the destination value.
	NOT_EQUAL,
	// Passes if the source depth value is greater than or equal to the destination value.
	GREATER_OR_EQUAL,
	// Always passes the comparison.
	ALWAYS
};

struct DepthStencilStateDesc
{
	CompareOp depthCompareOp;
	bool depthWriteEnabled;
};

// TODO: add per constant description.

enum class BlendFactor
{
	ZERO,
	ONE,
	SRC_COLOR,
	ONE_MINUS_SRC_COLOR,
	DST_COLOR,
	ONE_MINUS_DST_COLOR,
	SRC_ALPHA,
	ONE_MINUS_SRC_ALPHA,
	DST_ALPHA,
	ONE_MINUS_DST_ALPHA,
	CONSTANT_COLOR,
	ONE_MINUS_CONSTANT_COLOR,
	CONSTANT_ALPHA,
	ONE_MINUS_CONSTANT_ALPHA,
	SRC_ALPHA_SATURATE,
	SRC1_COLOR,
	ONE_MINUS_SRC1_COLOR,
	SRC1_ALPHA,
	ONE_MINUS_SRC1_ALPHA,
};

enum class BlendOp
{
	ADD,
	SUBTRACT,
	REVERSE_SUBTRACT,
	MIN,
	MAX
};

// Using a namespace instead of a enum allows using the same syntax while
// avoiding adding operator overrides and additional checks on casts.
namespace ColorWriteMask
{
constexpr uint8_t RED = 0x01;
constexpr uint8_t GREEN = 0x02;
constexpr uint8_t BLUE = 0x04;
constexpr uint8_t ALPHA = 0x08;
} // namespace ColorWriteMask

struct BlendStateDesc
{
	bool enabled;
	BlendFactor srcColorBlendFactor;
	BlendFactor dstColorBlendFactor;
	BlendOp colorBlendOp;
	BlendFactor srcAlphaBlendFactor;
	BlendFactor dstAlphaBlendFactor;
	BlendOp alphaBlendOp;
	CColor constant;
	uint8_t colorWriteMask;
};

enum class CullMode
{
	NONE,
	FRONT,
	BACK
};

enum class FrontFace
{
	COUNTER_CLOCKWISE,
	CLOCKWISE
};

struct RasterizationStateDesc
{
	CullMode cullMode;
	FrontFace frontFace;
};

// TODO: Add a shader program to the graphics pipeline state.
struct GraphicsPipelineStateDesc
{
	DepthStencilStateDesc depthStencilState;
	BlendStateDesc blendState;
	RasterizationStateDesc rasterizationState;
};

// We don't provide additional helpers intentionally because all custom states
// should be described with a related shader and should be switched together.
GraphicsPipelineStateDesc MakeDefaultGraphicsPipelineStateDesc();

CompareOp ParseCompareOp(const CStr& str);

BlendFactor ParseBlendFactor(const CStr& str);
BlendOp ParseBlendOp(const CStr& str);

CullMode ParseCullMode(const CStr& str);
FrontFace ParseFrontFace(const CStr& str);

} // namespace Backend

} // namespace Renderer

#endif // INCLUDED_RENDERER_BACKEND_PIPELINESTATE
