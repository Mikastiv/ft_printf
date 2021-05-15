# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 19:00:56 by mleblanc          #+#    #+#              #
#    Updated: 2021/05/14 22:07:49 by mleblanc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC			=	src
OBJ			=	obj
INC			=	include
CFILES		=	ft_printf.c do_printf.c
SRCS		=	$(addprefix $(SRC)/, $(CFILES))
OBJS		=	$(addprefix $(OBJ)/, $(CFILES:.c=.o))
NAME		=	libftprintf.a
CC			=	clang
LIBC		=	ar rcs
CFLAGS		=	-Wall -Werror -Wextra
LIBFT		=	libft/libft.a
MAKELIBFT	=	$(MAKE) -C libft
RM			=	rm -rf
CP			=	cp
MKDIR		=	mkdir -p
NORMINETTE	=	norminette

$(OBJ)/%.o:	$(SRC)/%.c
			$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

$(NAME):	mkobj $(OBJS)
			$(MAKELIBFT) bonus
			$(CP) $(LIBFT) $(NAME)
			$(LIBC) $(NAME) $(OBJS)

mkobj:
			$(MKDIR) $(OBJ)

norme:
			$(NORMINETTE) $(SRCS) $(INC)/*.h

all:		$(NAME)

clean:
			$(MAKELIBFT) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKELIBFT) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re mkobj norme