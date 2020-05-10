#include "Loader/PNG.hpp"

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>

void readFileCallback(png_structp png_ptr, png_bytep out, png_size_t count);

bool PNG::load(std::string_view file)
{
	png_structp png_ptr;
	png_infop info_ptr;

	std::ifstream ifile(file.data(), std::ios::binary);

	if (not ifile.is_open()) return false;

	char magicNumber[8];

	ifile.read(&magicNumber[0], 8 * sizeof(char));

	if (!png_check_sig(reinterpret_cast<png_bytep>(magicNumber), 8))
	{
		return false;
	}

	png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, 0, 0, 0);

	if (png_ptr == 0)
	{
		return false;
	}

	info_ptr = png_create_info_struct(png_ptr);

	if (info_ptr == 0)
	{
		png_destroy_read_struct(&png_ptr, 0, 0);
		return false;
	}

	png_set_read_fn(png_ptr, (void*)&ifile, readFileCallback);

	png_set_sig_bytes(png_ptr, 8);

	png_read_info(png_ptr, info_ptr);

	png_get_IHDR(png_ptr, info_ptr, (png_uint_32*)&width, (png_uint_32*)&height,
			&depth, &color_type, 0, 0, 0);

	cols = png_get_rowbytes(png_ptr, info_ptr);

	png_bytepp row_pp = new png_bytep[height];

	// We avoid clear the vector (performance) and resize for overwrite
	data.resize(cols * height);

	for (int i = 0; i < height; ++i)
	{
		row_pp[height - i - 1] = (png_bytep)&data[i * cols];
	}

	png_read_image(png_ptr, row_pp);
	png_read_end(png_ptr, info_ptr);

	png_destroy_read_struct(&png_ptr, &info_ptr, 0);

	delete[] row_pp;
	return true;
}

void readFileCallback(png_structp png_ptr, png_bytep out, png_size_t count)
{
	png_voidp io_ptr = png_get_io_ptr(png_ptr);

	if (io_ptr == 0)
	{
		return;
	}

	std::ifstream& ifs = *(std::ifstream*)io_ptr;

	ifs.read((char*)out, count);
}

std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> PNG::getPixelAt(const int& x, const int& y)
{
	const int idx = (y * cols) + (x * 4);

	const uint8_t red = data[idx];
	const uint8_t green = data[idx + 1];
	const uint8_t blue = data[idx + 2];
	const uint8_t alpha = data[idx + 3];

	return std::make_tuple(red, green, blue, alpha);
}
