#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	std::ifstream	inputFile;
	std::ofstream	outFile;
	std::string		line;
	std::string		tmp_line;
	size_t			pos_f;
	size_t			tmp_pos = 0;

	//if (ac != 4)
	//{
	//	std::cerr << "Program takes three parameters order: a filename and two strings" << std::endl;
	//	return (EXIT_FAILURE);
	//}
	std::string	filename = (std::string)av[1];
	std::string	strFind = (std::string)av[2];
	std::string	strRep = (std::string)av[3];
	
	size_t pos_l = filename.find_last_of('.');
	std::string	outname = filename.substr(0, pos_l);
	
	outname.append(".append");
	inputFile.open(filename, std::ios::in);
	outFile.open(outname, std::ios::out | std::ios::trunc);
	(void)ac;
	while (std::getline(inputFile, line))
	{
		while (line.empty())
		{
			pos_f = line.find(av[3]);
			if (!pos_f)
			{	
				outFile << av[3];
				line = line.substr(strRep.length());
			}
			else if (pos_f)
			{
				tmp_line = line.substr(0, pos_f);
				outFile << tmp_line;
				line = line.substr(pos_f);
			}
			else
			{
				line = line.substr(0, line.length());
				outFile << line;
			}
			tmp_pos = pos_f;
		}
	}
	inputFile.close();
	outFile.close();
}