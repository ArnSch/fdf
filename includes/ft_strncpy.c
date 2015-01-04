/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:19:27 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:56:12 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		count;
	size_t		len;

	count = 0;
	len = ft_strlen(src);
	if (!dst || !src || !n)
		return (dst);
	while (count < n)
	{
		if (count > len)
			dst[count++] = '\0';
		else
		{
			dst[count] = src[count];
			count++;
		}
	}
	return (dst);
}
