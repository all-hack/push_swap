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

int	*ft_mallocint(size_t size)
{
	int	*arr;

	if ((arr = (int*)malloc(sizeof(int) * size + 1)))
	{
		ft_bzero(arr, (size + 1) * sizeof(int));
		return (arr);
	}
	else
		ft_ps_error(0, "Malloc fail\n");
	return (0);
}

int	ft_convert_char_int(char *str)
{
	intmax_t	tmp;
	int			x;

	if (str[0] == '-')
		x = 11;
	else
		x = 10;
	if (ft_strlen(str) <= x)
	{
		tmp = ft_intmax_atoi(str);
		if (tmp > 2147483647 || tmp < -2147483648)
			ft_ps_error(0, "Error\n");
		return (tmp);
	}
	ft_ps_error(0, "Error\n");
	return (0);
}

int	*ft_cli_arguments_array(char **argv, size_t *size)
{
	intmax_t	i;
	int			*arr;

	if (argv && size)
	{
		*size = 0;
		while (argv[*size])
			(*size)++;
		NULL_GUARD(arr = ft_mallocint(*size));
		i = -1;
		while (++i < *size)
			arr[i] = ft_convert_char_int(argv[i]);
		return (arr);
	}
	return (NULL);
}
