// Design by Joan Andrés.

#ifndef GALL_LAYER_HPP
#define GALL_LAYER_HPP

#include <vector>

#include "Tile.hpp"

namespace xp
{
	class RexLayer
	{

	public:

		std::vector<RexTile> tiles;

		RexLayer() = default;

		RexLayer(int width, int height);
	};
}

#endif //GALL_LAYER_HPP
