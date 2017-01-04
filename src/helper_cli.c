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

char	*ft_read_stdin()
{	
	char	buff[BUFFSIZE];
	int		rec;
	char	*op_list;

	op_list = NULL;
	ft_bzero(buff, BUFFSIZE);
	while ((read(0, buff, BUFFSIZE) > 0))
	{		
		op_list = ft_fstrmcat(op_list, buff);
		ft_bzero(buff, BUFFSIZE);
	}	
	return (op_list);
}
