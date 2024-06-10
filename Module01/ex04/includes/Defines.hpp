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

/* Error defines */
#define ERROR_INVALID_ARGUMENTS \
RED "Error: Invalid Number of Arguments" RESET
#define ERROR_NULL_ARGUMENT \
RED "Error: Null Argument" RESET
#define ERROR_OPEN_FILE(filename) \
RED << "Error: " << filename << " could not be opened." << RESET

#endif