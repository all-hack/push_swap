/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 06:04:03 by obelange          #+#    #+#             */
/*   Updated: 2016/12/29 06:04:04 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int		ft_str_search_tokens(char const *s, char **c, size_t *endex)
{
	size_t	i;
	size_t	j;

	if (s && c && *c)
	{
		j = -1;
		while (c[++j] && *endex > 0)
		{
			if (ft_strncmp(s, c[j], *endex) == 0)
			{
				*endex = j;
				return (1);
			}
		}
		return (0);
	}
	return (-1);
}

size_t	validate_op_list(char *op_list, char **tokens, t_stacks *st, size_t i)
{
	size_t	endex;
	char	*(*op_ins[11])(int *arr, int *brr, size_t *asize, size_t *bsize);
	size_t	increment;

	op_ins[0] = ft_sa;
	op_ins[1] = ft_sb;
	op_ins[2] = ft_ss;
	op_ins[3] = ft_pa;
	op_ins[4] = ft_pb;
	op_ins[5] = ft_ra;
	op_ins[6] = ft_rb;
	op_ins[7] = ft_rr;
	op_ins[8] = ft_rra;
	op_ins[9] = ft_rrb;
	op_ins[10] = ft_rrr;
	while (ft_strchri(op_list, '\n', &endex))
	{
		increment = endex;
		if (ft_str_search_tokens(op_list, tokens, &endex))
			(*op_ins[endex])(st->arr, st->brr, &st->asize, &st->bsize);
		else
			ft_ps_error(0, "Error\n");
		op_list = op_list + increment + 1;
		i++;
	}
	return (i);
}

size_t	check_and_exec_op(char *op_list, t_stacks *st)
{
	char *tokens[12];

	tokens[0] = "sa\n";
	tokens[1] = "sb\n";
	tokens[2] = "ss\n";
	tokens[3] = "pa\n";
	tokens[4] = "pb\n";
	tokens[5] = "ra\n";
	tokens[6] = "rb\n";
	tokens[7] = "rr\n";
	tokens[8] = "rra\n";
	tokens[9] = "rrb\n";
	tokens[10] = "rrr\n";
	tokens[11] = 0;
	return (validate_op_list(op_list, tokens, st, 0));

}


int		main(int argc, char **argv)
{
	size_t		asize;
	size_t		true_size;
	size_t		ops;
	t_stacks	*st;
	char		*op_list;
	t_flags		*ft;

	
	ft = t_flags_init();
	if ((argv = ft_read_cli_args(argc, argv, ft, t_flags_checker_flags)) == NULL)
		ft_ps_error(0, "Error\n");
	st = ft_init_t_stacks(ft_cli_arguments_array(argv, &asize), asize);
	ft_ps_error(ft_check_duplicate_int(st->arr, st->asize), "Error\n");
	true_size = st->asize;
	op_list = ft_read_stdin();
	if (!ft_arr_sorted_asc(st->arr, st->asize))
	{
		if (!op_list)
		{
			ft_putstr("KO\n");
			exit(0);
		}
		ops = check_and_exec_op(op_list, st);
		if (ft_arr_sorted_asc(st->arr, true_size) && st->asize == true_size)
			ft_putstr("OK\n");
		else
			ft_putstr("KO\n");
		if (ft->flags[3] == 1)
		{
			ft_putstr("\x1b[32mnumber of instructions: ");
			ft_putnbr(ops);			
		}
	}
	else
		ft_putstr("OK\n");
	return (0);
}
