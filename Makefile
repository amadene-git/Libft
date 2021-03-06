# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: admadene <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/16 13:56:44 by admadene          #+#    #+#              #
#    Updated: 2021/01/12 16:28:11 by amadene          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		=	ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_isprint.c\
			ft_itoa.c\
			ft_memccpy.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrim.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c\
		    get_next_line.c\
			ft_strjoindoublefree.c\
	

OBJS		= ${SRCS:.c=.o }

OBJS_DIR	= objs

CFLAGS		= -Wall -Wextra -Werror

CC		= gcc

RM		= rm -rf

NAME		= libft.a

HEADER		= libft.h


.c.o 	:
			${CC} ${CFLAGS} -I  .  -c $< -o ${<:.c=.o}


all	:	${NAME}

$(NAME)	: 	${OBJS}
			ar rc ${NAME} ${OBJS}
			mkdir ${OBJS_DIR}
			mv ${OBJS} ${OBJS_DIR}

clean	:
			${RM} ${OBJS_DIR}

fclean	:	clean
			${RM} ${NAME}

re	:	fclean all


.PHONY	:	all clean fclean re

