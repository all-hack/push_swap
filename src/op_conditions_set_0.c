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

int		op_condition_0_less4(t_stacks *st, t_result *rt, int algo_op_end)
{
	if (st->asize < 4)
		return (1);
	else
		return (algo_op_end);
}

int		op_condition_1_less6(t_stacks *st, t_result *rt, int algo_op_end)
{
	if (st->asize < 6)
		return (0);
	else
		return (algo_op_end);
}
