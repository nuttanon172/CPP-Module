#include <iostream>
#include <fstream>
#include <stdlib.h>

void	ft_replace(std::ifstream &inputFile, std::ofstream &outFile, std::string strFind, std::string strRep)
{
	std::string		line;
	std::string		tmp_line;
	size_t			pos;

	while (std::getline(inputFile, line))
	{
		pos = 0;
		tmp_line = "";
		while ((pos = line.find(strFind, pos)) != (size_t)-1)
		{
			tmp_line = line.substr(0, pos);
			tmp_line += strRep;
			tmp_line += line.substr(pos + strFind.size());
			line = tmp_line;
			pos += strRep.size();
		}
		outFile << line;
		outFile << std::endl;
	}
}

int	main(int ac, char **av)
{
	std::ifstream	inputFile;
	std::ofstream	outFile;

	if (ac != 4)
	{
		std::cerr << "Program takes three parameters order: a filename and two strings" << std::endl;
		return (EXIT_FAILURE);
	}	
	std::string	filename = (std::string)av[1];
	std::string	strFind = (std::string)av[2];
	std::string	strRep = (std::string)av[3];
	if (filename.empty() || strFind.empty())
	{
		std::cerr << "Input valid" << std::endl;	
		return (EXIT_FAILURE);
	}
	size_t pos_l = filename.find_last_of('.');
	std::string	outname = filename.substr(0, pos_l);
	outname.append(".append");
	inputFile.open(filename.c_str(), std::ios::in);
	if (!inputFile.is_open())
	{
		std::cerr << "Open Inputfile failed" << std::endl;	
		return (EXIT_FAILURE);
	}
	outFile.open(outname.c_str(), std::ios::out | std::ios::trunc);
	if (!outFile.is_open())
	{
		std::cerr << "Open Outfile failed" << std::endl;	
		return (inputFile.close(), EXIT_FAILURE);
	}
	ft_replace(inputFile, outFile, strFind, strRep);
	inputFile.close();
	outFile.close();
	return (EXIT_SUCCESS);
}