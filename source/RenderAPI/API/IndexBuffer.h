#pragma once

#include "RenderCommon.h"

namespace Ardor
{
	class IndexBuffer
	{
	public:
		virtual ~IndexBuffer() {}

		virtual uint32_t GetIndexCount() = 0;
	};
}
