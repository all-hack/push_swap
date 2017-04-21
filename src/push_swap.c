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
	t_flags		*ft;	
	
	ft = t_flags_init();
	if ((argv = ft_read_cli_args(argc, argv, ft, t_flags_checker_flags)) == NULL)
		ft_ps_error(0, "Error\n");
	
	st = ft_init_t_stacks(ft_cli_arguments_array(argv, &asize), asize);
	ft_ps_error(ft_check_duplicate_int(st->arr, st->asize), "Error\n");
	rt = ft_pushswap_algo_control(st);
	
	if (ft->flags[4] == 1)
	{
		asize = 0;
		ft_putstr("\x1b[32msorted list: ");
		while (asize < st->asize)
		{			
			ft_putnbr(st->arr[asize++]);
			ft_putstr(" ");
		}
		ft_putstr("\n");
	}
	if (ft->flags[3] == 1)
	{	
		ft_putstr("\x1b[32mnumber of instructions: ");
		ft_putnbr(rt->op_count);
		ft_putstr("\n");
	}
	if (ft->flags[5] == 1)
	{
		ft_putstr("\x1b[32msorted: ");
		if (ft_arr_sorted_asc(st->arr, st->asize))
			ft_putstr("True");
		else
			ft_putstr("False");		
		ft_putstr("\n");	
	}	

	ft_putstr(rt->op_list);

	ft_clean_t_stacks(&st);
	ft_clean_t_result(&rt);
	return (0);
}


