# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dguet <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 12:25:52 by dguet             #+#    #+#              #
#    Updated: 2022/04/14 12:26:00 by dguet            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= ft_isprint.c	 ft_memcmp.c	  ft_split.c	 ft_strmapi.c  ft_toupper.c \
ft_atoi.c     ft_itoa.c		 ft_memcpy.c	  ft_strchr.c	 ft_strncmp.c  \
ft_bzero.c     ft_memmove.c	  ft_strdup.c	 ft_strnstr.c \
ft_calloc.c   ft_memset.c	  ft_striteri.c  ft_strrchr.c \
ft_isalnum.c   ft_putchar_fd.c  ft_strjoin.c \
ft_isalpha.c   ft_putendl_fd.c  ft_strlcat.c	 ft_strtrim.c \
ft_isascii.c  ft_lstsize.c	 ft_putnbr_fd.c   ft_strlcpy.c	 ft_substr.c\
ft_isdigit.c  ft_memchr.c	 ft_putstr_fd.c   ft_strlen.c	 ft_tolower.c \
ft_lstadd_back.c  ft_lstdelone.c ft_lstadd_front.c ft_lstlast.c	ft_lstnew.c	\
ft_lstclear.c ft_lstiter.c ft_lstmap.c

SRCS_BONUS	= ft_lstadd_back.c  ft_lstdelone.c ft_lstadd_front.c ft_lstlast.c ft_lstnew.c \
ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJS	= ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

CC		= gcc

CFLAGS	= -I. -c -Wall -Wextra -Werror

NAME	= libft.a

RM		= rm -f

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib $(NAME)

all:		${NAME}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

bonus:		${OBJS_BONUS}
			ar rc ${NAME} ${OBJS_BONUS}
			ranlib $(NAME)

.PHONY:		all clean fclean
