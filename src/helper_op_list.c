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

size_t	ft_count_operations(char *op_list)
{
	size_t i;

	i = 0;
	if (op_list)
		while (*op_list)
			if (*op_list++ == '\n')
				i++;
	return (i);
}

char	*ft_check_op_count(char *op_list, size_t *curr_count)
{
	size_t	op_count;
	
	op_count = ft_count_operations(op_list);

	if (op_count < *curr_count)
	{
		// printf("curr_count: %ld\n", *curr_count);
		*curr_count = op_count;
		// printf("curr_count: %ld\n", *curr_count);
		// printf("op_list: \n%s\n", op_list);
		// printf("op_list pointer: %p\n", op_list);
		return (op_list);
	}
	// return (curr_list);
	return (NULL);
}
