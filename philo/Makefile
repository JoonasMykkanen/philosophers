# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 11:21:33 by joonasmykka       #+#    #+#              #
#    Updated: 2023/06/29 17:58:54 by joonasmykka      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRCDIR = src
OBJDIR = obj

SRCS = $(SRCDIR)/main.c
SRCS += $(SRCDIR)/end.c
SRCS += $(SRCDIR)/init.c
SRCS += $(SRCDIR)/start.c
SRCS += $(SRCDIR)/clock.c
SRCS += $(SRCDIR)/printer.c
SRCS += $(SRCDIR)/helpers.c
SRCS += $(SRCDIR)/routine.c
SRCS += $(SRCDIR)/lib_funcs.c
SRCS += $(SRCDIR)/activities.c
SRCS += $(SRCDIR)/life_monitor.c
SRCS += $(SRCDIR)/activity_helpers.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCLUDES = inc/philo.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES) -g

.PHONY: all
all: $(NAME) 

$(NAME): $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCLUDES)
	mkdir -p $(OBJDIR)
	cc $(FLAGS) -c $< -o $@

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

.PHONY: leaks
leaks: fclean $(OBJS)
	cc $(FLAGS) $(OBJS) -o $(NAME)
	leaks --atExit -- ./philo 4 500 200 100 10
