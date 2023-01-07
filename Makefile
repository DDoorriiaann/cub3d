SRCS			=	main.c

SRCS_BONUS		=

OBJS			=	${addprefix srcs/mandatory/, ${SRCS:.c=.o}}

OBJS_BONUS		=	${addprefix srcs/bonus/, ${SRCS_BONUS:.c=.o}}

LIB_FLAGS		=	-L libft -L mlx_linux

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx_linux

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g

RM				=	rm -rf

NAME			=	cub3d

.c.o			:
					${CC} ${CFLAGS} ${HEAD} -c $< -o ${<:.c=.o}

$(NAME)			:	${OBJS}
					make -sC libft
					make -sC mlx_linux
					${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS} -o ${NAME} -lft ${MLX_FLAGS}

all				:	${NAME}

bonus			:	${OBJS_BONUS}
					make -C libft
					make -C mlx_linux
					${CC} ${CFLAGS} ${LIB_FLAGS} ${OBJS_BONUS} -o ${NAME} -lft ${MLX_FLAGS}

clean			:
					make clean -sC libft
					make clean -sC mlx_linux
					${RM} ${OBJS} ${OBJS_BONUS}

fclean			:	clean
					make fclean -sC libft
					${RM} ${NAME}

re				:	fclean all

.SILENT:
.PHONY			:	all clean fclean re
