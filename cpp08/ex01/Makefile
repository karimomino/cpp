NAME		= Span
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJDIR = .obj

FILES		= main Span

SRC			= $(FILES:=.cpp)
OBJ			= $(addprefix $(OBJDIR)/, $(FILES:=.o))
HEADER		= Span.hpp

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	$(CC) $(OBJ) $(OPTS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	$(RM) $(OBJDIR) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re