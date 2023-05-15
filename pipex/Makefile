NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = pipex.h libft.h

FILES =  mypipex utils_pipex checking   main removingquotes free split childs_check 


OBJ=$(FILES:=.o)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -I. -Ilib -c -o $@ $<

$(NAME): $(OBJ) libft/libft.a libpipex.a ft_printf/libftprintf.a
	$(CC) $(CFLAGS) -o $@ $^

all: $(NAME)

clean:
	rm -f *.o && cd libft && $(MAKE) clean && cd .. && cd ft_printf && $(MAKE) clean

fclean: clean
	rm -f $(NAME) && rm -f libpipex.a && cd libft && $(MAKE) fclean && cd .. && cd ft_printf && $(MAKE) fclean

re: fclean all

libft/libft.a:
	cd libft && $(MAKE)

libpipex.a:
	cc -c mypipex.c
	ar -rcs libpipex.a mypipex.o utils_pipex.o checking.o   main.o removingquotes.o free.o split.o childs_check.o 

ft_printf/libftprintf.a:
	cd ft_printf && $(MAKE)
