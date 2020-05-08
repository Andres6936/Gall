// Design by Joan Andrés.

#ifndef GALL_FILENOTEXISTEXCEPTION_HPP
#define GALL_FILENOTEXISTEXCEPTION_HPP

#include "Amoxe/Exception/GenericException.hpp"

namespace Amoxe
{
	class FileNotExistException : public GenericException
	{
	public:

		explicit FileNotExistException(std::string&& _message) : GenericException(std::move(_message)) {};
	};
}

#endif //GALL_FILENOTEXISTEXCEPTION_HPP
