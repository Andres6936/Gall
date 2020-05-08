// Design by Joan Andrés.

#ifndef GALL_READABLE_HPP
#define GALL_READABLE_HPP

#include <zlib.h>
#include <string>

namespace Amoxe
{
	class Readable
	{
	public:

		static gzFile readFile(const std::string& filename);
	};
}

#endif //GALL_READABLE_HPP
