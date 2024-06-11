#ifndef SED_HPP
# define SED_HPP

#include <iostream>

class Sed {
	private:
		std::string	_target;
		std::string	_replacement;

	public:
		/* Constructor Method */
		Sed( std::string target, std::string replacement );

		/* Destructor Method */
		~Sed( void );

		/* Getter and Setter _target */
		const	std::string	getTarget( void ) const;
		void	setTarget( std::string target );

		/* Getter and Setter _replacement */
		const	std::string	getReplacement( void ) const;
		void	setReplacement( std::string replacement );

		/* Public Methods */
		int	replace( std::string filename );
};

#endif