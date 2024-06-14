#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class AAnimal {
    protected:
        std::string _type;

    public:
        /* Constructor Method */
        AAnimal( void );

        /* Copy Constructor Method */
        AAnimal( const AAnimal &other );

        /* Copy Assignment Operator Overload */
        AAnimal &operator=( const AAnimal &other );

        /* Destructor Method */
        virtual ~AAnimal( void );

        /* Getter and Setter _type */
        std::string getType( void ) const;
        void setType( std::string type );
        
        /* Public Method */
        virtual void makeSound( void ) const = 0;
};

#endif
