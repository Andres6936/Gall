#pragma once

#include <string>
#include <png.h>
#include <tuple>

class PNG
{

private:

	char* data = nullptr;

	int width = 0;
	int height = 0;
	int depth = 0;
	int color_type = 0;
	png_size_t cols = 0;

public:

	PNG() noexcept = default;

	~PNG();

	bool load(std::string file);

	const char* getData() const
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
