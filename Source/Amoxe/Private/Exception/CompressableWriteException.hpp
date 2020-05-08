// Design by Joan Andrés.

#ifndef GALL_COMPRESSABLEWRITEEXCEPTION_HPP
#define GALL_COMPRESSABLEWRITEEXCEPTION_HPP

#include "Amoxe/Exception/Exception.hpp"

namespace Amoxe
{
	class CompressableWriteException : public Exception
	{
	public:

		CompressableWriteException() : Exception("CompressableWriteException") { }
	};
}

#endif //GALL_COMPRESSABLEWRITEEXCEPTION_HPP
