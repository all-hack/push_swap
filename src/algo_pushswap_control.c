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

t_result	*ft_pushswap_algo_control(t_stacks *st)
{
	t_result	*rt;
	t_algo		*at;
	int			i;
	int			algo_index;

	rt = ft_init_t_result(st->asize);
	at = ft_init_t_algo();
	i = -1;
	while (at->algo_condition[++i])
	{

		algo_index = at->algo_condition[i](st, rt, at->algo_op_end);		
		if (algo_index != at->algo_op_end)
		{
			if (at->algo_op[algo_index])			
				rt->op_list =
					ft_check_op_count(rt, at->algo_op[algo_index](st, rt), &(rt->op_count));
			break;
		}
		
		
		// printf("op_list[%d]: \n%s\n", algo_index, rt->op_list);
	}
	if (!rt->op_list)
		rt->op_list =
			ft_check_op_count(rt, at->algo_op[0](st, rt), &(rt->op_count));
	ft_clean_t_algo(&at);
	return (rt);
}
