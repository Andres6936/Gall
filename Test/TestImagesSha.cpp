// Design by Joan Andrés.

#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <boost/process.hpp>

namespace fs = std::filesystem;

int main(int argc, char* argv[])
{
	fs::path images = L"../Test/Images/";
	fs::directory_entry directory(images);
	std::vector<fs::path> filenames;
	std::vector<fs::path> filesPNG;
	std::vector<std::string> filenameOutput;

	if (directory.exists() and directory.is_directory())
	{
		for (const fs::directory_entry& entry : fs::directory_iterator(directory))
		{
			filenames.push_back(entry.path());
		}

		for (const fs::path& file: filenames)
		{
			if (file.extension() == ".png")
			{
				filesPNG.push_back(file);
				filenameOutput.push_back(file.filename().string() + ".xp");
			}
		}

		const std::string executable = "Gall";

		for (int i = 0; i < filesPNG.size(); ++i)
		{
			boost::process::system(executable, filesPNG[i].string(), filenameOutput[i]);
		}
	}
	else
	{
		std::cerr << "Error, the directory " << directory.path().string() << "not exist";
	}
}
