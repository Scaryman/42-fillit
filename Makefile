TARGET = fillit

CC = gcc
CFLAGS = -Wall -Werror -Wextra -c

SRC = main.c tetromino.c utils.c matrix.c solver.c free.c printer.c field.c
OBJ = $(SRC:.c=.o)
DEP = $(SRC:.c=.d)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re

all: $(TARGET)

$(TARGET): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(LIBFT) -o $(TARGET)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -MMD -MP $(CFLAGS) $< -o $@

clean:
	$(RM) -f $(OBJ) $(DEP)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) -f $(TARGET)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all	
