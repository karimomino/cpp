# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 12:26:06 by kamin             #+#    #+#              #
#    Updated: 2023/07/07 12:26:08 by kamin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= Harl
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJS_DIR = objs

FILES		= main Harl

SRCS			= $(FILES:=.cpp)
OBJS			= $(addprefix $(OBJS_DIR)/, $(FILES:=.o))
HEADER			= Harl.hpp

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
