/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fstrappend.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obelange <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 01:00:13 by obelange          #+#    #+#             */
/*   Updated: 2016/11/15 01:00:15 by obelange         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrappend(char *s1, char c)
{
	size_t	s1_len;
	size_t	c_len;
	char	*nstr;
	size_t	i;

	if (s1)
		s1_len = ft_strlen(s1);
	else
		s1_len = 0;
	if (c)
		c_len = 1;
	else
		c_len = 0;
	nstr = ft_strnew((s1_len + c_len + 1));
	ft_strncpy(nstr, s1, s1_len);
	ft_strncat(nstr, &c, 1);
	ft_strdel(&s1);
	return (nstr);
}
