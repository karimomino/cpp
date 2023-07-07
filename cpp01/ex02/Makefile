# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kamin <kamin@student.42abudhabi.ae>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/07 10:46:32 by kamin             #+#    #+#              #
#    Updated: 2023/07/07 10:46:33 by kamin            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= brainRef
	
CC			= c++
FLAGS		= -Wall -Wextra -Werror -std=c++98
RM			= rm -rf

OBJS_DIR = objs

FILES		= main

SRCS			= $(FILES:=.cpp)
OBJS			= $(addprefix $(OBJS_DIR)/, $(FILES:=.o))

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) $(OPTS) -o $(NAME)

$(OBJS_DIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) $(OPTS) -c $< -o $@

clean:
	@$(RM) $(OBJS_DIR) $(OBJS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
