// Design by Joan Andrés.

#ifndef GALL_EXCEPTION_HPP
#define GALL_EXCEPTION_HPP

namespace Amoxe
{

	//The error code thrown when a file does not exist. Strangely, gzopen does not set an error code.
	const int ERR_FILE_DOES_NOT_EXIST = 20202;
	//The error code thrown when a RexImage is found to not have a number of layers i, 1 <= i <= 4.
	const int ERR_INVALID_NUMBER_OF_LAYERS = 20203;

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
