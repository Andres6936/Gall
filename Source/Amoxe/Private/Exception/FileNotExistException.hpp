// Design by Joan Andrés.

#ifndef GALL_FILENOTEXISTEXCEPTION_HPP
#define GALL_FILENOTEXISTEXCEPTION_HPP

#include "Amoxe/Exception/Exception.hpp"

namespace Amoxe
{
	class FileNotExistException : public Exception
	{
	public:

		explicit FileNotExistException(std::string&& _message) : Exception(std::move(_message)) {};
	};
}

#endif //GALL_FILENOTEXISTEXCEPTION_HPP
