CC			=	cc
CFLAGS		=	-Wall -Wextra -g
RM			=	rm -rf
MOD 		=	dependencies/modules/ft_realloc.c
PARSING 	=	dependencies/parsing/cmd_tree_ops.c dependencies/parsing/parsing.c\
				dependencies/parsing/input_split.c
CFILES		=	core.c
PARSINGOBJ	=	$(PARSING:.c=.o)
COBJS		=	$(CFILES:.c=.o)
MODOBJ		=	$(MOD:.c=.o)
LIBFT		=	dependencies/libft/libft.a
NAME		=	minishell

all			:	$(NAME)

$(NAME)		:	$(COBJS) $(PARSINGOBJ) $(MODOBJ) $(LIBFT)
				$(CC) $(CFLAGS) -o $(NAME) $(COBJS) $(MODOBJ) $(PARSINGOBJ) $(LIBFT) -lreadline
$(LIBFT)	:
				cd dependencies/libft && $(MAKE)
clean		:
				$(RM) $(COBJS) $(PARSINGOBJ) $(MODOBJ)
				cd dependencies/libft && $(MAKE) clean
fclean		:	clean
				$(RM) $(NAME) $(LIBFT)
re			:	fclean all