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

char	*op_algo_3_5sort(t_stacks *st, t_result *rt)
{
	char	*op_list;

	op_list = ft_strdup(ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
	op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
	if (!(st->arr[0] < st->arr[1] && st->arr[1] < st->arr[2] && st->arr[0] < st->arr[2]))
		op_list = ft_fstrmcat(op_list, op_algo_2_3sort(st, rt));
	if (st->brr[0] > st->brr[1])
		op_list = ft_fstrmcat(op_list, ft_sb(st->arr, st->brr, &st->asize, &st->bsize));
	while (st->bsize != 0)
	{
		if (st->brr[0] < st->arr[0])
			op_list = ft_fstrmcat(op_list, ft_pa(st->arr, st->brr, &st->asize, &st->bsize));
		else if (ft_find_big(st->arr, st->asize) == 0 && st->brr[0] > st->arr[0])
		{
			op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
			op_list = ft_fstrmcat(op_list, ft_pa(st->arr, st->brr, &st->asize, &st->bsize));
		}
		else
			op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
	}	
	while (ft_find_small(st->arr, st->asize) != 0)		
		op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
	return (op_list);
}
