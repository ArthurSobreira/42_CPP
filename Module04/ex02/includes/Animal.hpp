#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        /* Constructor Method */
        Animal( void );

        /* Copy Constructor Method */
        Animal( const Animal &other );

        /* Copy Assignment Operator Overload */
        Animal &operator=( const Animal &other );

        /* Destructor Method */
        virtual ~Animal( void );

        /* Getter and Setter _type */
        std::string getType( void ) const;
        void setType( std::string type );
        
        /* Public Method */
        virtual void makeSound( void ) const;
};

#endif
