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

char	**ft_read_cli_args(int argc, char **argv)
{
	if (argc == 2)	
		argv = ft_strsplit(argv[1], ' ');
	else
		argv++;
	if (argc > 1)
		ft_ps_error(ft_check_valid_input(argv, "0123456789"), "Error\n");	
	else
		exit(0);
	return (argv);
}
