# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 10:52:19 by idongmin          #+#    #+#              #
#    Updated: 2022/07/25 09:40:42 by idongmin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= cub3D

SRCS_DIR	=	src

SRCS		=	main.c \
				checkMap.c \
				checkMapUtil.c \
				checkElement.c \
				checkMapError.c \
				util.c \
				start.c \
				raycastWall.c \
				raycastHeight.c \
				raycastUtils.c \
				settingRay.c \
				key.c \
				render.c \
				setTexture.c \
				mathUtil.c \
				mathUtil2.c \
				fadeColor.c \

MLX			=	./minilibx_opengl_20191021
MLX_LIB		=	libmlx.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
CLIB		=	-lmlx -framework OpenGL -framework Appkit -framework OpenCL
LIB			=	./lib

all		: $(NAME)
	@$(MAKE) -C $(LIB)
	@$(CC) $(CFLAGS) -L $(MLX) $(CLIB) $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o)) $(MLX)/$(MLX_LIB) lib/dmcw.a -o $(NAME)

$(NAME): srcs

srcs: $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

%.o	:%.c
	$(CC) $(CFLAGS)  -c $< -o $@

clean	:
	@$(MAKE) -C $(LIB) clean
	@rm -rf $(addprefix $(SRCS_DIR)/, $(SRCS:.c=.o))

fclean	: clean
	@$(MAKE) -C $(LIB) fclean
	@rm -rf	$(NAME)

re		: fclean all

.PHONY : all clean fclean re
