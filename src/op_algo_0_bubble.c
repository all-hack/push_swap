/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   overlap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:03:35 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:03:38 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

char	*op_algo_0_bubble(t_stacks *st, t_result *rt)
{
	size_t	i;
	int 	min;
	size_t	min_index;	
	char	*op_list;

	// printf("start\n");
	op_list = NULL;
	if (!ft_arr_sorted(st->arr, st->asize))
	{
		while (st->asize > 1)
		{
			i = 0;
			min = st->arr[0];
			// printf("st->asize: %d, min: %d\n", st->asize, min);
			while (i < st->asize)
			{
				// printf("i: %d\n", i);
				if (st->arr[i] < min)
				{
					min = st->arr[i];
					// printf("i: %d, min: %d\n", i, min);
				}
				i++;
			}
			// printf("rotating\n");
			while (min != st->arr[0])
			{				
				op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->asize));
				// printf("min: %d, st->arr[0]: %d, st->asize: %d,\n", min, st->arr[0], st->asize);
			}
			// printf("pushing st->arr[0]: %d\n", st->arr[0]);
			op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
			// ft_push(st->brr, st->arr, &st->bsize, &st->asize);		
			// printf("pushed\n");
		}
		
		while (st->bsize > 0)
		{
			// printf("pre st->bsize: %d, st->brr[0]: %d\n", st->bsize, st->brr[0]);
			op_list = ft_fstrmcat(op_list, ft_pa(st->arr, st->brr, &st->asize, &st->bsize));			
			// printf("pos st->bsize: %d, st->brr[0]: %d\n\n\n", st->bsize, st->brr[0]);
		}
		// printf("sorted\n");
		// printf("op_listL: %s\n", op_list);		
		// printf("algo op op_list pointer: %p\n", op_list);
		return (op_list);
	}
	return (NULL);
}


