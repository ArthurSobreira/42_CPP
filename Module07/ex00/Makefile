#------------------------------------------------------------------------------#
#                                  GENERICS                                    #
#------------------------------------------------------------------------------#

DEFAULT_GOAL: all
.DELETE_ON_ERROR: $(NAME)
.PHONY: all bonus clean fclean re eval

#------------------------------------------------------------------------------#
#                                VARIABLES                                     #
#------------------------------------------------------------------------------#

CC		=	c++
CFLAGS	=	-Wall -Werror -Wextra -std=c++98 -I includes/
RM		=	rm -rf

NAME	=	Template
NAME_S	=	TemplateEval
BUILD	=	./build
SRCS	=	src/main.cpp
SRCS_S	=	src/ex00.cpp
OBJS	=	$(addprefix $(BUILD)/, $(notdir $(SRCS:.cpp=.o)))
INC		=	$(wildcard includes/*.hpp)

GREEN	=	"\033[32;1m"
RED		=	"\033[31;1m"
CYAN	=	"\033[36;1;3m"
WHITE_U	=	"\033[37;1;4m"
LIMITER =	"\033[0m"

#------------------------------------------------------------------------------#
#                                 TARGETS                                      #
#------------------------------------------------------------------------------#

all: $(BUILD) $(NAME)

$(NAME): $(OBJS)
	@echo $(CYAN)[$(NAME) executable created successfully...]$(LIMITER)
	@$(CC) $(CFLAGS) $(OBJS) -o $@

$(BUILD)/%.o: src/%.cpp $(INC)
	@echo $(GREEN)[Compiling]$(LIMITER) $(WHITE_U)$(notdir $(<))...$(LIMITER)
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD):
	@mkdir -p $(BUILD)

eval: $(BUILD)
	@echo $(CYAN)[$(NAME_S) executable created successfully...]$(LIMITER)
	@$(CC) $(CFLAGS) $(SRCS_S) -o $(NAME_S)

clean:
	@echo $(RED)[Cleaning object files...]$(LIMITER)
	@$(RM) $(BUILD)

fclean: clean
	@echo $(RED)[Cleaning $(NAME) executable...]$(LIMITER)
	@echo $(RED)[Cleaning $(NAME_S) executable...]$(LIMITER)
	@$(RM) $(NAME)
	@$(RM) $(NAME_S)

re: fclean all
