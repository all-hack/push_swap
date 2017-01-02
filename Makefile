# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: obelange <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 11:25:58 by obelange          #+#    #+#              #
#    Updated: 2016/10/22 17:26:22 by obelange         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = a.out

S_PATH = src/
B_PATH = build/
H_PATH = include/
LIBFT_PATH = libft

FILES = overlap ft_strsearch_ov

OBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(FILES)))
LIB_COMP = -L$(LIBFT_PATH) -lft -I$(LIBFT_PATH)

FLAGS = -Wall -Werror -Wextra

.PHONY: all fclean clean build libft.a run

all : $(NAME)

$(NAME) : build $(OBJ) libft.a
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP)

run : fclean build $(OBJ) libft.a
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP) && ./$(NAME)
	

libft.a : 
	@echo "compiling library...."
	@$(MAKE) -C $(LIBFT_PATH) all

build : 
	@mkdir build

$(B_PATH)%.o : $(S_PATH)%.c
	gcc -c $< -o $@ -I ./$(LIBFT_PATH)/$(H_PATH) -I ./$(H_PATH)

clean : 
	@rm -rf build
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean : clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all


