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


char	*merge_stack_b_to_a(t_stacks *st, char *op_list)
{
	int i;

	// printf("merging\n");
	// LIST2("merging", "arr: ", "%d, ", "", st, st->arr, st->asize)
	// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
	i = 0;
	while (st->bsize > 0)
	{
		i++;
		while (st->brr[0] < st->arr[st->asize - 1])
		{
			i++;
			op_list = ft_fstrmcat(op_list, ft_rra(st->arr, st->brr, &st->asize, &st->bsize));	
		}
		
		op_list = ft_fstrmcat(op_list, ft_pa(st->arr, st->brr, &st->asize, &st->bsize));
		// printf("\nasize: %d, bsize: %d", st->asize, st->bsize);
		// LIST1("arr: ", "%d, ", "", st, st->arr, st->asize)
		// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
	}
	while (i-- > 0)
	{
		op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
		// printf("%d-> op_list: %s\n", (*y)++, op_list);	
	}
	return (op_list);
}


char	*place_in_desc_stack(t_stacks *st, char *op_list, int *high, size_t *y)
{
	int num;
	int i;
	int lowb;

	num = st->arr[0];
	lowb = st->brr[st->bsize - 1];
	i = 1;
	// printf("starting desc loop\n");
	// LIST2("\n\nstarting desc loop", "arr: ", "%d, ", "", st, st->arr, st->asize)
	// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
	// printf("*high: %d\n", *high);
	if (num >= *high)
	{
		*high = num;
		return (op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize)));
	}
	else if (num < lowb)
	{
		op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
		op_list = ft_fstrmcat(op_list, ft_rb(st->arr, st->brr, &st->asize, &st->bsize));
	}
	else
	{		
		op_list = ft_fstrmcat(op_list, ft_rb(st->arr, st->brr, &st->asize, &st->bsize));
		while (num < st->brr[0] && st->brr[0] != *high)
		{
			// printf("*high: %d\n", *high);
			// LIST2("\n\ni increasing", "arr: ", "%d, ", "", st, st->arr, st->asize)
			// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
			i++;
			op_list = ft_fstrmcat(op_list, ft_rb(st->arr, st->brr, &st->asize, &st->bsize));			
			// LIST2("i2 increasing", "arr: ", "%d, ", "", st, st->arr, st->asize)
			// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)

		}
		op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
		while (i-- > 0)
		{
			op_list = ft_fstrmcat(op_list, ft_rrb(st->arr, st->brr, &st->asize, &st->bsize));
			// printf("%d-> op_list: %s\n", (*y)++, op_list);	
		}
	}	
		

	// LIST2("\n\nexit desc loop", "arr: ", "%d, ", "", st, st->arr, st->asize)
	// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)

	return (op_list);
}

char	*place_in_asc_stack(t_stacks *st, char *op_list, int *low, size_t *y)
{
	int	num;
	int	i;
	size_t low_index;

	
	num = st->arr[0];

	// printf("starting asc loop\n");	
	// LIST2("\n\nstarting asc loop", "arr: ", "%d, ", "", st, st->arr, st->asize)
	// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
	


	if (num == *low)
	{
		return (op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize)));
	}	
	else if (ft_find_value(st->arr, st->asize, *low) == -1 && num < *low)
	{
		*low = num;
		return (op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize)));
	}
	else if (num > st->arr[st->asize - 1])
		return (op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize)));
	else
		op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));		


	// LIST2("\n\ndirty", "arr: ", "%d, ", "", st, st->arr, st->asize)
	// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)

	i = 1;
	while (num < st->arr[st->asize - 1] && st->arr[0] != *low)
	{
		// printf("low: %d\n", *low);
		// LIST2("\n\ni increasing", "arr: ", "%d, ", "", st, st->arr, st->asize)
		// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
		i++;
		op_list = ft_fstrmcat(op_list, ft_rra(st->arr, st->brr, &st->asize, &st->bsize));		
		// LIST2("i2 increasing", "arr: ", "%d, ", "", st, st->arr, st->asize)
		// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
	}
	if (st->asize == 2 && (num < st->arr[st->asize - 1] && st->arr[0] == *low))
	{
		i++;
		op_list = ft_fstrmcat(op_list, ft_rra(st->arr, st->brr, &st->asize, &st->bsize));
	}
	if (num < st->arr[st->asize - 1] && num > st->arr[0])
		op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
	// printf("i: %d\n", i);
	op_list = ft_fstrmcat(op_list, ft_pa(st->arr, st->brr, &st->asize, &st->bsize));
	// printf("%d-> op_list: %s\n", (*y)++, op_list);	
	while (i-- > 0)
	{

		op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
		// printf("%d-> op_list: %s\n", (*y)++, op_list);	
	}

	if (num < *low)
		*low = num;

	// LIST2("\n\nexit asc loop", "arr: ", "%d, ", "", st, st->arr, st->asize)
	// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
	
	return (op_list);
}

char	*op_algo_1_stackmerge(t_stacks *st, t_result *rt)
{
	size_t	i;
	int		low;
	int		high;
	int 	pivot;
	char	*op_list;
	int		*y;
	int 	j;

	j = 0;
	y = &j;
	i = 0;	
	op_list = NULL;
	// printf("%ld --> low: %d, high: %d, pivot: %d, \n", y++, low, high, pivot);
	// LIST1("arr: ", "%d, ", "", st, st->arr, st->asize)
	// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)

	// if (!ft_arr_sorted_asc(st->arr, st->asize))
	
	// op_list = ft_fstrmcat(op_list, ft_ra(st->arr, st->brr, &st->asize, &st->bsize));
	
	// printf("%ld-> op_list: %s\n", (*y)++, op_list);	
	// printf("fufy\n");
	if (!(ft_arr_sorted_asc(st->arr, st->asize) && st->bsize == 0))
	{
		// high = st- >arr[ft_find_big(st->arr, st->asize)];
		// low = st-> arr[ft_find_small(st->arr, st->asize)];
		
		high = st->arr[0];
		low = st->arr[0];

		pivot = low + ((high - low) / 2);
		op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
		// printf("%ld --> low: %d, high: %d, pivot: %d, \n", y++, low, high, pivot);
		// op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));

		while (!(ft_arr_sorted_asc(st->arr, st->asize) && st->bsize == 0))
		{
			
			// op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));

			
			
			// LIST1("arr: ", "%d, ", "", st, st->arr, st->asize)
			// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)

			// if (st->arr[0] > pivot)
			// {
			// 	high = st->arr[0];
			// 	pivot = low + ((high - low) / 2);
			// 	op_list = ft_fstrmcat(op_list, ft_pb(st->arr, st->brr, &st->asize, &st->bsize));
			// }
			// else
			// {
			// 	low = st->arr[0];
			// 	pivot = low + ((high - low) / 2);
			// 	op_list = ft_fstrmcat(op_list, ft_rra(st->arr, st->brr, &st->asize, &st->bsize));
			// }
			
			// printf("01 --> low: %d, high: %d, pivot: %d, \n", low, high, pivot);
			// LIST1("arr: ", "%d, ", "", st, st->arr, st->asize)
			// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)

			// if (st->arr[0] < pivot)
			// {
			// 	place_in_asc_stack(st, op_list, &low);
			// 	pivot = low + ((high - low) / 2);
			// }

			// printf("\n%ld --> low: %d, high: %d, pivot: %d", y++, low, high, pivot);
			// LIST1("arr: ", "%d, ", "", st, st->arr, st->asize)
			// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)

			// op_list = place_in_asc_stack(st, op_list, &low, y);
			// op_list = place_in_desc_stack(st, op_list, &low, y);
			
						
			// if (ft_arr_sorted_asc(st->arr, st->asize) && st->bsize == 0)
			
			if (st->arr[0] > pivot)
				op_list = place_in_desc_stack(st, op_list, &high, y);
			else if (st->arr[0] <= pivot)
				op_list = place_in_asc_stack(st, op_list, &low, y);			

			pivot = low + ((high - low) / 2);
			// printf("\n%ld --> low: %d, high: %d, pivot: %d", y++, low, high, pivot);
			// LIST1("arr: ", "%d, ", "", st, st->arr, st->asize)
			// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
			
			if (ft_arr_sorted_asc(st->arr, st->asize) && ft_arr_sorted_desc(st->brr, st->bsize))
				return (merge_stack_b_to_a(st, op_list));				
		}
		// printf("aoihpa\n");
		// printf("\n%ld --> low: %d, high: %d, pivot: %d", y++, low, high, pivot);
		// LIST2("merge ready", "arr: ", "%d, ", "", st, st->arr, st->asize)
		// LIST1("brr: ", "%d, ", "\n\n", st, st->brr, st->bsize)
		

	}



	return (ft_strdup(""));
}
