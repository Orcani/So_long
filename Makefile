NAME = so_long
LIBFT = libft.a
PRINTF = libftprintf.a
MLX = libmlx.a

SRC =  parsing.c main.c verification.c

OBJ = $(addprefix $(SL_OBJS_DIR)/, $(SRC:.c=.o)) 



CC = gcc
CFLAGS = -Wextra -Wall -Werror -g 
MLX_FLAGS = -lmlx -lX11 -lXext
MATH_FLAGS = -lm -O3
LDFLAGS = -pie

SL_HEADER_DIR = includes
SL_SRC_DIR = srcs
SL_OBJS_DIR = objs

LIBFT_DIR = ./Libft
LIBFT_HEADER_DIR = $(LIBFT_DIR)/includes
LIBFT_SRC_DIR= ./srcs

PRINTF_DIR = ./ft_printf
PRINTF_HEADER_DIR = $(PRINTF_DIR)/includes
PRINTF_SRC_DIR= ./srcs

MLX_DIR = ./minilibx
MLX_HEADER_DIR = $(MLX_DIR)

SL_INCLUDES = -I $(SL_HEADER_DIR) -I $(LIBFT_HEADER_DIR) -I $(PRINTF_HEADER_DIR) -I $(MLX_HEADER_DIR) 
SL_LIBRARIES = -L$(LIBFT_DIR) -lft  -L$(PRINTF_DIR) -lftprintf  -L$(MLX_DIR) $(MLX_FLAGS) $(MATH_FLAGS)
#SL_LIBRARIES = -L$(LIBFT_DIR) -lft -L$(PRINTF_DIR) -lftprintf -L$(MLX_DIR) -lmlx $(MATH_FLAGS)



all:  $(LIBFT) $(PRINTF) $(MLX) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)
$(MLX):
	$(MAKE) -C $(MLX_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SL_INCLUDES) $(OBJ) $(SL_LIBRARIES) -o $(NAME)

$(SL_OBJS_DIR)/%.o: $(SL_SRC_DIR)/%.c
	@mkdir -p $(SL_OBJS_DIR)
	${CC} ${CFLAGS} $(SL_INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(PRINTF_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(PRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

