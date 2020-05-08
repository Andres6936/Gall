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
	class Rexception : public std::exception
	{

	public:

		Rexception(const std::string& msg, int errcode) : err(msg), code(errcode)
		{
		}

		const char* what() const noexcept override
		{
			return err.c_str();
		}

		int code;
	private:
		std::string err;
	};
}

#endif //GALL_EXCEPTION_HPP
