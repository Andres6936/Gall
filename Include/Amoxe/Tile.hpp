// Design by Joan Andrés.

#ifndef GALL_TILE_HPP
#define GALL_TILE_HPP

#include <cstdint>

namespace Amoxe
{

	/**
	 * Range between [0, 255] and Domain natural numbers.
	 */
	using UInt8 = std::uint8_t;

	/**
	 * Range between [0, 4,294,967,296] and Domain natural numbers.
	 */
	using UInt32 = std::uint32_t;

	//This struct matches the order and width of data in .xp tiles.
	struct Tile
	{
		//I don't know why a CP437 character should be 4 bytes wide, but thus sprach the manual.
		UInt32 character;
		UInt8 fore_red;
		UInt8 fore_green;
		UInt8 fore_blue;
		UInt8 back_red;
		UInt8 back_green;
		UInt8 back_blue;
	};
}

#endif //GALL_TILE_HPP
