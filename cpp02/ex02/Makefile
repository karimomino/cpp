NAME		= Fixed
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJS_DIR = objs

FILES		=  main Fixed

SRCS			= $(FILES:=.cpp)
OBJS			= $(addprefix $(OBJS_DIR)/, $(FILES:=.o))
HEADER			= Fixed.hpp

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	@$(CC) $(OBJS) $(OPTS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
