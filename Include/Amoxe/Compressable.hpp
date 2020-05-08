// Design by Joan Andrés.

#ifndef GALL_UNPACKABLE_HPP
#define GALL_UNPACKABLE_HPP

#include <zlib.h>

namespace Amoxe
{
	class Compressable
	{
	public:

		static void write(gzFile gz, voidp buf, const unsigned int length)
		{
			if (gzwrite(gz, buf, length) > 0) return;

			throw "DecompressableWriteExcption";
		}

		template <typename Object>
		static void write(gzFile g, Object& buf, unsigned int length)
		{
			write(g,  reinterpret_cast<void *>(&buf), length);
		}
	};
}

#endif //GALL_UNPACKABLE_HPP
