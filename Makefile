
NAME = push_swap
NAME_BONUS = checker

CC = cc
FLAGS = -O3 -g3 -L -lft
CFLAGS = -Wall -Wextra -Werror

LIBFT = ./libft
LIBS = /include

RM = rm -f
FILES = main.c ft_utils.c push.c swap.c rotate.c reverse_rotate.c \
		add_to_stack.c check_duplic.c calculate_costs.c final_sort.c \
		find_max_value.c find_target.c move.c sort_stack.c stack_b.c \
		utils.c

FILES_BONUS = main_cheker.c utils_1.c utils_2.c push_checker.c \
			  swap_checker.c rotate_checker.c reverse_rotate_checker.c \
			  parse_arg.c

BONUS_DIR = bonus
SRC_DIR = srcs
INC_DIR = include
OBJ_DIR = build

IFLAGS = -I$(INC_DIR)
OBJS = $(addprefix $(OBJ_DIR)/, $(FILES:.c=.o))
OBJS_BONUS = $(addprefix $(OBJ_DIR)/, $(FILES_BONUS:.c=.o))

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LIBFT)
	$(CC) $(OBJS) $(CFLAGS) $(LIBFT)/libft.a -O3 -g3 -L -lft -o $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	make -C $(LIBFT)
	$(CC) $(OBJS_BONUS) $(CFLAGS) $(LIBFT)/libft.a $(FLAGS) -o $(NAME_BONUS)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	make clean -C $(LIBFT)
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	make fclean -C $(LIBFT)
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus