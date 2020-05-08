// Design by Joan Andrés.

#ifndef GALL_LAYER_HPP
#define GALL_LAYER_HPP

#include <vector>

#include "Tile.hpp"

namespace xp
{
	using VectorTiles = std::vector<Tile>;

	class Layer : public VectorTiles { };
}

#endif //GALL_LAYER_HPP
