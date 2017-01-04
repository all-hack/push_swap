/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:03:44 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:03:53 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"


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

	i = 0;
	j = 0;
	
	// while (argv[j])
	// 	printf("argd: %s\n", argv[j++]);
	
	if ((argv = ft_read_cli_args(argc, argv)) == NULL)
		ft_ps_error(0, "Error\n");

	st = ft_init_t_stacks(ft_cli_arguments_array(argv, &asize), asize);
	ft_ps_error(ft_check_duplicate_int(st->arr, st->asize), "Error\n");

	rt = ft_pushswap_algo_control(st);

	ft_putstr(rt->op_list);
	
	// LIST("st->arr[%ld]: %d\n", st, st->arr, st->asize)

	ft_clean_t_stacks(&st);
	ft_clean_t_result(&rt);
	// printf("st->asize: %zd\n", asize);
	// arr = ft_cli_arguments_array(argv, &asize);
	
	
	// brr = ft_bzero(ft_mallocint(asize), asize);
	// bsize = asize;

	// printf("rt: %p\n", rt);	
	// printf("rt->true_size: %ld\n", rt->true_size);
	
	

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





