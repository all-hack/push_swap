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

void	ft_swap1(int	*array, size_t size)
{
	int	tmp;

	if (size > 1)
	{
		tmp = array[0];
		array[0] = array[1];
		array[1] = tmp;
	}
}

void	ft_swap2(int	*arr, int	*brr, size_t asize, size_t bsize)
{
	ft_swap1(arr, asize);
	ft_swap1(brr, bsize);
}

void	ft_push(int	*array1, int *array2, size_t *size1, size_t *size2)
{

	if (*size2 > 0)
	{
		ft_revrotate1(array1, ++(*size1));
		array1[0] = array2[0];
		array2[0] = 0;
		ft_rotate1(array2, (*size2)--);
	}
}
