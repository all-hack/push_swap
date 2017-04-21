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

t_flags	*t_flags_init(void)
{
	t_flags	*ft;

	if ((ft = (t_flags*)malloc(sizeof(t_flags))) == 0)
		ft_ps_error(0, "Malloc fail\n");
	ft->valid_flags[0] = "-help";
	ft->valid_flags[1] = "-debug";
	ft->valid_flags[2] = "-v";
	ft->valid_flags[3] = "-stat";
	ft->valid_flags[4] = "-list";
	ft->valid_flags[5] = "-check";
	ft->valid_flags[6] = NULL;
	ft->flags[0] = -1;
	ft->flags[1] = -1;
	ft->flags[2] = -1;
	ft->flags[3] = -1;	
	ft->flags[4] = -1;
	ft->flags[5] = -1;
	ft->flags[6] = 0;
	return (ft);
}

void	t_flags_clean(t_algo **ft)
{
	if (ft && *ft)
	{
		free((*ft));
		*ft = NULL;
	}
}
