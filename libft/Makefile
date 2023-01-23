# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybaudoui <ybaudoui@student.42angouleme.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 12:20:41 by ybaudoui          #+#    #+#              #
#    Updated: 2023/01/16 14:37:06 by ybaudoui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SRCS	= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
		  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
		  ft_strrchr.c ft_strcmp.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
		  ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
		  ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
		  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c\
		  ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		  ft_lstmap.c get_next_line.c get_next_line_utils.c ft_printf.c ft_putchar.c \
		  ft_puthexa_low.c ft_puthexa_upp.c ft_putnbr.c ft_putnbr_u.c ft_putptr.c \
		  ft_putstr.c \

OBJS	= ${SRCS:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -L. -I.

$(NAME):	${OBJS}
			ar rcs ${NAME} ${OBJS}

all :	${NAME}

clean : 
		rm -f $(OBJS)
	
fclean : clean
		rm -f $(NAME)

re : fclean all 

