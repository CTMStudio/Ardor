#pragma once

#include "RenderCommon.h"

namespace Ardor
{
	class VertexBuffer
	{
	public:
		virtual ~VertexBuffer() {}

		uint32_t virtual GetVertexCount() = 0;
	};
}

