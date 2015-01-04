/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:04:51 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:57:16 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;
	size_t		i;

	s2_len = ft_strlen((char *)s2);
	if (*s2 == '\0')
		return ((char *)s1);
	if (s2_len > ft_strlen(s1) || s2_len > n)
		return (NULL);
	i = 0;
	while ((char)s1[i] && (i + s2_len) <= n)
	{
		if (!(ft_strncmp(s1 + i, s2, s2_len)))
			return ((char *)(s1 + i));
		i++;
	}
	return (NULL);
}
