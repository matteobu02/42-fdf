NAME		=	libft.a
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -I $(INCLUDES)
AR			=	ar rc
SRCDIR		=	./srcs/
OBJDIR		=	./objs/
INCLUDES	=	./includes/

SRCS	=	ft_atoi.c		\
			ft_error.c		\
			ft_free_tab.c	\
			ft_putchar_fd.c	\
			ft_putstr_fd.c	\
			ft_strcpy.c		\
			ft_split.c		\
			ft_strlen.c		\
			get_next_line.c		\
			get_next_line_utils.c	\

OBJS	=	${addprefix $(OBJDIR), $(SRCS:%.c=%.o)}


# ===== #


all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJS)
				@$(AR) $(NAME) $(OBJS)
				@echo "Lirary sucessfully created"

clean:
				@rm -rf $(OBJDIR)
				@echo "Library objects removed"

fclean:
				@rm -rf $(NAME) $(OBJDIR)
				@echo "Library cleaned"

re:				fclean all

$(OBJDIR)%.o:	$(SRCDIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
				@mkdir -p $(OBJDIR)

.PHONY:			clean fclean all re
