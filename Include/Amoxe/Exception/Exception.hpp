// Design by Joan Andrés.

#ifndef GALL_EXCEPTION_HPP
#define GALL_EXCEPTION_HPP

namespace Amoxe
{

	//Custom exception class, mostly for zlib errors. Custom exception codes follow.
	//This is needlessly verbose because I don't want to reference gzFiles
	//in this header. Then users would have to include zlib.h.
	class Exception : public std::exception
	{
	private:

		const std::string message;

	public:

		explicit Exception(std::string&& msg) : message(msg) { }

		const char* what() const noexcept override
		{
			return message.data();
		}
	};
}

#endif //GALL_EXCEPTION_HPP
