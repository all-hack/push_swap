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

t_algo	*ft_init_t_algo(void)
{
	t_algo	*at;

	if ((at = (t_algo*)malloc(sizeof(t_algo))) == 0)
		ft_ps_error(0, "Malloc fail\n");
	at->algo_op[0] = op_algo_0_bubble;
	at->algo_op[1] = op_algo_1_pathsort;
	at->algo_op[2] = op_algo_2_3sort;
	at->algo_op[3] = op_algo_3_5sort;
	at->algo_op[4] = NULL;
	at->algo_names[0] = "bubble sort";
	at->algo_names[1] = "path sort";
	at->algo_names[2] = "3sort";
	at->algo_names[3] = "5sort";
	at->algo_condition[0] = op_condition_0_less4;	
	at->algo_condition[1] = op_condition_1_less6;
	at->algo_condition[2] = op_condition_2_more6;
	at->algo_condition[3] = 0;
	at->algo_op_end = 4;
	at->algo_condition_end = 3;
	return (at);
}

void	ft_clean_t_algo(t_algo **at)
{
	if (at && *at)
	{
		free((*at));
		*at = NULL;
	}
}
