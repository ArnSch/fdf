/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 17:04:45 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 16:02:08 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *occ, int c)
{
	char		c_bis;
	int			i;

	c_bis = (char)c;
	i = ft_strlen(occ);
	while (i >= 0)
	{
		if (occ[i] == c_bis)
			return ((char *)occ + i);
		i--;
	}
	return (NULL);
}
