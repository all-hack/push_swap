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

char	*op_algo_2_3sort(t_stacks *st, t_result *rt)
{
	char	*op_list;

	op_list = NULL;
	if (st->arr[0] > st->arr[1] && st->arr[1] > st->arr[2])
	{
		op_list = ft_fstrmcat(op_list, ft_sa(st->arr, st->brr, &st->asize, &st->bsize));
		op_list = ft_fstrmcat(op_list, ft_rra(st->arr, st->brr, &st->asize, &st->bsize));
	}
	else if (st->arr[0] > st->arr[1] && st->arr[1] < st->arr[2] && st->arr[0] > st->arr[2])
		op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));	
	else if (st->arr[0] > st->arr[1] && st->arr[1] < st->arr[2] && st->arr[0] < st->arr[2])
		op_list = ft_fstrmcat(op_list, ft_sa(st->arr, st->brr, &st->asize, &st->bsize));
	else if (st->arr[0] < st->arr[1] && st->arr[1] > st->arr[2])
	{
		op_list = ft_fstrmcat(op_list, ft_rra(st->arr, st->brr, &st->asize, &st->bsize));
		if (st->arr[0] > st->arr[1])
			op_list = ft_fstrmcat(op_list, ft_sa(st->arr, st->brr, &st->asize, &st->bsize));
	}
	return (op_list);
}
