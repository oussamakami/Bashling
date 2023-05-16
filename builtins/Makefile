# Define the name of your output program
NAME = builtins

# List of source files
SRC = env.c export.c split.c main.c utils.c unset.c

# List of object files, derived from source files
OBJ = $(SRC:.c=.o)

# Compiler to use
CC = gcc

# Flags to pass to the compiler
CFLAGS = #-Wall -Wextra -Werror

# Rule for "all" (default rule)
all: $(NAME)

# Rule for output program
$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)

# Generic rule for compiling source files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for "clean"
clean:
	rm -f $(OBJ)

# Rule for "fclean"
fclean: clean
	rm -f $(NAME)

# Rule for "re"
re: fclean all
