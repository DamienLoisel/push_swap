# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dloisel <dloisel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/24 15:47:11 by dloisel           #+#    #+#              #
#    Updated: 2024/06/29 20:52:39 by dloisel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GRAY = \033[30m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
RESET = \033[0m

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRC = source/free_and_error.c \
	source/push_swap.c \
	source/push_swap_utils_1.c \
	source/push_swap_utils_2.c \
	source/push_swap_utils_3.c \
	source/stack_init.c \
	source/stack_manip.c \
	source/stack_parsing.c \
	source/little_sort.c \
	source/big_sort.c \
	source/sort_utils1.c \
	source/sort_utils2.c \

SRC_BONUS = checker_bonus/checker.c \
	checker_bonus/instruction_parsing.c \
	source/free_and_error.c \
	source/push_swap_utils_1.c \
	source/push_swap_utils_2.c \
	source/push_swap_utils_3.c \
	source/stack_init.c \
	source/stack_manip.c \
	source/stack_parsing.c \
	source/little_sort.c \
	source/big_sort.c \
	source/sort_utils1.c \
	source/sort_utils2.c \

OBJ = $(SRC:.c=.o)
OBJS_BONUS = $(SRC_BONUS:.c=.o)

LIBFT = ./include/libft/libft.a
PRINTF = ./include/ft_printf/libftprintf.a
GNL = ./include/get_next_line/get_next_line.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(PRINTF)
	@$(CC) $(OBJ) $(LIBFT) $(PRINTF) $(CFLAGS) -o $(NAME)
	@echo
	@echo "$(GREEN)██████╗ ██╗   ██╗ ██████╗██╗  ██╗   ██████╗ ██╗       ██╗ █████╗ ██████╗ "
	@echo "$(GREEN)██╔══██╗██║   ██║██╔════╝██║  ██║  ██╔════╝ ██║  ██╗  ██║██╔══██╗██╔══██╗"
	@echo "$(GREEN)██████╔╝██║   ██║╚█████╗ ███████║  ╚█████╗  ╚██╗████╗██╔╝███████║██████╔╝"
	@echo "$(GREEN)██╔═══╝ ██║   ██║ ╚═══██╗██╔══██║   ╚═══██╗  ████╔═████║ ██╔══██║██╔═══╝ "
	@echo "$(GREEN)██║     ╚██████╔╝██████╔╝██║  ██║  ██████╔╝  ╚██╔╝ ╚██╔╝ ██║  ██║██║     "
	@echo "$(GREEN)╚═╝      ╚═════╝ ╚═════╝ ╚═╝  ╚═╝  ╚═════╝    ╚═╝   ╚═╝  ╚═╝  ╚═╝╚═╝     "
	@echo
	@echo "$(GREEN) █████╗  █████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████╗ ██╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗██║"
	@echo "$(GREEN)██║  ╚═╝██║  ██║██╔████╔██║██████╔╝██║██║     █████╗  ██║  ██║██║"
	@echo "$(GREEN)██║  ██╗██║  ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██║  ██║╚═╝"
	@echo "$(GREEN)╚█████╔╝╚█████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██████╔╝██╗"
	@echo "$(GREEN) ╚════╝  ╚════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝ ╚═╝"
	@echo

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@echo "$(YELLOW)Making libft..."
	@make bonus --no-print-directory -C ./include/libft

$(PRINTF):
	@echo "$(YELLOW)Making printf..."
	@make --no-print-directory -C ./include/ft_printf

$(GNL):
	@echo "$(YELLOW)Making GNL..."
	@make --no-print-directory -C ./include/get_next_line

clean:
	@echo "$(RED)make clean..."
	@rm -f $(OBJ)
	@rm -f $(OBJS_BONUS)
	@make clean --no-print-directory -C ./include/libft
	@make clean --no-print-directory -C ./include/ft_printf
	@make clean --no-print-directory -C ./include/get_next_line

fclean: clean
	@echo "$(RED)make fclean..."
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@make fclean --no-print-directory -C ./include/libft
	@make fclean --no-print-directory -C ./include/ft_printf
	@make fclean --no-print-directory -C ./include/get_next_line

re: fclean all

bonus: $(OBJS_BONUS) $(LIBFT) $(PRINTF) $(GNL)
	@$(CC) $(OBJS_BONUS) $(LIBFT) $(PRINTF) $(GNL) $(CFLAGS) -o $(NAME_BONUS)
	@echo
	@echo "$(GREEN)██████╗  █████╗ ███╗  ██╗██╗   ██╗ ██████╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ██║██║   ██║██╔════╝"
	@echo "$(GREEN)██████╦╝██║  ██║██╔██╗██║██║   ██║╚█████╗ "
	@echo "$(GREEN)██╔══██╗██║  ██║██║╚████║██║   ██║ ╚═══██╗"
	@echo "$(GREEN)██████╦╝╚█████╔╝██║ ╚███║╚██████╔╝██████╔╝"
	@echo "$(GREEN)╚═════╝  ╚════╝ ╚═╝  ╚══╝ ╚═════╝ ╚═════╝ "
	@echo
	@echo "$(GREEN) █████╗  █████╗ ███╗   ███╗██████╗ ██╗██╗     ███████╗██████╗ ██╗"
	@echo "$(GREEN)██╔══██╗██╔══██╗████╗ ████║██╔══██╗██║██║     ██╔════╝██╔══██╗██║"
	@echo "$(GREEN)██║  ╚═╝██║  ██║██╔████╔██║██████╔╝██║██║     █████╗  ██║  ██║██║"
	@echo "$(GREEN)██║  ██╗██║  ██║██║╚██╔╝██║██╔═══╝ ██║██║     ██╔══╝  ██║  ██║╚═╝"
	@echo "$(GREEN)╚█████╔╝╚█████╔╝██║ ╚═╝ ██║██║     ██║███████╗███████╗██████╔╝██╗"
	@echo "$(GREEN) ╚════╝  ╚════╝ ╚═╝     ╚═╝╚═╝     ╚═╝╚══════╝╚══════╝╚═════╝ ╚═╝"
	@echo

.PHONY: all clean fclean re bonus
