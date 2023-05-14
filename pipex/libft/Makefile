NAME=libft.a

FILES= ft_isalpha ft_isdigit ft_isalnum ft_isascii ft_strlen \
	   ft_toupper ft_tolower ft_strchr ft_strrchr ft_strncmp \
	   ft_strnstr ft_strlcpy ft_strlcat ft_atoi ft_strdup \
	   ft_substr ft_strjoin  ft_itoa ft_strmapi \
	   ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_isprint \
	   ft_putnbr_fd ft_strtrim ft_memcpy ft_memmove ft_memset \
	   ft_memcmp ft_memchr ft_bzero ft_calloc ft_striteri ft_strncpy ft_strstr

BFILES = ft_lstnew ft_lstadd_front \
	   ft_striteri ft_lstsize ft_lstlast ft_lstadd_back ft_lstdelone \
	   ft_lstclear ft_lstiter ft_lstmap

OBJ=$(FILES:=.o)

BOBJ=$(BFILES:=.o)

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FILES:=.c)
	ar rcs $(NAME) $(OBJ) 
bonus:
	gcc -Wall -Wextra -Werror -c $(BFILES:=.c)
	ar rcs $(NAME) $(BOBJ)
clean:
	rm -rf $(OBJ) $(BOBJ)
fclean:
	rm -rf $(OBJ) $(BOBJ) $(NAME)

re: fclean all