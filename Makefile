# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aconceic <aconceic@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 21:54:54 by aconceic          #+#    #+#              #
#    Updated: 2024/10/08 09:38:30 by aconceic         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# linux link
# https://cdn.intra.42.fr/document/document/25858/minilibx-linux.tgz

# WSL link
# https://cdn.intra.42.fr/document/document/25859/minilibx_opengl.tgz

# openGL link
# https://cdn.intra.42.fr/document/document/25859/minilibx_opengl.tgz

##############################################
#                 MAIN SOURCES               #
##############################################
#Libraries
LIBFT_DIR = libraries/libft/
LIBFT_LIB = $(LIBFT_DIR)libft.a
PRINTF_DIR = $(LIBFT_DIR)/ft_printf
GNL_DIR = $(LIBFT_DIR)get_next_line/
GNL_LIB = $(GNL_DIR)gnl.a

### Project
NAME = cub3D
OBJ_DIR = ./objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
SRC_DIR = ./sources/
SRC = main.c memory/free.c memory/init.c start/start_game.c parsing/support.c \
	  parsing/scene.c parsing/elements.c parsing/elements2.c \
	  parsing/map.c parsing/map_validations1.c raycaster/raycaster.c\
	  events/exit.c events/handlers.c raycaster/render_textures.c\
	  events/move.c parsing/map_validations2.c events/rotate.c\
	  utils/utils.c\

### MiniLibX
##DIR FOR MLX HAVING IN CONSIDERATION THE OS
MLX_DIR = libraries/minilibx-linux/
##FLAGS FOR MLX HAVING IN CONSIDERATION THE OS
MLXFLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

### Compilation
CC = cc
GCC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

### BONUS
BONUS_NAME = cub3D_bonus
BONUS_OBJ_DIR = ./objs_bonus/
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR), $(BONUS_SRC:.c=.o))
BONUS_SRC_DIR = ./bonus/
BONUS_SRC = main_bonus.c memory_bonus/free_bonus.c memory_bonus/init_bonus.c start_bonus/start_game_bonus.c parsing_bonus/support_bonus.c \
	  parsing_bonus/scene_bonus.c parsing_bonus/elements_bonus.c parsing_bonus/elements2_bonus.c \
	  parsing_bonus/map_bonus.c parsing_bonus/map_validations1_bonus.c raycaster_bonus/raycaster_bonus.c\
	  events_bonus/exit_bonus.c events_bonus/handlers_bonus.c raycaster_bonus/render_textures_bonus.c\
	  events_bonus/move_bonus.c parsing_bonus/map_validations2_bonus.c bonus/mini_map_bonus.c events_bonus/rotate_bonus.c\
	  utils_bonus/utils_bonus.c bonus/gun_bonus.c


### RULES
all : download mlx_compile $(NAME)

mlx_compile : download
	@echo "$(ORANGE)[!]$(RESET) Working on MiniLibX ..."
	@$(MAKE) -C $(MLX_DIR) > /dev/null 2>&1

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@echo "$(ORANGE)[!]$(RESET) Creating object file: $@ from source: $< ..."
	@mkdir -p $(dir $@) > /dev/null 2>&1
	@$(GCC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ) $(LIBFT_LIB)
	@echo "$(ORANGE)[!]$(RESET) Working on project ... "
	@$(GCC) $(CFLAGS) $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(MLXFLAGS) -o $(NAME) > /dev/null 2>&1
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Ok!$(RESET) "

$(LIBFT_LIB) : $(LIBFT_DIR) $(PRINTF_DIR) $(GNL_DIR)
	@echo "$(ORANGE)[!]$(RESET) Working on LIBFT_LIB ..."
	@make -C $(LIBFT_DIR) bonus > /dev/null 2>&1
	@make -C $(PRINTF_DIR) > /dev/null 2>&1
	@make -C $(GNL_DIR) > /dev/null 2>&1
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)LIBFT Ok!$(RESET)"

clean:
	@echo "$(ORANGE)[!]$(RESET) Executing cleaning ..."
	@$(RM) -rf $(OBJ_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(LIBFT_DIR) > /dev/null 2>&1
	@$(MAKE) clean -C $(MLX_DIR) > /dev/null 2>&1
	@$(RM) -rf $(OBJ_DIR) $(BONUS_OBJ_DIR) > /dev/null 2>&1
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Cleaning Ok!$(RESET)"

fclean:
	@echo "$(ORANGE)[!]$(RESET) Executing full cleaning..."
	@$(RM) $(NAME) > /dev/null 2>&1
	@$(RM) -rf $(OBJ_DIR) > /dev/null 2>&1
	@$(RM) -rf $(OBJ_DIR) $(BONUS_OBJ_DIR) > /dev/null 2>&1
	@$(RM) $(BONUS_NAME) > /dev/null 2>&1
#	@$(RM) -rf $(MLX_DIR) > /dev/null 2>&1
	@$(MAKE) fclean -C $(LIBFT_DIR) > /dev/null 2>&1
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Full cleaning Ok!$(RESET)"

re : fclean all
	@echo "$(GREEN)[✔]$(RESET) $(MAGENTA)Refresh Ok!$(RESET) "

download:
ifeq ($(shell test -d $(MLX_DIR) && echo yes),)
	@echo "$(ORANGE)[!]$(RESET) Downloading MiniLibX..."
	@wget https://cdn.intra.42.fr/document/document/32396/minilibx-linux.tgz
	@tar -xzf minilibx-linux.tgz -C libraries
	@rm minilibx-linux.tgz
else
	@echo "$(GREEN)[✔]$(RESET) MiniLibX already exists, skipping download."
endif

bonus : download mlx_compile $(BONUS_NAME)

$(BONUS_OBJ_DIR)%.o: $(BONUS_SRC_DIR)%.c
	@mkdir -p $(dir $@) > /dev/null 2>&1
	@echo "$(ORANGE)[!]$(RESET) Creating object file: $@ from source: $< ..."
	@$(GCC) $(CFLAGS) -c $< -o $@

$(BONUS_NAME) : $(BONUS_OBJ) $(LIBFT_LIB)
	@echo "$(ORANGE)[!]$(RESET) Working on bonus project ... "
	@$(GCC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT_LIB) $(GNL_LIB) $(MLXFLAGS) -o $(BONUS_NAME)
	@echo "$(GREEN)[✔]$(RESET) $(BLUE)Bonus Ok!$(RESET)"

bonus : download mlx_compile $(BONUS_NAME)

.SILENT : all