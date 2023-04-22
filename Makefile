CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror 
RM			=	rm -rf
CFILES		=	core.c dependencies/parsing/cmd_tree_ops.c
COBJS		=	$(CFILES:.c=.o)
LIBFT		=	dependencies/libft/libft.a
NAME		=	minishell

all			:	$(NAME)

$(NAME)		:	$(COBJS) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(COBJS) $(LIBFT) -lreadline
$(LIBFT)	:
				cd dependencies/libft && $(MAKE)
clean		:
				$(RM) $(COBJS)
				cd dependencies/libft && $(MAKE) clean
fclean		:	clean
				$(RM) $(NAME) $(LIBFT)
re			:	fclean all