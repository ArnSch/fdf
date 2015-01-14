/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:59:36 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:54:22 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		size1;
	size_t		size2;
	char		*dst;

	if (!s1 || !s2)
		return (NULL);
	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	if (NULL == (dst = (char *)ft_memalloc(size1 + size2 + 1)))
		return (NULL);
	dst = (char *)ft_memcpy(dst, s1, size1);
	ft_strncpy(dst + size1, s2, size2 + 1);
	return (dst);
}
