#pragma once

#include "stdafx.h"

namespace Dive9
{
	class Scene
	{
	public:
		Scene();
		virtual ~Scene();

		virtual void	Update(float time);
	};
}