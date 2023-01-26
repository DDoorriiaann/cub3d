SRC				=	main.c\
					drawing/circles.c\
					drawing/lines.c\
					drawing/mlx_addons.c\
					drawing/drawing_utils.c\
					drawing/minimap.c\
					drawing/minimap_rays.c\
					drawing/game_window.c\
					input_management/keys.c\
					game/game_routine.c\
					game/quit_game.c\
					game/movements/collisions.c\
					game/movements/movements.c\
					game/raycasting/raycasting.c\
					game/raycasting/horizontal_collision.c\
					game/raycasting/vertical_collision.c\
					parsing/parse_map.c\
					parsing/init.c\
					parsing/error.c\
					parsing/free_data.c\
					parsing/floor.c\
					parsing/ceiling.c\
					parsing/parsing_utils_1.c\
					parsing/parsing_utils_2.c\
					parsing/parsing_utils_3.c\
					parsing/parsing_utils_4.c\
					parsing/parsing_utils_5.c\
					parsing/parse_information.c\
					parsing/init_xpm.c\
					parsing/open_and_read_fd.c\

SRC_BONUS		=

OBJS			=	${addprefix src/mandatory/, ${SRC:.c=.o}}

OBJS_BONUS		=	${addprefix src/bonus/, ${SRC_BONUS:.c=.o}}

LIB_FLAGS		=	-L libft -L mlx_linux

MLX_FLAGS		=	-lm -lmlx -lXext -lX11

HEAD			=	-I includes -I libft -I mlx_linux

CC				=	clang

CFLAGS			=	-Wall -Werror -Wextra -g

RM				=	rm -rf

NAME			=	cub3D

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
