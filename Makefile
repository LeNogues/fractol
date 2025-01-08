NAME = fract

# Fichiers sources et objets
SRC = test_image.c
OBJ = $(SRC:.c=.o)

# Chemins pour MiniLibX et headers
MLX_DIR = ./minilibx-linux
INCLUDES = -I$(MLX_DIR) -Iincludes

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

# Liens pour MiniLibX et autres bibliothèques
LDFLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext
MLX = $(MLX_DIR)/libmlx.a

# Règles de construction
all: $(NAME)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(MLX) -lXext -lX11 -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all