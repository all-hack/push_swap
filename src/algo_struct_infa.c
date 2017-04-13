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
	at->algo_op[1] = op_algo_1_stackmerge;
	at->algo_op[2] = NULL;
	at->algo_names[0] = "bubble sort";
	at->algo_names[1] = "stack merge";
	at->algo_condition[0] = op_condition_0_less4;
	at->algo_condition[1] = 0;
	at->algo_op_end = 0;
	at->algo_condition_end = 2;
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
