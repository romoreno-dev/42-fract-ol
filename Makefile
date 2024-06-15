# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: romoreno <romoreno@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/20 19:14:15 by romoreno          #+#    #+#              #
#    Updated: 2024/01/20 19:14:15 by romoreno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fractol

# Global directories
SRC := src
LIB := include
OBJ := obj/obj

# Libraries directories
LIBFT_ROUTE := $(LIB)/libft
# MINILIBX_ROUTE := $(LIB)/minilibx_opengl_20191021
MINILIBX_ROUTE_LINUX := $(LIB)/minilibx-linux

# Compiled libraries
LIBFT := $(LIBFT_ROUTE)/libft.a
# MINILIBX := $(MINILIBX_ROUTE)/libmlx.a
MINILIBX_LINUX := $(MINILIBX_ROUTE_LINUX)/libmlx_Linux.a

# Commands
COMPILER := gcc -Wall -Wextra -Werror
REMOVER := rm -rf

# Files
SRC_FILES := $(SRC)/main.c \
	$(SRC)/controllers/init_controllers.c $(SRC)/controllers/render_controllers.c \
	$(SRC)/handlers/event_handlers.c $(SRC)/handlers/julia_handlers.c  $(SRC)/handlers/exit_handlers.c \
	$(SRC)/utils/colors_utils.c $(SRC)/utils/math_utils.c $(SRC)/utils/printing_utils.c $(SRC)/utils/string_utils.c
OBJ_FILES := $(SRC_FILES:.c=.o)

		# @$(COMPILER) $(OBJ_FILES) $(LIBFT) $(MINILIBX) -framework OpenGL -framework AppKit  -o $(NAME)

# Styles
GREEN		:= \033[0;32m
BOLD 		:= \033[1m
BLUE		:= \033[0;94m
RESET_STYLE	:= \033[0m

# Rules
.c.o:
		@$(COMPILER) -c $< -o ${<:.c=.o}

all: fractol

$(NAME): $(OBJ_FILES) $(LIBFT) $(MINILIBX_LINUX)
		@echo "Creating $(NAME)..."
		@$(COMPILER) $(OBJ_FILES) $(LIBFT) $(MINILIBX_LINUX)  -lGL -lm -lX11 -lXext  -o $(NAME) #Ubuntu
		@echo "Using libft and minilibx for create $(NAME)"
		@echo "$(GREEN)$(BOLD)$(NAME) created!$(RESET_STYLE)"

$(LIBFT):
		@make -s -C $(LIBFT_ROUTE)
		@echo "$(GREEN)$(BOLD)libft compiled$(RESET_STYLE)"

# I supress warnings about deprecated tools on minilibx
$(MINILIBX):
		@make -s -C $(MINILIBX_ROUTE) 2>/dev/null
		@echo "$(GREEN)$(BOLD)minilibx compiled$(RESET_STYLE)"
$(MINILIBX_LINUX):
		@make -s -C $(MINILIBX_ROUTE_LINUX) 2>/dev/null
		@echo "$(GREEN)$(BOLD)minilibx compiled$(RESET_STYLE)"

clean:
		@echo "Cleaning..."
		@$(REMOVER) $(OBJ_FILES)
		@make clean -s -C $(LIBFT_ROUTE)
		@make clean -s -C $(MINILIBX_ROUTE_LINUX)
		@echo "$(BLUE)All objects files were cleaned!$(RESET_STYLE)"

fclean: clean
		@$(REMOVER) $(NAME)
		@make fclean -s -C $(LIBFT_ROUTE)
		@make clean -s -C $(MINILIBX_ROUTE_LINUX)
		@echo "$(BLUE)All compiled files were cleaned!$(RESET_STYLE)"

re: 	fclean all

.PHONY: all clean fclean re

# Instrucciones compilacion libreria grafica

# 1. COMPILAR
# 1.1. MinilibX en Linux (-L$(GRAPHIC_LIBRARY) -lmlx -lGL -lm -lX11 -lXext):
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) -L$(GRAPHIC_LIBRARY) -lmlx -lGL -lm -lX11 -lXext  -o $(NAME)
# 1.2. MinilibX en MAC (-L$(GRAPHIC_LIBRARY) -lmlx -framework OpenGL -framework AppKit):
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) -L$(GRAPHIC_LIBRARY) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

# 1.3. LibMlx42 en Linux:
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) $(GRAPHIC_LIBRARY) -Iinclude -ldl -lglfw -pthread -lm  -o $(NAME) -g
# 1.4. LibMlx42 en MAC:
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) $(GRAPHIC_LIBRARY) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/romoreno/.brew/opt/glfw/lib/" -o $(NAME) -g

# 2. AGREGAR YA COMPILADO(.a)
# 2.1. MinilibX en Linux ($(GRAPHIC_LIBRARY) -lmlx -lGL -lm -lX11 -lXext):
# GRAPHIC_LIBRARY := $(LIB)/libmlx/libmlx_Linux.a
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) $(GRAPHIC_LIBRARY) -lGL -lm -lX11 -lXext  -o $(NAME)
# 2.2. MinilibX en MAC (-framework OpenGL -framework AppKit):
# GRAPHIC_LIBRARY := $(LIB)/libmlx
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) -L$(GRAPHIC_LIBRARY) -lmlx -framework OpenGL -framework AppKit  -o $(NAME)

# 2.3. LibMlx42 en Linux:
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) $(GRAPHIC_LIBRARY) -Iinclude -ldl -lglfw -pthread -lm  -o $(NAME) -g
# 2.4. LibMlx42 en MAC:
# @$(COMPILER) $(OBJ_FILES) $(LIBFT) $(GRAPHIC_LIBRARY) -framework Cocoa -framework OpenGL -framework IOKit -Iinclude -lglfw -L"/Users/romoreno/.brew/opt/glfw/lib/" -o $(NAME) -g
