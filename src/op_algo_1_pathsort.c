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




int		rotate_push(t_stacks *st, int index)
{
	if (st->asize - index < index)
		return (st->asize - index) * -1;
	else
		return (index);
}

int		find_spot(t_stacks *st, int num)
{
	int	maxi;
	int mini;
	int max;
	int min;
	int i;

	mini = ft_find_small(st->brr, st->bsize);
	maxi = ft_find_big(st->brr, st->bsize);
	min = st->brr[mini];
	max = st->brr[maxi];

	if (num >= max)
		return (maxi);
	if (num <= min)
		return (mini + 1);

	i = -1;
	if (maxi == 0)
	{	
		while (++i < st->bsize)
			if (st->brr[i] < num)
				return (i);
		return (st->bsize);
	}

	while (maxi < st->bsize)
	{
		if (st->brr[maxi] < num)
			return (maxi);
		maxi += 1;
	}

	while (++i <= mini)
		if (st->brr[i] < num)
			return (i);
	return (0);
}

int	rotate_spot(t_stacks *st, int num)
{
	int spot;

	spot = find_spot(st, num);

	if (st->bsize - spot == 0)
		return (0);
	else if (st->bsize - spot < spot)
		return (spot - st->bsize);
	return (spot);
}

static	int		ut_abs_itoa(int x)
{	
	if (x < 0)
		return (x * -1);
	return (x);
}


int	rotate_db_path(int rot_push, int rot_spot)
{
	// printf("rotate_db_path\n");
	if ((rot_push > 0 && rot_spot > 0) || (rot_push < 0 && rot_spot < 0))
	{
		// printf("(rot_push > 0 && rot_spot > 0) || (rot_push < 0 && rot_spot < 0)\n");
		if (ut_abs_itoa(rot_push) >= ut_abs_itoa(rot_spot))
		{
			// printf("ut_abs_itoa push: %d\n", ut_abs_itoa(rot_push));
			return (1 + ut_abs_itoa(rot_push));
		}
		else
		{
			return (1 + ut_abs_itoa(rot_spot));
		}
	}
	else
	{
		// printf("else\n");
		return (1 + ut_abs_itoa(rot_push) + ut_abs_itoa(rot_spot));
	}
}

char	*prep_stack_push(t_stacks *st, int rot_push, int rot_spot, char *op_list)
{
	while (rot_push != 0 || rot_spot != 0)
	{
		if (rot_push > 0 && rot_spot > 0)
		{
            op_list = ft_fstrmcat(op_list, ft_rr(st->arr, st->brr, &st->asize, &st->bsize));
            rot_push -= 1;
            rot_spot -= 1;
        }
        else if(rot_push < 0 && rot_spot < 0)
        {
            op_list = ft_fstrmcat(op_list, ft_rrr(st->arr, st->brr, &st->asize, &st->bsize));
            rot_push += 1;
            rot_spot += 1;
		}
        if (rot_push > 0 && (rot_push -= 1))
            op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
        else if (rot_push < 0 && (rot_push += 1))
            op_list = ft_fstrmcat(op_list, ft_rra(st->arr, st->brr, &st->asize, &st->bsize));
        if (rot_spot > 0 && (rot_spot -= 1))
        	op_list = ft_fstrmcat(op_list, ft_rb(st->arr, st->brr, &st->asize, &st->bsize));
        else if (rot_spot < 0 && (rot_spot += 1))
            op_list = ft_fstrmcat(op_list, ft_rrb(st->arr, st->brr, &st->asize, &st->bsize));
	}
	return (op_list);
}


void	path_sort(t_stacks *st, char *op_list, int *short_index, int *short_value)
{
	int	min;
	int	max;
	int	i;
	int	total;

	i = -1;
	min = st->brr[ft_find_small(st->brr, st->bsize)];
	max = st->brr[ft_find_big(st->brr, st->bsize)];
	
	// printf("path_sort\n\n");
	while (++i < st->asize)
	{
		// printf("path_sort, st->asize: %d\n", st->asize);
		total = rotate_db_path(rotate_push(st, i), rotate_spot(st, st->arr[i]));
		// printf("path_sort, total: %d\n", total);
		if (total < *short_value)
		{
			*short_value = total;
			*short_index = i;
		}
	}
}





char	*op_algo_1_pathsort(t_stacks *st, t_result *rt)
{
	char	*op_list;
	int		short_index;
	int		short_value;
	int		max;
	
	// printf("run\n");


	op_list = ft_strdup(ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
	
	// printf("op_algo_1_pathsort 0\n");
	
	while (st->asize > 0)
	{
		// printf("outer, st->asize: %d\n", st->asize);
		short_index = 0;
    	short_value = 2147483647;
    	path_sort(st, op_list, &short_index, &short_value);
   
    	op_list = prep_stack_push(st, rotate_push(st, short_index), rotate_spot(st, st->arr[short_index]), op_list);
    	op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
	}

	// printf("st->asize: %d\n", st->asize);
	// printf("st->bsize: %d\n", st->bsize);

	max = st->brr[ft_find_big(st->brr, st->bsize)];
	// printf("max(b): %d\n");
	

	if (st->bsize / 2 > ft_find_big(st->brr, st->bsize))
		while (st->brr[0] != max)
			op_list = ft_fstrmcat(op_list, ft_rb(st->arr, st->brr, &st->asize, &st->bsize));
	else
		while (st->brr[0] != max)
			op_list = ft_fstrmcat(op_list, ft_rrb(st->arr, st->brr, &st->asize, &st->bsize));	

	while (st->bsize > 0)
		op_list = ft_fstrmcat(op_list, ft_pa(st->arr, st->brr, &st->asize, &st->bsize));

	return (op_list);
}
















