# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maricard <maricard@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/15 16:59:07 by maricard          #+#    #+#              #
#    Updated: 2023/05/16 17:19:19 by maricard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

RM = rm -f

CC = cc

CFLAGS = -Wall -Werror -Wextra

INCLUDES = ../includes

SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c ft_memcpy.c ft_memmove.c  \
ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c  \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c  \
ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strtrim.c \
ft_substr.c ft_tolower.c ft_toupper.c ft_memcmp.c ft_strrchr.c get_next_line.c \
ft_strcmp.c

SRC-OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c 

BONUS-OBJ = $(BONUS:.c=.o)

%.o:		%.c
			$(CC) -c $(CFLAGS) $^ -o $@ -I $(INCLUDES)

all:		$(NAME)
		
$(NAME):	$(SRC-OBJ)	
			ar rcs $(NAME) $(SRC-OBJ)

bonus:		$(NAME) $(BONUS-OBJ)
			ar rs $(NAME) $(BONUS-OBJ)

clean:
			$(RM) $(SRC-OBJ) $(BONUS-OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)
