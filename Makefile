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


PUSHSWAP = push_swap
CHECKER = checker

# NAME = push_swap

S_PATH = src/
B_PATH = build/
H_PATH = include/
LIBFT_PATH = libft

FILES = ft_strsearch_ov 

FILES += overlap_allocation overlap_ps_operations_rot overlap_error \
overlap_ps_operations_ps overlap_validity overlap_struct_infa \
overlap_ps_operations_wrappers

FILES += algo_truesort_merge algo_truesort_stackmerge

FILES += algo_struct_infa algo_pushswap_control

FILES += op_conditions_set_0

FILES += helper_array helper_op_list helper_cli

FILES += op_algo_0_bubble

PFILES += $(FILES) push_swap
CFILES += $(FILES) checker


OBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(FILES)))
POBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(PFILES)))
COBJ = $(addprefix $(B_PATH), $(addsuffix .o, $(CFILES)))

LIB_COMP = -L$(LIBFT_PATH) -lft -I$(LIBFT_PATH)

FLAGS = -Wall -Werror -Wextra
DEVF = $(FLAGS) -fsanitize=address
LEAKF = $(FLAGS) $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl

ifdef ALLOCWRAP
	C_FLAGS += $(HOME)/Desktop/offence/tools/alloc_wrap.c -ldl
endif 

.PHONY: all fclean clean build libft.a run

all : $(PUSHSWAP) $(CHECKER)

$(PUSHSWAP) : build $(POBJ) libft.a
	gcc $(FLAGS) -o $(PUSHSWAP) $(POBJ) $(LIB_COMP)

$(CHECKER) : build $(COBJ) libft.a
	gcc $(FLAGS) -o $(CHECKER) $(COBJ) $(LIB_COMP)

$(NAME) : build $(OBJ) libft.a
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP)

run : fclean build $(OBJ) libft.a
	@gcc $(FLAGS) -o $(NAME) $(OBJ) $(LIB_COMP)

dev : fclean build $(OBJ) libft.a
	gcc $(DEVF) -o $(NAME) $(OBJ) $(LIB_COMP)

leak : fclean build $(OBJ) libft.a
	gcc $(LEAKF) -o $(NAME) $(OBJ) $(LIB_COMP)

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
	@rm -f $(PUSHSWAP) $(CHECKER)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re : fclean all


