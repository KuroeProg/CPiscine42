OUT = libft.a

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS := ./srcs/ft_putchar.c ./srcs/ft_swap.c ./srcs/ft_putstr.c ./srcs/ft_strlen.c ./srcs/ft_strcmp.c

OBJ := $(SRCS:.c=.o)

INC_DIR = includes

all: $(OUT)

$(OUT): $(OBJ)
	ar rcs $(OUT) $(OBJ)
	ranlib $(OUT)

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(OUT)

re: fclean all

.PHONY: all clean fclean re
