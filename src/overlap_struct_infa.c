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

t_stacks	*ft_init_t_stacks(int *arr, size_t asize)
{
	t_stacks	*st;

	if (arr)
	{
		if ((st = (t_stacks*)malloc(sizeof(t_stacks))) == 0)
			ft_ps_error(0, "Malloc fail\n");
		st->arr = arr;
		st->brr = ft_mallocint(asize);
		st->asize = asize;
		st->bsize = 0;
		return (st);
	}
	return (NULL);
}

void		ft_clean_t_stacks(t_stacks **st)
{
	if (st && *st)
	{
		if ((*st)->arr)
			free((*st)->arr);
		if ((*st)->brr)
			free((*st)->brr);
		free(*st);
		*st = NULL;
	}
}

t_result	*ft_init_t_result(size_t true_size)
{
	t_result	*rt;

	if (true_size)
	{
		if ((rt = (t_result*)malloc(sizeof(t_result))) == 0)
			ft_ps_error(0, "Malloc fail\n");
		rt->true_sort = NULL;
		rt->true_size = true_size;
		rt->op_list = NULL;
		rt->op_count = 2147483647;
		rt->algo_index = -1;
		return (rt);
	}
	return (NULL);
}

void		ft_clean_t_result(t_result **rt)
{
	if (rt && *rt)
	{
		if ((*rt)->true_sort)
			free((*rt)->true_sort);
		if ((*rt)->op_list)
			free((*rt)->op_list);
		free((*rt));
		*rt = NULL;
	}
}
