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

char	*ft_sa(int	*arr, size_t size)
{
	ft_swap1(arr, size);
	return ("sa\n");
}

char	*ft_sb(int	*brr, size_t size)
{
	ft_swap1(brr, size);
	return ("sb\n");
}

char	*ft_ss(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_swap2(arr, brr, asize, bsize);
	return ("ss\n");
}

char	*ft_pa(int	*arr, int *brr, size_t *asize, size_t *bsize)
{
	ft_push(arr, brr, asize, bsize);
	return ("pa\n");
}

char	*ft_pb(int	*arr, int *brr, size_t *asize, size_t *bsize)
{
	ft_push(brr, arr, bsize, asize);
	return ("pb\n");
}


char	*ft_ra(int	*arr, size_t size)
{
	ft_rotate1(arr, size);
	return ("ra\n");
}

char	*ft_rb(int	*brr, size_t size)
{
	ft_rotate1(brr, size);
	return ("rb\n");
}

char	*ft_rra(int	*arr, size_t size)
{
	ft_revrotate1(arr, size);
	return ("rra\n");
}

char	*ft_rrb(int	*brr, size_t size)
{
	ft_revrotate1(brr, size);
	return ("rrb\n");
}

char	*ft_rr(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_rotate2(arr, brr, asize, bsize);
	return ("rr\n");
}

char	*ft_rrr(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_revrotate2(arr, brr, asize, bsize);
	return ("rrr\n");
}

