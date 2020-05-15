#include <iostream>
#include <string>

#include "Gall/Gall.hpp"
#include "Loader/PNG.hpp"
#include "Amoxe/Image.hpp"

using namespace Amoxe;

void Gall::convert(std::string_view pathPng)
{
	const int REX_VERSION = -1;

	PNG png;

	if (png.load(pathPng))
	{
		const int width = png.getWidth();
		const int height = png.getHeight();
		std::cout << "Original image is " << width << "x" << height << " pixels\n";

		Image rex{ REX_VERSION, width, height, 1 };
		for (int y = 0; y < height; ++y)
		{
			for (int x = 0; x < width; ++x)
			{
				uint8_t r, g, b, a;
				std::tie(r, g, b, a) = png.getPixelAt(x, (height - 1) - y);
				if (a == 0)
				{
					rex.setTile(0, x, y, Tile{ 0, 0, 0, 0, 255, 0, 255 });
				}
				else if (a == 255)
				{
					rex.setTile(0, x, y, Tile{ 219, r, g, b, 0, 0, 0 });
				}
				else
				{
					float percent = (float)a / 255.0F;
					if (percent < 0.25F)
					{
						rex.setTile(0, x, y, Tile{ 176, r, g, b, 0, 0, 0 });
					}
					else if (percent < 0.5F)
					{
						rex.setTile(0, x, y, Tile{ 177, r, g, b, 0, 0, 0 });
					}
					else if (percent < 0.75F)
					{
						rex.setTile(0, x, y, Tile{ 178, r, g, b, 0, 0, 0 });
					}
					else
					{
						rex.setTile(0, x, y, Tile{ 219, r, g, b, 0, 0, 0 });
					}
				}
			}
		}
		rex.flatten();

		// Save the file with the same name of input,
		// but extension .xp
		rex.save(std::string(pathPng) + ".xp");

		std::cout << "Done\n";
	}
	else
	{
		std::cerr << "Error load the image.\n";
	}
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		std::cerr << "Gall usage: ./Gall <pngfile>\n";
		return 1;
	}

	Gall::convert(std::string(argv[1]));
}