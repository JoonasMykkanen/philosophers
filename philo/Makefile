# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 11:21:33 by joonasmykka       #+#    #+#              #
#    Updated: 2023/05/25 14:10:24 by joonasmykka      ###   ########.fr        #
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
OBJS += $(OBJDIR)/routine.o
OBJS += $(OBJDIR)/helper2.o
OBJS += $(OBJDIR)/lib_funcs.o
OBJS += $(OBJDIR)/activities.o

INCLUDES = includes/philo.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) -g $(OBJS) -o $(NAME)

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
	./philo 10 500 200 100 3

.PHONY: thread
thread: fclean $(OBJS)
	cc $(FLAGS) -g -fsanitize=thread $(OBJS) -o $(NAME)
	./philo 10 500 200 100 3

.PHONY:
leaks: fclean $(OBJS)
	cc $(FLAGS) -g $(OBJS) -o $(NAME)
	leaks --atExit -- ./philo 10 500 200 100 3
	