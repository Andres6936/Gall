// Design by Joan Andrés.

#ifndef GALL_LAYER_HPP
#define GALL_LAYER_HPP

#include <vector>

#include "Tile.hpp"

namespace Amoxe
{
	using VectorTiles = std::vector<Tile>;

	class Layer final : public VectorTiles { };
}

#endif //GALL_LAYER_HPP
