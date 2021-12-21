NAME	=	fdf

SRCS	=	srcs/main.c			\
			srcs/read_file.c	\
			srcs/draw_map.c		\
			srcs/drawing_tools.c

OBJS	=	$(SRCS:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

M_FLAGS	=	-lmlx -Llibft -lft -framework AppKit -framework OpenGL

L_FLAGS	=	-lmlx -lX11 -lXext -Llibft -lft


all:		$(NAME)

$(NAME):	$(OBJS)
			make -C libft/
			$(CC) $(CFLAGS) $(OBJS) $(M_FLAGS) -o $(NAME)

linux:		$(OBJS)
			make -C libft/
			$(CC) $(CFLAGS) $(OBJS) $(L_FLAGS) -o $(NAME)

clean:
			rm -rf $(OBJS)
			make -C libft/ clean

fclean:		
			make -C libft/ fclean
			rm -rf $(NAME) $(OBJS)

re:			clean all

.PHONY:		re clean fclean libftmake all
