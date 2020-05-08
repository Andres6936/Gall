// Design by Joan Andrés.

#ifndef GALL_DECOMPRESSABLEWRITEEXCEPTION_HPP
#define GALL_DECOMPRESSABLEWRITEEXCEPTION_HPP

#include "Amoxe/Exception/GenericException.hpp"

namespace Amoxe
{
	class DecompressableWriteException : public GenericException
	{
	public:

		DecompressableWriteException() : GenericException("DecompressableWriteException") { }

	};
}

#endif //GALL_DECOMPRESSABLEWRITEEXCEPTION_HPP
