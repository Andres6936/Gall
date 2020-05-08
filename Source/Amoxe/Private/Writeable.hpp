// Design by Joan Andrés.

#ifndef GALL_WRITEABLE_HPP
#define GALL_WRITEABLE_HPP

#include <zlib.h>
#include <string>

namespace Amoxe
{
	class Writable
	{
	public:

		static gzFile writeFile(const std::string& filename);
	};
}

#endif //GALL_WRITEABLE_HPP
