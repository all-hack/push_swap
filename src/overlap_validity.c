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

int	ps_ssov_wrapper(char const *s, char const *c)
{
	if (s && c)
	{		
		if (s[0] == '-')
			return (ft_strsearch_ov(++s, c));
		else
			return (ft_strsearch_ov(s, c));
	}
	return (-1);
}

int	ft_check_valid_input(char **argv, char *valid_char)
{
	if (argv && *argv)
	{
		while (*argv)
			if (ps_ssov_wrapper(*argv++, valid_char) == 0)
				return (0);
		return (1);		
	}
	return (-1);
}

/*
** a static helper function for ft_check duplicate_int
*/
static	int	recursive_loop(int a, int *arr, size_t size)
{
	size_t i;

	if (arr)
	{
		i = 0;
		while (i < size)
			if (a == arr[i++])
				return (1);
		return (0);
	}
	return (-1);
}

int ft_check_duplicate_int(int	*arr, size_t size)
{
	int	*i;

	if (arr)
	{
		i = arr + size - 1;
		while (arr++ < i)
		{			
			if (recursive_loop(*(arr - 1), arr, --size))
				return (0);
		}
		return (1);
	}
	return (-1);
}
