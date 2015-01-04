/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:46:30 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:43:57 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *occ, int c)
{
	char		c_bis;
	size_t		i;

	c_bis = (char)c;
	i = 0;
	while (i <= ft_strlen(occ))
	{
		if (occ[i] == c_bis)
			return ((char *)occ + i);
		else
			i++;
	}
	return (NULL);
}
