// Design by Joan Andrés.

#ifndef GALL_COMPRESSABLEWRITEEXCEPTION_HPP
#define GALL_COMPRESSABLEWRITEEXCEPTION_HPP

#include "Amoxe/Exception/GenericException.hpp"

namespace Amoxe
{
	class CompressableWriteException : public GenericException
	{
	public:

		CompressableWriteException() : GenericException("CompressableWriteException") { }
	};
}

#endif //GALL_COMPRESSABLEWRITEEXCEPTION_HPP
