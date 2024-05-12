#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation", 145, 137), _target("Unknow")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation", 145, 137)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &obj) : AForm(obj.getName(), obj.getReq(), obj.getExec())
{
	_target = obj._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{

}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &obj)
{
	if (this != &obj)
	{
		_target = obj._target;
	}
	return (*this);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream outFile;
	std::string   outName;

	if (executor.getGrade() <= this->getExec())
	{
		outName = _target + "_shrubbery";
		outFile.open(outName.c_str(), std::ios::out | std::ios::trunc);
		if (!outFile.is_open())
		{
			std::cerr << "Open Outfile failed" << std::endl;	
			throw std::runtime_error("Failed to create file: " + outName);
		}
		outFile << '\n';
		outFile << "                       _{/{/\\}\\" << '\n';
		outFile << "                    `_{/\\}{/\\}/}/}" << '\n';
		outFile << "                  _{/\\} _{/\\}{//\\}/}" << '\n';              
		outFile << "                {/{/\\}{/{/\\}(\\}{/\\} _" << '\n';         
		outFile << "               `{/\\}{/{/\\}(_)\\}{/{/\\}  _" << '\n'; 
		outFile << "             _\\{/(\\}\\}{/{/\\}\\}{/){/\\}\\}}" << '\n'; 
		outFile << "            {/{/(_)/}{\\{/)\\}{\\(_){/}/}/}/}" << '\n'; 
		outFile << "           _{\\{/{/{\\{/{/(_)/}/}/}{\\(/}/}/}`" << '\n'; 
		outFile << "         {/{/{\\{\\{\\(/}`{\\{\\/}/}{\\}(_){\\/}\\}" << '\n'; 
		outFile << "         _{\\{/{\\{/(_)\\}/}{/{/{/\\}\\})\\}{/\\}}" << '\n'; 
		outFile << "        {/{/{\\{\\(/}{/{\\{\\{\\/})/}{\\(_)/}/}\\}}`" << '\n'; 
		outFile << "        {\\{\\/}(_){\\{\\{\\/}/}(_){\\/}{\\/}/}`)/}/}" << '\n'; 
		outFile << "        `{/{\\{\\/}{/{\\{\\{\\/}/}{\\{\\/}/}\\}(_)}/}}" << '\n'; 
		outFile << "         {/{\\{\\/}{/){\\{\\{\\/}/}{\\{\\(/}/}\\}/}\\}" << '\n'; 
		outFile << "          {/{\\{\\/}(_){\\{\\{\\(/}/}{\\(_)/}/}\\}/}" << '\n'; 
		outFile << "           {/({/{\\{/{\\{\\/}(_){\\/}/}\\}/}(\\}/}" << '\n'; 
		outFile << "            `(_|{/{\\/}{\\{\\/}/}{\\{\\|/}/}(_)`" << '\n'; 
		outFile << "              (_)/{/{\\{\\/}{/{\\{\\{\\(_)/}" << '\n'; 
		outFile << "                {/{\\{\\{\\/}/}{\\{\\}/}/}" << '\n'; 
		outFile << "                  {){/ {\\/}{\\/} \\}\\}" << '\n'; 
		outFile << "                       \\.-'.-/" << '\n'; 
		outFile << "              __...    |'-.-'| --...__" << '\n'; 
		outFile << "    _...--   ..----'   |'...'|  ' ..   ...." << '\n'; 
		outFile << "    -     .  . .    |. |-._  |   . .  '" << '\n';    
		outFile << "    .  '-  '    .--'   | '-.'|    .  '  . '" << '\n';
		outFile << "            ' ..       |'-_.-|" << '\n';
		outFile << "    .  '  .         _.-|-._ -|-._  .  '  ." << '\n';
		outFile << "                  .'   |'- .-|   '." << '\n';
		outFile << "    ..-'   ' .    '.   '-._.-'   .'  '  - ." << '\n';
		outFile << "    .-' '           '-._______.-'     '  ." << '\n';
		outFile << "            .      ~," << '\n';
		outFile << "        .       .   .   .    ' '-." << '\n';
		outFile.close();
	}
	else
		throw AForm::GradeTooLowExeception();
}
