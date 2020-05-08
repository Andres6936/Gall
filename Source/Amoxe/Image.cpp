#include "Amoxe/Image.hpp"
#include "Amoxe/Exception/Exception.hpp"

#include "Private/Compressable.hpp"
#include "Private/Decompressable.hpp"

#include <zlib.h>

//===========================================================================================================//
//    Safe I/O (where "safe" means "will throw errors")                                                      //
//                                                                                                           //
//   These functions will throw an error message from gzerror, and set errno to the error code.              //
//===========================================================================================================//

using namespace Amoxe;

static gzFile s_gzopen(const std::string& filename, const char* permissions)
{
	static_assert(ZLIB_VERNUM >= 0x1280,
			"Version of ZLib is very old, please update your version of ZLib");

	gzFile g = gzopen(filename.c_str(), permissions);

	if (g != Z_NULL)
		return g;

	int err = 0;
	const char* errstr = gzerror(g, &err);
	if (err == 0)
	{
		// Assume the file simply didn't exist.
		throw Exception("File " + filename + " does not exist.");
	}

	throw Exception(errstr);
}


namespace Amoxe
{

//===========================================================================================================//
//    Loading an xp file                                                                                     //
//===========================================================================================================//
	Image::Image(std::string const& filename)
	{
		typedef void* vp;
		//Number of bytes in a tile. Not equal to sizeof(RexTile) due to padding.
		const int tileLen = 10;

		gzFile gz;
		try
		{
			gz = s_gzopen(filename, "rb");

			Decompressable::read(gz, &version);
			Decompressable::read(gz, &num_layers);
			Decompressable::read(gz, &width);
			Decompressable::read(gz, &height);

			layers.resize(num_layers);

			for (int i = 0; i < num_layers; i++)
			{
				layers[i].resize(width * height);
			}

			for (int layer_index = 0; layer_index < num_layers; layer_index++)
			{
				for (int i = 0; i < width * height; ++i)
					Decompressable::read(gz, getTile(layer_index, i), tileLen);

				//The layer and height information is repeated.
				//This is expected to read off the end after the last layer.
				Decompressable::read(gz, &width);
				Decompressable::read(gz, &height);
			}
		}
		catch (...)
		{ throw; }

		gzclose(gz);
	}

//===========================================================================================================//
//    Saving an xp file                                                                                      //
//===========================================================================================================//
	void Image::save(std::string const& filename)
	{
		typedef void* vp;
		//Number of bytes in a tile. Not equal to sizeof(RexTile) due to padding.
		const int tileLen = 10;

		try
		{
			gzFile gz = s_gzopen(filename, "wb");

			Compressable::write(gz, &version, sizeof(version));
			Compressable::write(gz, &num_layers, sizeof(num_layers));

			for (int layer = 0; layer < num_layers; ++layer)
			{
				Compressable::write(gz, &width, sizeof(width));
				Compressable::write(gz, &height, sizeof(height));

				for (int i = 0; i < width * height; ++i)
					//Note: not "sizeof(RexTile)" because of padding.
					Compressable::write(gz, getTile(layer, i), tileLen);

			}

			gzflush(gz, Z_FULL_FLUSH);
			gzclose(gz);
		}
		catch (...)
		{ throw; }
	}

//===========================================================================================================//
//    Constructors / Destructors                                                                             //
//===========================================================================================================//
	Image::Image(int _version, int _width, int _height, int _num_layers)
			: version(_version), width(_width), height(_height), num_layers(_num_layers)
	{
		layers.resize(num_layers);

		//All layers above the first are set transparent.
		for (int l = 0; l < num_layers; l++)
		{
			layers[l].resize(width * height);
			for (int i = 0; i < width * height; ++i)
			{
				Tile t = transparentTile();
				setTile(l, i, t);
			}
		}
	}

//===========================================================================================================//
//    Utility Functions                                                                                      //
//===========================================================================================================//
	void Image::flatten()
	{
		if (num_layers == 1)
			return;

		//Paint the last layer onto the second-to-last
		for (int i = 0; i < width * height; ++i)
		{
			Tile overlay = getTile(num_layers - 1, i);

			if (!isTransparent(overlay))
			{
				getTile(num_layers - 2, i) = overlay;
			}
		}

		//Remove the last layer
		--num_layers;

		//Recurse
		flatten();
	}


	bool isTransparent(const Tile& tile)
	{
		//This might be faster than comparing with transparentTile(), despite it being a constexpr
		return tile.back_red == 255 and tile.back_green == 0 and tile.back_blue == 255;
	}
}
