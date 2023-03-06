# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmanouze <mmanouze@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/05 19:09:07 by mmanouze          #+#    #+#              #
#    Updated: 2023/03/05 19:28:27 by mmanouze         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADER_SRCS = 	Vector/enable_if.hpp\
				Vector/vector.hpp\
				stack/stack.hpp\
				map/map.hpp\
				map/pair/pair.hpp\
				map/map_iterator/iterator_traits_map.hpp\
				map/map_iterator/map_iterator.hpp\
				map/map_iterator/map_reverse_iterator.hpp\
				map/avl_tree/avl_tree.hpp\
				iterators/Iterator_traits.hpp\
				iterators/Iterator.hpp\
				iterators/reverse_Iterator.hpp\

CPP_SRCS = ./main.cpp

all : $(NAME)

$(NAME) : $(CPP_SRCS) $(HEADER_SRCS)
	$(CC) $(CFLAGS) $(CPP_SRCS) -o $(NAME)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : all fclean re
