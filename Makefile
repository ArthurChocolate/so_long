# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naqua <naqua@student.21-school.ru>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/07 16:38:14 by naqua             #+#    #+#              #
#    Updated: 2021/12/14 15:55:42 by naqua            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	so_long
NAME_BONUS			=	so_long_bonus

SRCS_FILES			=	so_long.c\
						ft_checker.c \
						get_next_line.c \
						get_next_line_utils.c \
						ft_map_reader.c \
						ft_draw.c \
						ft_exit.c \
						ft_load.c \
						ft_gameplay.c \
						ft_player_moves.c \
						ft_collect.c

SRCS_BONUS_FILES	=	so_long_bonus.c \
						ft_checker_bonus.c \
						get_next_line.c \
						get_next_line_utils.c \
						ft_map_reader_bonus.c \
						ft_draw_bonus.c \
						ft_exit_bonus.c \
						ft_load_bonus.c \
						ft_gameplay_bonus.c \
						ft_player_moves_bonus.c \
						ft_collect_bonus.c \
						ft_moves_bonus.c \
						ft_animation_bonus.c

SRCS_PATH			=	srcs/
SRCS_BONUS_PATH		=	srcs_bonus/

INCLUDE				=	-I ./include -I./minilibx

CC  				=	gcc
FLAGS				=	-Wall -Wextra -Werror
MLX_FLAGS			=	-framework OpenGL -framework AppKit

SRCS				=	$(addprefix $(SRCS_PATH),$(SRCS_FILES))
SRCS_BONUS			=	$(addprefix $(SRCS_BONUS_PATH),$(SRCS_BONUS_FILES))

OBJS				=	$(SRCS:%.c=%.o)
OBJS_BONUS			=	$(SRCS_BONUS:%.c=%.o)

MLX_PATH	=	./minilibx/libmlx.a
LIBFT_PATH	=	./libft/libft.a

$(NAME): $(OBJS) 
	$(MAKE) -C $(dir $(LIBFT_PATH))
	$(MAKE) -C $(dir $(MLX_PATH))
	cp $(MLX_PATH) .
	$(CC) $(FLAGS) $(LIBFT_PATH) $(MLX_PATH) $(OBJS) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(MAKE) -C $(dir $(LIBFT_PATH))
	$(MAKE) -C $(dir $(MLX_PATH))
	cp $(MLX_PATH) .
	$(CC) $(FLAGS) $(LIBFT_PATH) $(MLX_PATH) $(OBJS_BONUS) $(MLX_FLAGS) -o $(NAME_BONUS)

all: $(NAME)

bonus: $(NAME_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(MAKE) clean -C $(dir $(LIBFT_PATH))
	$(MAKE) clean -C $(dir $(MLX_PATH))
	rm -rf $(OBJS) $(OBJS_BONUS)

fclean:	clean
	$(MAKE) fclean -C $(dir $(LIBFT_PATH))
	rm -rf $(NAME) $(NAME_BONUS)
	rm -rf libmlx.a

re:	fclean all

.PHONY:	all clean fclean re bonus
