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

void	ft_rotate1(int	*array, size_t size)
{	
	size_t	i;	

	i = 0;
	if (size > 1)
		while (i++ < size - 1)
			ft_swap1(array++, size);
}

void	ft_rotate2(int	*arr, int	*brr, size_t asize, size_t bsize)
{
	ft_rotate1(arr, asize);
	ft_rotate1(brr, bsize);
}

void	ft_revrotate1(int	*array, size_t size)
{
	int		tmp;
	size_t	i;	

	i = 1;
	if (size > 1)
		while (i++ < size)
			ft_swap1((array + (size - i)), size);
}

void	ft_revrotate2(int	*arr, int	*brr, size_t asize, size_t bsize)
{
	ft_revrotate1(arr, asize);
	ft_revrotate1(brr, bsize);
}
