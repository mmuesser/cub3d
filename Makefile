NAME  = cub3d

BONUS_NAME = cub3d_bonus

CC	= gcc

CFLAGS	= -Werror -Wextra -Wall -g3

MLX_PATH    = ./mlx_linux/
MLX_NAME    = libmlx.a
MLX        = $(MLX_PATH)$(MLX_NAME)

INC	= -I ./include/ \
	  -I $(MLX_PATH)

SRC_PATH	= ./srcs/

SRC	= \
		main.c \
		hook.c \
		keys_moves.c \
		init.c \
		draws.c \
		raycasting.c \
		look.c\
		print.c\
		split_file_line.c \
		parsing.c \
		check_desc.c \
		check_map.c \
		split_desc_and_map.c \
		free_all.c \
		error.c \
		utils_parsing.c\
		3d.c\
		textures.c\
		print_textures_ew.c\
		print_textures_ns.c\
		colors.c\
		init2.c\
		draws2.c\
		keys_moves2.c\
		raycasting2.c\
		utils2.c\

SRC_BONUS = \
		main.c \
		hook.c \
		keys_moves.c \
		init.c \
		draws_bonus.c \
		raycasting.c \
		look.c\
		print.c\
		split_file_line.c \
		parsing.c \
		check_desc.c \
		check_map.c \
		split_desc_and_map.c \
		free_all.c \
		error.c \
		utils_parsing.c\
		3d.c\
		textures.c\
		print_textures_ew.c\
		print_textures_ns.c\
		colors.c\
		init2.c\
		draws2.c\
		keys_moves2.c\
		raycasting2.c\
		utils2.c\
		
	

SRCS        = $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH    = obj/
OBJ        = $(SRC:.c=.o)
OBJS        = $(addprefix $(OBJ_PATH), $(OBJ))

SRCS_BONUS  = $(addprefix $(SRC_PATH), $(SRC_BONUS))

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

$(NAME): $(MLX) $(OBJ_PATH) $(OBJS)
	@make -C ./Libft
	@echo "$(GREEN)Compiling cub3d...$(RESET)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(INC) -lXext -lX11 -lm -L Libft -lft -lreadline
	@echo "$(GREEN)cub3d ready.$(RESET)"

all: $(NAME) $(BONUS_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)
	@echo "$(GREEN)Compiled $< successfully!$(RESET)"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(MLX):
	@echo "$(GREEN)Making MiniLibX...$(RESET)"
	@make -sC $(MLX_PATH) 2>&1 >/dev/null

$(BONUS_NAME): $(MLX) $(OBJ_PATH) $(SRCS_BONUS)
	@make -C ./Libft
	@echo "$(GREEN)Compiling cub3d_bonus...$(RESET)"
	@$(CC) $(CFLAGS) -o $(BONUS_NAME) $(SRCS_BONUS) $(MLX) $(INC) -lXext -lX11 -lm -L Libft -lft -lreadline
	@echo "$(GREEN)cub3d_bonus ready.$(RESET)"

bonus: $(BONUS_NAME)

clean:
	@make clean -C ./Libft
	@echo "$(RED)Removing .o object files...$(RESET)"
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH) 2>&1 >/dev/null

fclean: clean
	@make fclean -C ./Libft
	@echo "$(RED)Removing cub3d...$(RESET)"
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all re clean fclean bonus