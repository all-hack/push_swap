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

char	*ft_sa(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_swap1(arr, asize);
	return ("sa\n");
}

char	*ft_sb(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_swap1(brr, bsize);
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


char	*ft_ra(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_rotate1(arr, asize);
	return ("ra\n");
}

char	*ft_rb(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_rotate1(brr, bsize);
	return ("rb\n");
}

char	*ft_rra(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_revrotate1(arr, asize);
	return ("rra\n");
}

char	*ft_rrb(int	*arr, int *brr, size_t asize, size_t bsize)
{
	ft_revrotate1(brr, bsize);
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

