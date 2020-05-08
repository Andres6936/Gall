// Design by Joan Andrés.

#ifndef GALL_DECOMPRESSABLEWRITEEXCEPTION_HPP
#define GALL_DECOMPRESSABLEWRITEEXCEPTION_HPP

#include "Amoxe/Exception/Exception.hpp"

namespace Amoxe
{
	class DecompressableWriteException : public Exception
	{
	public:

		DecompressableWriteException() : Exception("DecompressableWriteException") { }

	};
}

#endif //GALL_DECOMPRESSABLEWRITEEXCEPTION_HPP
