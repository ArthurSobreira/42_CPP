#ifndef DEFINES_HPP
# define DEFINES_HPP

/* Color Reset */
# define RESET "\033[0m"

/* Colorize Macro */
# define COLORIZE(color, text) color << text << RESET

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

/* Messages Defines */
# define ATTACK_MESSAGE(name, target, damage) \
"ClapTrap " << COLORIZE(CYAN, name) << " attacks " << COLORIZE(YELLOW, target) \
<< ", causing " << COLORIZE(RED, damage) << " points of damage!"
# define TAKE_DAMAGE_MESSAGE(name, amount) \
"ClapTrap " << COLORIZE(CYAN, name) << " takes " \
<< COLORIZE(RED, amount) << " damage!"
# define BE_REPAIRED_MESSAGE(name, amount) \
"ClapTrap " << COLORIZE(CYAN, name) << " is being repaired by " \
<< COLORIZE(MAGENTA, amount) << " points"

# define NO_ENERGY_MESSAGE(name) \
"ClapTrap " << COLORIZE(CYAN, name) << " has no energy points left!"
# define ALREADY_DEAD_MESSAGE(name) \
"ClapTrap " << COLORIZE(CYAN, name) << " is already dead!"
# define DEATH_MESSAGE(name) \
"ClapTrap " << COLORIZE(CYAN, name) << " has just been killed!"

/* ScavTrap Messages */
# define ST_ATTACK_MESSAGE(name, target, damage) \
"ScavTrap " << COLORIZE(CYAN, name) << " attacks " << COLORIZE(YELLOW, target) \
<< ", causing " << COLORIZE(RED, damage) << " points of damage!"
# define ST_NO_ENERGY_MESSAGE(name) \
"ScavTrap " << COLORIZE(CYAN, name) << " has no energy points left!"
# define ST_ALREADY_DEAD_MESSAGE(name) \
"ScavTrap " << COLORIZE(CYAN, name) << " is already dead!"
# define GUARD_GATE_MESSAGE(name) \
"ScavTrap " << COLORIZE(CYAN, name) << " has entered in Gate keeper mode!"

/* FragTrap Messages */
# define HIGH_FIVES_MESSAGE(name) \
"FragTrap " << COLORIZE(CYAN, name) << " wants to high five!"

/* DiamondTrap Messages */
#define WHO_AM_I_MESSAGE(dt_name, ct_name) \
"DiamondTrap Name: " << COLORIZE(CYAN, dt_name) << std::endl << \
"ClapTrap Name: " << COLORIZE(CYAN, ct_name)

#endif