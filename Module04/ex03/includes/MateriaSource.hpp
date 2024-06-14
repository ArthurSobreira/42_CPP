
#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
	private:
		AMateria	*_materia[4];

	public:
		/* Constructor Method */
		MateriaSource( void );

		/* Copy Constructor Method */
		MateriaSource( const MateriaSource &other );

		/* Copy Assignment Operator Overload */
		MateriaSource &operator=( const MateriaSource &other );

		/* Destructor Method */
		~MateriaSource( void );

		/* Public Method */
		void learnMateria( AMateria *m );
		AMateria *createMateria( std::string const &type );
};

#endif // MATERIASOURCE_HPP_
