#ifndef DATA_HPP
#define DATA_HPP

class Data {
	private:
		int	_attribute;
		
	public:
		/* Constructor Method */
		Data( void );
		Data( int attribute );
		
		/* Copy Constructor Method */
		Data( const Data &other );
		
		/* Copy Assignment Operator Overload */
		Data &operator=( const Data &other );
		
		/* Destructor Method */
		~Data( void );
		
		/* Public Methods */
		int    getAttribute( void ) const;
};

#endif
