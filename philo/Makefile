# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 11:21:33 by joonasmykka       #+#    #+#              #
#    Updated: 2023/06/29 17:52:07 by joonasmykka      ###   ########.fr        #
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
OBJS += $(OBJDIR)/printer.o
OBJS += $(OBJDIR)/helpers.o
OBJS += $(OBJDIR)/routine.o
OBJS += $(OBJDIR)/lib_funcs.o
OBJS += $(OBJDIR)/activities.o
OBJS += $(OBJDIR)/life_monitor.o
OBJS += $(OBJDIR)/activity_helpers.o

INCLUDES = inc/philo.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES) -g

.PHONY: all
all: $(NAME)

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: src/%.c
	cc -c -g $< -o $@

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
	cc $(FLAGS) -fsanitize=address $(OBJS) -o $(NAME)
	./philo 4 500 200 100 10

.PHONY: thread
thread: fclean $(OBJS)
	cc $(FLAGS) -fsanitize=thread $(OBJS) -o $(NAME)
	./philo 4 500 200 100 10

.PHONY:
leaks: fclean $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)
	leaks --atExit -- ./philo 4 500 200 100 10
	