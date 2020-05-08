// Design by Joan Andrés.

#include "Private/Readable.hpp"

gzFile Amoxe::Readable::readFile(const std::string& filename)
{
	// I've tested this program in version of ZLib 1.2.8
	static_assert(ZLIB_VERNUM >= 0x1280,
			"Version of ZLib is very old, please update your version of ZLib");

	// The gzip format is different from the zlib format .gzip is a
	// gzip wrapper, documented in RFC 1952, wrapped around a
	// deflate stream.

	// Opens a gzip (.gz) file for reading or writing. The mode
	// parameter is as in fopen ("rb" or "wb") but can also
	// include a compression level ("wb9") or a strategy: 'f' for
	// filtered data as in "wb6f", 'h' for Huffman-only compression
	// as in "wb1h", 'R' for run-length encoding as in "wb1R", or
	// 'F' for fixed code compression as in "wb9F".

	// In we case, open a .xp file for reading or writing.

	// These functions, as well as gzip, will read and decode a
	// sequence of gzip streams in a file. The append function of
	// gzopen() can be used to create such a file. (Also see
	// gzflush() for another way to do this.) When appending,
	// gzopen does not test whether the file begins with a gzip
	// stream, nor does it look for the end of the gzip streams
	// to begin appending. gzopen will simply append a gzip
	// stream to the existing file.

	// gzopen can be used to read a file which is not in gzip format;
	// in this case gzread will directly read from the file without
	// decompression. When reading, this will be detected automatically
	// by looking for the magic two-byte gzip header.

	// gzopen returns NULL if the file could not be opened, if there
	// was insufficient memory to allocate the gzFile state, or if
	// an invalid mode was specified (an 'r', 'w', or 'a' was not
	// provided, or '+' was provided). errno can be checked to
	// determine if the reason gzopen failed was that the file
	// could not be opened.
	gzFile g = gzopen(filename.data(), "rb");

	if (g not_eq nullptr) return g;
}
