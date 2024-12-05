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

NAME		= libft.a

SRCS		=	ft_atoi.c\
				ft_bzero.c\
				ft_calloc.c\
				ft_isalnum.c\
				ft_isalpha.c\
				ft_isascii.c\
				ft_isdigit.c\
				ft_isprint.c\
				ft_isspace.c\
				ft_isInCharset.c\
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
				ft_putstr.c\
				ft_split.c\
				ft_strchr.c\
				ft_strcmp.c\
				ft_strdup.c\
				ft_strndup.c\
				ft_strjoin.c\
				ft_strjoindoublefree.c\
				ft_strlcat.c\
				ft_strlcpy.c\
				ft_strlen.c\
				ft_strmapi.c\
				ft_strncmp.c\
				ft_strnstr.c\
				ft_strrchr.c\
				ft_strtrim.c\
				ft_striteri.c\
				ft_substr.c\
				ft_tolower.c\
				ft_toupper.c\
				get_next_line.c\
				ft_getFile.c\
				ft_lstnew.c\
				ft_lstsize.c\
				ft_lstadd_back.c\
				ft_lstadd_front.c\
				ft_lstlast.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c\


CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

OBJS 		= $(SRCS:%.c=$(OBJS_DIR)/%.o)
OBJS_DIR	= ./objs
DEP 		= $(OBJS:%.o=%.d)

INCLUDE 	= -I .



all		:	${NAME}

$(NAME)	: 	$(OBJS_DIR) ${OBJS}
				ar rc ${NAME} ${OBJS}

$(OBJS_DIR):
			mkdir -p $(OBJS_DIR)

-include $(DEP)
$(OBJS_DIR)/%.o	:	%.c 
						${CC} ${CFLAGS} $(INCLUDE) -MMD -c $< -o $@



clean	:
			rm -rf $(OBJS_DIR)

fclean	:	clean
			rm -rf ${NAME}

re	:	fclean all


.PHONY	:	all clean fclean re

 
 
 
