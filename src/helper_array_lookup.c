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

int	ft_find_big(int *arr, size_t size)
{
	int largest;
	int i;
	int index;

	i = 0;
	largest = arr[i];
	index = i;
	while (++i < size)
	{
		if (arr[i] > largest)
		{
			largest = arr[i];
			index = i;
		}
	}
	return (index);
}

int	ft_find_small(int *arr, size_t size)
{
	int smallest;
	int i;
	int index;

	i = 0;
	smallest = arr[i];
	index = i;
	while (++i < size)
	{
		if (arr[i] < smallest)
		{
			smallest = arr[i];
			index = i;
		}
	}
	return (index);
}

int	ft_find_value(int *arr, size_t size, int value)
{
	int i;
	int index;

	i = 0;
	index = i;
	while (i < size)
	{
		if (arr[i] == value)
		{
			return(i);
		}
		i++;
	}
	return (-1);
}




