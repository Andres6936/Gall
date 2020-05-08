// Design by Joan Andrés.

#ifndef GALL_COMPRESSIBLE_HPP
#define GALL_COMPRESSIBLE_HPP

#include <zlib.h>

#include "Exception/DecompressableWriteException.hpp"

namespace Amoxe
{
	class Decompressable
	{
	public:

		static void read(gzFile gz, void * buffer, const unsigned int length)
		{
			if (gzread(gz, buffer, length) > 0) return;

			// We expect to read past
			// the end of the file
			// after the last layer.
			if (gzeof(gz)) return;

			throw DecompressableWriteException();
		}

		static void read(gzFile gz, void * buffer)
		{
			read(gz, buffer, sizeof(buffer));
		}

		template <typename Object>
		static void read(gzFile g, Object& object, unsigned int length)
		{
			read(g, reinterpret_cast<void *>(&object), length);
		}
	};
}

#endif //GALL_COMPRESSIBLE_HPP
