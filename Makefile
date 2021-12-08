NAME	=	fdf

SRCS	=	srcs/main.c			\
			srcs/read_file.c	\
			srcs/draw_map.c

OBJS	=	$(SRCS:.c=.o)

LIBFT	=	make -C libft/

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

M_FLAGS	=	-lmlx -framework AppKit -framework OpenGL

L_FLAGS	=	-lmlx -lm -L /usr/include -lX11 -lXext -no-pie


$(NAME):	$(OBJS) libftmake
			$(CC) $(CFLAGS) libft/libft.a $(OBJS) $(M_FLAGS) -o $(NAME)

libftmake:
			$(LIBFT)

all:		$(NAME)

clean:
			rm -rf $(OBJS)
			make -C libft/ clean

fclean:		clean
			rm -rf $(NAME) libft/libft.a

re:			clean all

.PHONY:		re clean fclean libftmake all
