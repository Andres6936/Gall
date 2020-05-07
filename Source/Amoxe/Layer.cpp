// Design by Joan Andrés.

#include "Amoxe/Layer.hpp"

using namespace xp;

RexLayer::RexLayer(int width, int height)
{
	tiles.resize(width * height);
}

RexLayer::~RexLayer()
{
	tiles.clear();
}
