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

int		*ft_intcpy(int *dst, int *src, size_t n)
{
	size_t i;

	if (n > 0)
	{
		i = 0;
		while (i <= n)
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}

int		ft_arr_sorted(int *arr, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 1)
	{
		while (i < size - 1)
			if (arr[i] > arr[i++ + 1])
				return (0);
	}
	return (1);
}
