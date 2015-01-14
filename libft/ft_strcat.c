/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 14:30:26 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:43:51 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	int		i;

	i = 0;
	if (!dest || !src)
		return (NULL);
	while (dest[i] != '\0')
	{
		i++;
	}
	if (dest[i] == '\0')
	{
		while (*src != '\0')
		{
			dest[i] = *(src++);
			i++;
		}
		dest[i] = '\0';
	}
	return (dest);
}
