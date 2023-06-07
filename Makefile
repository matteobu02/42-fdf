NAME		=	fdf
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDES) -I libft/includes/
SRCDIR		=	./srcs/
OBJDIR		=	./objs/
INCLUDES	=	./includes/
OS			=	$(shell uname)

ifeq ($(OS), Linux)
	MLX_FLAGS = -lmlx -lX11 -lXext -Llibft -lft
else
	MLX_FLAGS = -lmlx -Llibft -lft -framework AppKit -framework OpenGL
endif

SRCS	=	main.c			\
			read_file.c		\
			draw_map.c		\
			drawing_tools.c	\

OBJS	=	${addprefix $(OBJDIR), $(SRCS:%.c=%.o)}


# ===== #


all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJS)
				@make -C libft/
				$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)

bonus:			$(OBJDIR) $(OBJS)
				# TODO

clean:
				@rm -rf $(OBJDIR)
				@make -C libft/ clean

fclean:			
				@make -C libft/ fclean
				@rm -rf $(NAME) $(OBJDIR)
				@echo "Project cleaned"

re:				clean all

$(OBJDIR)%.o:	$(SRCDIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
				@mkdir -p $(OBJDIR)

.PHONY:			re clean fclean all
