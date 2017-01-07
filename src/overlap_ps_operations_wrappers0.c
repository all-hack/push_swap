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

char	*ft_sa(int *arr, int *brr, size_t *asize, size_t *bsize)
{
	ft_swap1(arr, *asize);
	return ("sa\n");
}

char	*ft_sb(int *arr, int *brr, size_t *asize, size_t *bsize)
{
	ft_swap1(brr, *bsize);
	return ("sb\n");
}

char	*ft_ss(int *arr, int *brr, size_t *asize, size_t *bsize)
{
	ft_swap2(arr, brr, *asize, *bsize);
	return ("ss\n");
}

char	*ft_pa(int *arr, int *brr, size_t *asize, size_t *bsize)
{
	ft_push(arr, brr, asize, bsize);
	return ("pa\n");
}

char	*ft_pb(int *arr, int *brr, size_t *asize, size_t *bsize)
{
	ft_push(brr, arr, bsize, asize);
	return ("pb\n");
}
