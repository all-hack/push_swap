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
	int		i;
	int		min;
	size_t	min_index;
	char	*op_list;

	op_list = NULL;
	if (!ft_arr_sorted(st->arr, st->asize))
	{
		while (st->asize > 1)
		{
			i = -1;
			min = st->arr[0];
			while (++i < st->asize)
				if (st->arr[i] < min)
					min = st->arr[i];
			while (min != st->arr[0])
				op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr,
													&st->asize, &st->bsize));
			op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr,
													&st->asize, &st->bsize));
		}
		while (st->bsize > 0)
			op_list = ft_fstrmcat(op_list, ft_pa(st->arr, st->brr,
													&st->asize, &st->bsize));
		return (op_list);
	}
	return (NULL);
}
