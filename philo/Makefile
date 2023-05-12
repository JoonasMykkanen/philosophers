# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 11:21:33 by joonasmykka       #+#    #+#              #
#    Updated: 2023/05/12 16:10:22 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC = src

OBJDIR = obj

OBJS = $(OBJDIR)/main.o
OBJS += $(OBJDIR)/end.o
OBJS += $(OBJDIR)/init.o
OBJS += $(OBJDIR)/start.o
OBJS += $(OBJDIR)/clock.o
OBJS += $(OBJDIR)/helpers.o
OBJS += $(OBJDIR)/ft_atoi.o
OBJS += $(OBJDIR)/routine.o
OBJS += $(OBJDIR)/activities.o

INCLUDES = includes/philo.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.c
	cc -c $< -o $@

.PHONY: clean
clean:
	rm -f $(OBJS)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re: fclean all

.PHONY: address
address: fclean $(OBJS)
	cc $(FLAGS) -g -fsanitize=address $(OBJS) -o $(NAME)
	./philo 3 500 100 100 3

.PHONY: thread
thread: fclean $(OBJS)
	cc $(FLAGS) -g -fsanitize=thread $(OBJS) -o $(NAME)
	./philo 3 500 100 100 3
	