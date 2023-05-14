
NAME=libftprintf.a

CC=gcc
CFLAGS=-Wall -Werror -Wextra

CFILES= ft_printf.c to_hex.c ft_putnbr.c ft_strlen.c ft_putstr.c 


OBJECTS  = $(CFILES:.c=.o)

all:$(NAME)

$(NAME):$(OBJECTS)
	$(CC) $(CFLAGS)  -c $(CFILES) 
	ar -rcs	$@ $^


clean:
	rm -rf  $(OBJECTS)

fclean: clean
		rm -rf $(NAME)
	
re: fclean all
