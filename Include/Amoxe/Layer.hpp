// Design by Joan Andrés.

#ifndef GALL_LAYER_HPP
#define GALL_LAYER_HPP

#include <vector>

#include "Tile.hpp"

namespace xp
{
	struct RexLayer
	{
		std::vector<RexTile> tiles;

		RexLayer(int width, int height);

		RexLayer()
		{
		}

		~RexLayer();
	};
}

#endif //GALL_LAYER_HPP
