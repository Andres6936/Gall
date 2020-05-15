#pragma once

#include <png.h>

#include <tuple>
#include <vector>
#include <string>
#include <string_view>

class PNG final
{

private:

	std::vector<unsigned char> data;

	int width = 0;
	int height = 0;
	int depth = 0;
	int color_type = 0;
	png_size_t cols = 0;

public:

	PNG() noexcept = default;

	/**
	 * The result of function determine if the image
	 * has been loaded correctly.
	 *
	 * @param file Filename of file with extension .png
	 * @return True if the file is correctly loaded.
	 */
	[[nodiscard]] bool load(std::string_view file);

	const std::vector<unsigned char>& getData() const
	{
		return data;
	}

	int getWidth() const
	{
		return width;
	}

	int getHeight() const
	{
		return height;
	}

	int getDepth() const
	{
		return depth;
	}

	int getColorType() const
	{
		return color_type;
	}

	std::tuple<uint8_t, uint8_t, uint8_t, uint8_t> getPixelAt(const int& x, const int& y);
};
