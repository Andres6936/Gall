// Design by Joan Andrés.

#ifndef GALL_GENERICEXCEPTION_HPP
#define GALL_GENERICEXCEPTION_HPP

namespace Amoxe
{

	//Custom exception class, mostly for zlib errors. Custom exception codes follow.
	//This is needlessly verbose because I don't want to reference gzFiles
	//in this header. Then users would have to include zlib.h.
	class GenericException : public std::exception
	{
	private:

		const std::string message;

	public:

		explicit GenericException(std::string&& msg) : message(msg) { }

		const char* what() const noexcept override
		{
			return message.data();
		}
	};
}

#endif //GALL_GENERICEXCEPTION_HPP
