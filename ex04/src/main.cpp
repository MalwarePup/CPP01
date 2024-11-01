#include <iostream>
#include <fstream>
#include <string>

void printUsage(const char* programName)
{
	std::cerr << "Usage: " << programName << " filename s1 s2" << std::endl;
}

bool openFiles(const std::string& filename, std::ifstream& ifs, std::ofstream& ofs)
{
	ifs.open(filename.c_str());
	if (!ifs.is_open())
	{
		std::cerr << "Error: could not open input file: " << filename << std::endl;
		return false;
	}

	ofs.open((filename + ".replace").c_str());
	if (!ofs.is_open())
	{
		std::cerr << "Error: could not create output file: " << filename << ".replace" << std::endl;
		return false;
	}
	return true;
}

void replaceOccurrences(std::string& line, const std::string& s1, const std::string& s2)
{
	size_t pos = 0;
	while ((pos = line.find(s1, pos)) != std::string::npos)
	{
		line.replace(pos, s1.length(), s2);
		pos += s2.length();
	}
}

void processFile(std::ifstream& ifs, std::ofstream& ofs, const std::string& s1, const std::string& s2)
{
	std::string line;
	while (std::getline(ifs, line, '\0'))
	{
		replaceOccurrences(line, s1, s2);
		ofs << line;
	}
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		printUsage(argv[0]);
		return 1;
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 cannot be an empty string." << std::endl;
		return 1;
	}

	std::ifstream ifs;
	std::ofstream ofs;
	if (!openFiles(filename, ifs, ofs))
	{
		return 1;
	}
	processFile(ifs, ofs, s1, s2);
	ifs.close();
	ofs.close();
	return 0;
}
