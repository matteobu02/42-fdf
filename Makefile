NAME	=	fdf
CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror -I $(INCLUDE) -I libft/include/
SRCDIR	=	./src/
OBJDIR	=	./obj/
INCLUDE	=	./include/

ifeq ($(shell uname), Linux)
	MLXFLAGS = -lmlx -lX11 -lXext
else
	MLXFLAGS = -lmlx -framework AppKit -framework OpenGL
endif

SRC		=	main.c			\
			read_file.c		\
			draw_map.c		\
			drawing_tools.c	\

OBJ		=	${addprefix $(OBJDIR), $(SRC:%.c=%.o)}


# ===== #


all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJ)
				@make -C libft/
				$(CC) $(CFLAGS) $(OBJ) $(MLXFLAGS) -L libft -lft -o $(NAME)

bonus:			$(OBJDIR) $(OBJ)
				# TODO

clean:
				rm -rf $(OBJDIR)

fclean:			clean
				rm -rf $(NAME)
				@make -C libft/ fclean

re:				fclean all

$(OBJDIR)%.o:	$(SRCDIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
				@mkdir -p $(OBJDIR)

.PHONY:			re clean fclean obj all
