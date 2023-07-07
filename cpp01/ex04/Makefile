# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 11:52:58 by kamin             #+#    #+#              #
#    Updated: 2023/07/07 11:52:59 by kamin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Sed
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJS_DIR = objs

FILES		= main Sed

SRCS			= $(FILES:=.cpp)
OBJS			= $(addprefix $(OBJS_DIR)/, $(FILES:=.o))
HEADER			= Sed.hpp

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
