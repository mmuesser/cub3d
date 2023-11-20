NAME = cub3d

SRCS =	split_file_line.c \
		parsing.c \
		check_desc.c \
		check_map.c \
		init.c \
		split_desc_and_map.c \

OBJS = ${SRCS:.c=.o}

INCLUDE = -I ./include/

CC = cc

CFLAGS = -Werror -Wextra -Wall -g3

RM = rm -rf

.c.o:
		@${CC} ${CFLAGS} ${INCLUDE} -c $< -o ${<:.c=.o}

${NAME}: 	${OBJS} Makefile ./include/cub3d.h
			@make -C ./Libft
			@echo "Making cub3d..."
			@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} -L Libft -lft -lreadline -o ${NAME}
			@echo "cub3d is done"

all:	${NAME}

clean:
		@make clean -C ./Libft
		@${RM} ${OBJS}
		@echo "cub3d is deleted"

fclean: 
		@make fclean -C ./Libft
		@${RM} ${OBJS} ${NAME}
		@echo "cub3d is deleted"

re:		fclean all

.PHONY:	all clean fclean re