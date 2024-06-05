#ifndef DEFINES_HPP
# define DEFINES_HPP

/* Color Reset */
# define RESET "\033[0m"

/* Regular Colors */
# define BLACK "\033[30m"
# define GRAY "\033[90m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

/* Bold Colors */
# define BOLD_BLACK "\033[1;30m"
# define BOLD_GRAY "\033[1;90m"
# define BOLD_RED "\033[1;31m"
# define BOLD_GREEN "\033[1;32m"
# define BOLD_YELLOW "\033[1;33m"
# define BOLD_BLUE "\033[1;34m"
# define BOLD_MAGENTA "\033[1;35m"
# define BOLD_CYAN "\033[1;36m"
# define BOLD_WHITE "\033[1;37m"

/* Underline Colors */
# define UNDER_BLACK "\033[4;30m"
# define UNDER_GRAY "\033[4;90m"
# define UNDER_RED "\033[4;31m"
# define UNDER_GREEN "\033[4;32m"
# define UNDER_YELLOW "\033[4;33m"
# define UNDER_BLUE "\033[4;34m"
# define UNDER_MAGENTA "\033[4;35m"
# define UNDER_CYAN "\033[4;36m"
# define UNDER_WHITE "\033[4;37m"

/* Utils Defines */
# define MAX_CONTACTS 8
# define HEADER_SIZE 45

/* Messages Defines */
# define WELCOME_MESSAGE BOLD_GREEN \
"   Welcome to the PhoneBook! (type 'help')" RESET
# define HELP_MESSAGE BOLD_WHITE \
"[ADD]    -  Add a new contact\n\
[SEARCH] -  Search for a contact\n\
[EXIT]   -  Exit the PhoneBook" RESET
# define ERROR_MESSAGE RED \
"Invalid command. Type 'help' for a list of commands." RESET
# define INPUT_MESSAGE BOLD_GRAY "PhoneBook> " RESET
# define EXIT_MESSAGE BOLD_CYAN \
"\n ~ Goodbye! Have a nice day! ~ " RESET

/* Error defines */
# define ERROR_EMPTY_FIELD(nameType) \
RED << std::string(nameType) << " cannot be empty." << RESET
# define ERROR_INVALID_NAME(nameType) \
RED << std::string(nameType) << " can only contain alphabets." << RESET
# define ERROR_INVALID_NUMBER(numberType) \
RED << std::string(numberType) << " can only contain digits." << RESET
# define ERROR_NUMBER_LENGTH \
RED "Phone Number must be between 10 and 15 digits" RESET
# define ERROR_INVALID_INDEX \
RED "Invalid index." RESET
# define ERROR_PHONEBOOK_EMPTY \
RED << "PhoneBook is empty." << RESET

/* Input Defines */
# define INPUT_FIRST_NAME \
UNDER_WHITE "First Name:" RESET " "
# define INPUT_LAST_NAME \
UNDER_WHITE "Last Name:" RESET " "
# define INPUT_NICKNAME \
UNDER_WHITE "Nickname:" RESET " "
# define INPUT_PHONE_NUMBER \
UNDER_WHITE "Phone Number:" RESET " "
# define INPUT_DARKEST_SECRET \
UNDER_WHITE "Darkest Secret:" RESET " "
# define INPUT_SEARCH \
UNDER_WHITE "Enter the index of the contact:" RESET " "

/* Print Defines */
# define PRINT_FIRST_NAME \
YELLOW << "First Name        :" << RESET
# define PRINT_LAST_NAME \
YELLOW << "Last Name         :" << RESET
# define PRINT_NICKNAME \
YELLOW << "Nickname          :" << RESET
# define PRINT_PHONE_NUMBER \
YELLOW << "Phone Number      :" << RESET
# define PRINT_DARKEST_SECRET \
YELLOW << "Darkest Secret    :" << RESET

#endif