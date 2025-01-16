NAME = fract

# Fichiers sources et objets
SRC =  fractol.c \
       event.c \
       init.c \
       render.c \
       clean.c \
       create_img.c \
       calcul.c \
       color.c \
       destroy.c

OBJ = $(SRC:.c=.o)

# Chemins pour MiniLibX et headers
MLX_DIR = ./minilibx-linux
INCLUDES = -I$(MLX_DIR) -Iincludes

# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -Werror $(INCLUDES) -ggdb -g3

# Liens pour MiniLibX et autres bibliothèques
LDFLAGS = -L$(MLX_DIR) -lmlx -lm -lX11 -lXext
MLX = $(MLX_DIR)/libmlx.a

# Règles de construction
all: $(NAME)
	@echo "\033[32mCompilation réussie\033[0m"

$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(MLX) $(OBJ)
	@echo "\033[32mCompilation de $(NAME) ...\033[0m"
	$(CC) -o $(NAME) $(OBJ) $(MLX) -lXext -lX11 -lm

%.o: %.c
	@echo "\033[32mCompilation de $< ...\033[0m"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\033[32mSuppression des fichiers objets ...\033[0m"
	rm -f $(OBJ)

fclean: clean
	@echo "\033[32mSuppression de l'exécutable $(NAME) ...\033[0m"
	rm -f $(NAME)

re: fclean all
