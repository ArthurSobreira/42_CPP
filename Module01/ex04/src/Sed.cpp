#include "Defines.hpp"
#include "Sed.hpp"
#include <fstream>
#include <sstream>

Sed::Sed( std::string target, std::string replacement ) : 
	_target(target), _replacement(replacement) {};

Sed::~Sed( void ) {};

/* Getter and Setter _target */
const std::string	Sed::getTarget( void ) const {
	return (this->_target);
}

void	Sed::setTarget( std::string target ) {
	this->_target = target;
}

/* Getter and Setter _replacement */
const	std::string	Sed::getReplacement( void ) const {
	return (this->_replacement);
}

void	Sed::setReplacement( std::string replacement ) {
	this->_replacement = replacement;
}

/* Public Methods */
namespace SUtils {
	std::string getFileContent( std::ifstream &file ) {
		std::stringstream	buffer;
		std::string	content;

		buffer << file.rdbuf();
		content = buffer.str();
		return (content);
	}

	void	replaceString( std::string &content, std::string target, std::string replacement ) {
		size_t	pos = content.find(target, 0);
		while (pos != std::string::npos) {
			std::string before = content.substr(0, pos);
			std::string after = content.substr(pos + target.length());
			content = before + replacement + after;
			pos += replacement.length();
			pos = content.find(target, pos);
		}
	}
}

int	Sed::replace( std::string filename ) {
	std::ifstream	inFile(filename.c_str());
	std::ofstream	outFile((filename + ".replace").c_str());

	if (!inFile || inFile.fail()) {
		std::cout << ERROR_OPEN_FILE(filename) << std::endl;
		return (FAILURE);
	}
	if (!outFile || outFile.fail()) {
		std::cout << ERROR_OPEN_FILE(filename + ".replace") << std::endl;
		return (FAILURE);
	}
	std::string	content = SUtils::getFileContent(inFile);
	SUtils::replaceString(content, this->getTarget(), 
		this->getReplacement());
	outFile << content;
	inFile.close();
	outFile.close();
	return (SUCCESS);
}
