# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/13 14:11:55 by mrachid           #+#    #+#              #
#    Updated: 2014/03/26 13:51:31 by jzimini          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = RayT

OBJ = $(SRCS:.c=.o)

FLAG = -Wall -Werror -Wextra -O3 -pedantic

DIR_LIBS = /usr/X11/lib

SRCS = cone.c cylinder.c ft_tmp.c item_fun.c light.c parser.c points.c start.c\
	sphere.c vectors.c color.c ft_core.c \
	get_light.c main.c plane.c process_pixel.c utils_parser.c

XFLAGS = -L$(DIR_LIBS) -lXext -lX11 -lmlx

.PHONY: clean all re fclean

all: $(NAME)

make:
	@make -C libft/

$(NAME): $(OBJ)
	@gcc -o $(NAME) $(OBJ) -L libft $(XFLAGS) -lft -g
	@echo "\033[1;46m"
	@echo "RRRRRRRRRRRRRRRRR                                           TTTTTTTTTTTTTTTTTTTTTTT                                                                                               "
	@echo "R::::::::::::::::R                                          T:::::::::::::::::::::T                                                                                               "
	@echo "R::::::RRRRRR:::::R                                         T:::::::::::::::::::::T                                                                                               "
	@echo "RR:::::R     R:::::R                                        T:::::TT:::::::TT:::::T                                                                                               "
	@echo "  R::::R     R:::::R  aaaaaaaaaaaaayyyyyyy           yyyyyyyTTTTTT  T:::::T  TTTTTTrrrrr   rrrrrrrrr   aaaaaaaaaaaaa      cccccccccccccccc    eeeeeeeeeeee    rrrrr   rrrrrrrrr   "
	@echo "  R::::R     R:::::R  a::::::::::::ay:::::y         y:::::y         T:::::T        r::::rrr:::::::::r  a::::::::::::a   cc:::::::::::::::c  ee::::::::::::ee  r::::rrr:::::::::r  "
	@echo "  R::::RRRRRR:::::R   aaaaaaaaa:::::ay:::::y       y:::::y          T:::::T        r:::::::::::::::::r aaaaaaaaa:::::a c:::::::::::::::::c e::::::eeeee:::::eer:::::::::::::::::r "
	@echo "  R:::::::::::::RR             a::::a y:::::y     y:::::y           T:::::T        rr::::::rrrrr::::::r         a::::ac:::::::cccccc:::::ce::::::e     e:::::err::::::rrrrr::::::r"
	@echo "  R::::RRRRRR:::::R     aaaaaaa:::::a  y:::::y   y:::::y            T:::::T         r:::::r     r:::::r  aaaaaaa:::::ac::::::c     ccccccce:::::::eeeee::::::e r:::::r     r:::::r"
	@echo "  R::::R     R:::::R  aa::::::::::::a   y:::::y y:::::y             T:::::T         r:::::r     rrrrrrraa::::::::::::ac:::::c             e:::::::::::::::::e  r:::::r     rrrrrrr"
	@echo "  R::::R     R:::::R a::::aaaa::::::a    y:::::y:::::y              T:::::T         r:::::r           a::::aaaa::::::ac:::::c             e::::::eeeeeeeeeee   r:::::r            "
	@echo "  R::::R     R:::::Ra::::a    a:::::a     y:::::::::y               T:::::T         r:::::r          a::::a    a:::::ac::::::c     ccccccce:::::::e            r:::::r            "
	@echo "RR:::::R     R:::::Ra::::a    a:::::a      y:::::::y              TT:::::::TT       r:::::r          a::::a    a:::::ac:::::::cccccc:::::ce::::::::e           r:::::r            "
	@echo "R::::::R     R:::::Ra:::::aaaa::::::a       y:::::y               T:::::::::T       r:::::r          a:::::aaaa::::::a c:::::::::::::::::c e::::::::eeeeeeee   r:::::r            "
	@echo "R::::::R     R:::::R a::::::::::aa:::a     y:::::y                T:::::::::T       r:::::r           a::::::::::aa:::a cc:::::::::::::::c  ee:::::::::::::e   r:::::r            "
	@echo "RRRRRRRR     RRRRRRR  aaaaaaaaaa  aaaa    y:::::y                 TTTTTTTTTTT       rrrrrrr            aaaaaaaaaa  aaaa   cccccccccccccccc    eeeeeeeeeeeeee   rrrrrrr            "
	@echo "                                         y:::::y                                                                                                                                  "
	@echo "                                        y:::::y                                                                                                                                   "
	@echo "                                       y:::::y                                                                                                                                    "
	@echo "                                      y:::::y                                                                                                                                     "
	@echo "                                     yyyyyyy                                                                                                                                      "
	@echo "by ATCHOUUUM"

%.o : %.c
	@make -C libft/
	@gcc -g -I libft/includes/  $(FLAG) -c $^

clean:
	@make -C libft/ clean
	@/bin/rm -rf $(OBJ)

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all

