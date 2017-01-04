/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:04:03 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:04:04 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"




// ft_sa
// ft_sb
// ft_ss
// ft_pa
// ft_pb
// ft_ra
// ft_rb
// ft_rr
// ft_rra
// ft_rrb
// ft_rrr

int	ft_str_search_tokens(char const *s, char **c, size_t *index)
{
	size_t	i;
	size_t	j;

	if (s && c && *c)
	{		
		// printf("s: %s\n", s);
		// printf("s: %d\n", s[3]);

		j = -1;
		while (c[++j])
		{
			// printf("adfhoafh\n");
			if (ft_strcmp(s, c[j]) == 0)
			{
				// printf("c[%d]: %s\n", j, c[j]);
				*index = j;
				return (1);
			}
		}
		return (0);
	}	
	return (-1);
}

void	init_op_instruction(char	**(*op_instruction))
{
	// char	*(*algo_condition[11]) (int	*arr, int *brr, size_t asize, size_t bsize);


	
}

void	validate_op_list(char *op_list, char **tokens, char delim, char	*(*op_instruction))
{
	// char **split_op;	
	// split_op = ft_strsplit(op_list, delim);
	size_t	end;	
	// size_t	start;	

	// start = 0;	
	printf("function: %p\n", op_instruction);	

	while (ft_strchri(op_list, '\n', &end))
	{
		if (ft_str_search_tokens(op_list, tokens, &end))
			printf("end: %ld\n", end);		
	}


	// int i = 0;
	// while (split_op[i])
	// 	printf("split_op: %s\n", split_op[i++]);
	
	// LIST0("split_op[%d]: %s\n", split_op, split_op)



}



void	init_op_tokens(char *op_list)
{
	char *tokens[12];
	char	*(*op_instruction[11])(int	*arr, int *brr, size_t asize, size_t bsize);

	op_instruction[0] = ft_sa;
	op_instruction[1] = ft_sb;
	op_instruction[2] = ft_ss;
	op_instruction[3] = ft_pa;
	op_instruction[4] = ft_pb;
	op_instruction[5] = ft_ra;
	op_instruction[6] = ft_rb;
	op_instruction[7] = ft_rr;
	op_instruction[8] = ft_rra;
	op_instruction[9] = ft_rrb;
	op_instruction[10] = ft_rrr;

	tokens[0] = "sa\n";
	tokens[1] = "sb\n";
	tokens[2] = "ss\n";
	tokens[3] = "pa\n";
	tokens[4] = "pb\n";
	tokens[5] = "ra\n";
	tokens[6] = "rb\n";
	tokens[7] = "rr\n";
	tokens[8] = "rra\n";
	tokens[9] = "rrb\n";
	tokens[10] = "rrr\n";
	tokens[11] = 0;

	// op_instruction = NULL;
	validate_op_list(op_list, tokens, '\n', op_instruction);
}


int main(int argc, char **argv)
{
	size_t	asize;
	// size_t	bsize;
	// int		*arr;
	// int		*brr;
	size_t	i;
	size_t	j;
	t_stacks	*st;
	t_result	*rt;
	char	*op_list;	

	i = 0;
	j = 0;
	
	// while (argv[j])
	// 	printf("argd: %s\n", argv[j++]);
	


	// if ((argv = ft_read_cli_args(argc, argv)) == NULL)
	// 	ft_ps_error(0, "Error\n");

	// st = ft_init_t_stacks(ft_cli_arguments_array(argv, &asize), asize);
	// ft_ps_error(ft_check_duplicate_int(st->arr, st->asize), "Error\n");



	op_list = ft_read_stdin();
	init_op_tokens(op_list);


	// printf("st->asize: %zd\n", asize);
	// arr = ft_cli_arguments_array(argv, &asize);
	
	
	// brr = ft_bzero(ft_mallocint(asize), asize);
	// bsize = asize;

	// printf("rt: %p\n", rt);	
	// printf("rt->true_size: %ld\n", rt->true_size);
	
	// LIST("st->arr[%ld]: %d\n", st, st->arr, st->asize)

	// printf("\nop_list: \n%s\n\n", rt->op_list);
	// printf("\nop_count: %ld\n\n", rt->op_count);

	// i = 0;
	// while (rt && i < rt->true_size)
	// 	printf("rt->true_sort[%ld]: %d\n", i, rt->true_sort[i++]);

	// printf("opcount: %zd\n", rt->op_count);
	// i = 0;
	// while (i < st->asize)
	// 	printf("int brr[%ld]: %d\n", i, st->brr[i++]);
	
	// int array1[7] = {1, 6, 4, 9, 3, 8, 0};
	// int array2[4] = {5, 5, 5, 0};
	// asize = 6;
	// bsize = 3;
	
	// i = 0;
	// printf("asize: %ld\n", asize);
	// while (i < asize)
	// 	printf("array1[%ld]: %d\n", i, array1[i++]);
	
	// printf("\n");
	// i = 0;
	// printf("bsize: %ld\n", bsize);
	// while (i < bsize)
	// 	printf("array2[%ld]: %d\n", i, array2[i++]);

	// ft_push(array1, array2, &asize, &bsize);

	// i = 0;
	// printf("asize: %ld\n", asize);
	// while (i < asize)
	// 	printf("array1[%ld]: %d\n", i, array1[i++]);
	
	// printf("\n");
	// i = 0;
	// printf("bsize: %ld\n", bsize);
	// while (i < bsize)
	// 	printf("array2[%ld]: %d\n", i, array2[i++]);
	

	// printf("input valid\n");
	// printf("return: %d\n", ft_check_valid_input(argv, "0123456789"));
	// ft_cli_arguments_array(argv, j);

	return (0);

}