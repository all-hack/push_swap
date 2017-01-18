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


static int	t_flags_valid_loop(char *argv, int *argc, t_flags *ft)
{
	int	i;

	if (argv && ft)
	{
		i = -1;
		while (ft->valid_flags[++i])
		{
			// printf("%s <-> %s\n", argv, ft->valid_flags[i]);
			if (ft_strcmp(argv, ft->valid_flags[i]) == 0)
			{					
				(*argc)--;
				ft->flags[i] = 1;
				return (1);
			}
		}
	}
	return (0);
}


char	**t_flags_checker_flags(int	*argc, char **argv, t_flags *ft)
{
	// int	i;
	size_t	j;

	if (argv && argc)
	{	
		// printf("*argc: %d\n", *argc);
		
		// LIST0("flag[%ld]: %s\n", argv, argv)
		--(*argc);		

		// LIST0("flag[%ld]: %s\n", argv, argv)

		while (*argv++)
		{			
			// i = -1;
			// printf("aa: %s\n", *argv);
			if (*argv && ps_ssov_wrapper(*argv, "- 0123456789"))
			{
				if (ft_strchri(*argv, ' ', &j))
					return (ft_strsplit(argv[0], ' '));				
				else
					return(argv);
			}
			// printf("adfad\n");
			if (t_flags_valid_loop(*argv, argc, ft) == 0)
				ft_ps_error(0, "\x1b[31mError\nuse -help flag for usage information\n");
			if (ft->flags[0] == 1)
				ft_ps_error(0, "\x1b[33mUsage:\t./checker {-[flags]*} {[-0123456789*]*}\n---------------------------------------------------------\n\
\t-help: displays usage\n\
\t-stat: displays the number of operations run\n\
\t-list: displays the sorted list\n");
		}

		ft_ps_error(0, "\x1b[31mError\nuse -help flag for usage information\n");
	}
	return (NULL);
	// LIST0("flag[%ld]: %s\n", argv, argv)
}



char	**ft_read_cli_args(int argc, char **argv, t_flags *ft, char **(*flag_check)(int *, char **, t_flags*))
{
	argv = (*flag_check)(&argc, argv, ft);
	// printf("argc: %d\n", argc);
		
	
	if (argc >= 1)
		ft_ps_error(ft_check_valid_input(argv, "0123456789"), "Error\n");
	else
		exit(0);
	// printf("\n");
	// LIST0("argv[%ld]: %s\n", argv, argv)
	return (argv);
}

char	*ft_read_stdin(void)
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
