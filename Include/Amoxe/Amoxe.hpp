/*For version 1.02 of REXPaint*/
#pragma once

#include <iostream>
#include <stdint.h>
#include <array>
#include <vector>

#include "Tile.hpp"
#include "Layer.hpp"

namespace xp
{
	//REXpaint identifies transparent tiles by setting their background color to 255,0,255.
	//You may want to check this for each tile before drawing or converting a RexFile.
	//(By default, no tile in the first layer is transaprent).
	inline bool isTransparent(RexTile* tile);

	//Returns a transparent tile.
	constexpr RexTile transparentTile()
	{
		return RexTile{ 0, 0, 0, 0, 255, 0, 255 };
	}

	class RexImage
	{

	private:

		//Image properties
		int version = -1;
		int width = 0;
		int height = 0;
		int num_layers = 0;

		//layers[0] is the first layer.
		std::vector<RexLayer> layers;

	public:
		//Load an .xp file into a new RexFile.
		//Note: May throw a const char* error message and set errno.
		//Both the error message and the value of errno may be as gzopen or gzread set them.
		//It may also throw an error with code REXSPEEDER_FILE_DOES_NOT_EXIST.
		//Will not throw an error if the file specified by `filename` is not zlib compressed.
		RexImage(std::string const& filename);

		//Save this RexFile into a valid .xp file that RexPaint can load (if the ".xp" suffix is present).
		//Note: May throw a const char* error message and set errno.
		//Both the error message and the value of errno may be as gzopen or gzwrite set them.
		void save(std::string const& filename);

		//Create a blank RexFile with the specified attributes.
		//Layers above the first will be made of transparent tiles.
		RexImage(int _version, int _width, int _height, int _num_layers);

		//Image attributes
		inline int getVersion()
		{
			return version;
		};

		inline int getWidth()
		{
			return width;
		};

		inline int getHeight()
		{
			return height;
		};

		inline int getNumLayers()
		{
			return num_layers;
		};

		//Returns a pointer to a single tile specified by layer, x coordinate, y coordinate.
		//0,0 is the top-left corner.
		inline RexTile* getTile(int layer, int x, int y)
		{
			return &layers[layer].tiles[y + (x * height)];
		};

		//Returns a pointer to a single tile specified by layer and the actual index into the array.
		//Useful for iterating through a whole layer in one go for coordinate-nonspecific tasks.
		inline RexTile* getTile(int layer, int index)
		{
			return &layers[layer].tiles[index];
		};

		//Replaces the data for a tile. Not super necessary, but might save you a couple lines.
		inline void setTile(int layer, int x, int y, RexTile val)
		{
			*getTile(layer, x, y) = val;
		};

		//Replaces the data for a tile. Not super necessary, but might save you a couple lines.
		inline void setTile(int layer, int i, RexTile& val)
		{
			*getTile(layer, i) = val;
		};

		//Combines all the layers of the image into one layer.
		//Respects transparency.
		void flatten();
	};

	//Custom exception class, mostly for zlib errors. Custom exception codes follow.
	//This is needlessly verbose because I don't want to reference gzFiles
	//in this header. Then users would have to include zlib.h.
	class Rexception : public std::exception
	{
	public:
		Rexception(std::string msg, int errcode) : err(msg), code(errcode)
		{
		}

		~Rexception()
		{
		}

		virtual const char* what() const throw()
		{
			return err.c_str();
		}

		int code;
	private:
		std::string err;
	};

	//The error code thrown when a file does not exist. Strangely, gzopen does not set an error code.
	constexpr int ERR_FILE_DOES_NOT_EXIST = 20202;
	//The error code thrown when a RexImage is found to not have a number of layers i, 1 <= i <= 4.
	constexpr int ERR_INVALID_NUMBER_OF_LAYERS = 20203;
}
