# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joonasmykkanen <joonasmykkanen@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 11:21:33 by joonasmykka       #+#    #+#              #
#    Updated: 2023/05/10 13:51:34 by joonasmykka      ###   ########.fr        #
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
OBJS += $(OBJDIR)/problem.o
OBJS += $(OBJDIR)/helpers.o
OBJS += $(OBJDIR)/ft_atoi.o
OBJS += $(OBJDIR)/routine.o

INCLUDES = includes/philo.h

FLAGS = -Wall -Werror -Wextra -I $(INCLUDES)

DBFLAGS = -g -fsanitize=address

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

.PHONY: test
test: $(OBJS)
	cc $(DBFLAGS) $(FLAGS) $(OBJS) -o $(NAME)
	./philo