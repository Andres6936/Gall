// Design by Joan Andrés.

#ifndef GALL_UNPACKABLE_HPP
#define GALL_UNPACKABLE_HPP

#include <zlib.h>

#include "Exception/CompressableWriteException.hpp"

namespace Amoxe
{
	class Compressable
	{
	public:

		static void write(gzFile gz, voidp buf, const unsigned int length)
		{
			if (gzwrite(gz, buf, length) > 0) return;

			throw CompressableWriteException();
		}

		template <typename Object>
		static void write(gzFile g, Object& buf, unsigned int length)
		{
			write(g,  reinterpret_cast<void *>(&buf), length);
		}
	};
}

#endif //GALL_UNPACKABLE_HPP
