/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:03:44 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:03:53 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	size_t		asize;
	t_stacks	*st;
	t_result	*rt;

	if ((argv = ft_read_cli_args(argc, argv)) == NULL)
		ft_ps_error(0, "Error\n");
	st = ft_init_t_stacks(ft_cli_arguments_array(argv, &asize), asize);
	ft_ps_error(ft_check_duplicate_int(st->arr, st->asize), "Error\n");
	rt = ft_pushswap_algo_control(st);
	ft_putstr(rt->op_list);
	ft_clean_t_stacks(&st);
	ft_clean_t_result(&rt);
	return (0);
}
