NAME = fdf
LIBMLX_DIR = ./minilibx
LIBFT_DIR = ./libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBMLXFLAGS = -L$(LIBMLX_DIR) -lmlx
LIBFTFLAGS = -L$(LIBFT_DIR) -lft

SOURCES_DIR = ./sources/
SOURCES_LIST = main.c read_map.c draw_map.c project_map.c manage_map.c fdf_utils.c
SOURCES = $(addprefix $(SOURCES_DIR), $(SOURCES_LIST))

OBJECTS_DIR = ./objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIR), $(OBJECTS_LIST))

D_FILES_DIR = ./objects/
D_FILES_LIST = $(patsubst %.c, %.d, $(SOURCES_LIST))
D_FILES = $(addprefix $(D_FILES_DIR), $(D_FILES_LIST))

all: libft libmlx $(NAME)

$(NAME): $(OBJECTS_DIR) $(OBJECTS)
	$(CC) $(OBJECTS) -lm $(LIBFTFLAGS) $(LIBMLXFLAGS) -framework OpenGL -framework AppKit -o $(NAME)

$(OBJECTS_DIR):
	@mkdir -p $(OBJECTS_DIR)

$(OBJECTS_DIR)%.o: $(SOURCES_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -MMD

include $(wildcard $(D_FILES_DIR)*.d)

.PHONY: all libft libmlx clean fclean re

libft:
	@make -s -C $(LIBFT_DIR)

libmlx:
	@make -s -C $(LIBMLX_DIR)

clean:
	@rm -rf $(OBJECTS_DIR)
	@make clean -s -C $(LIBMLX_DIR)
	@make clean -s -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -s -C $(LIBFT_DIR)

re: fclean all


