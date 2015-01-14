/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 13:20:31 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:42:17 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		i;
	size_t		i_d;
	char		*dst_dup;
	char		*src_dup;

	if (!n || !dst || !src)
		return (dst);
	dst_dup = (char *)dst;
	src_dup = (char *)src;
	i = 0;
	while (i < n)
	{
		i_d = (dst_dup > src_dup) ? n - i - 1 : i;
		dst_dup[i_d] = src_dup[i_d];
		i++;
	}
	return (dst);
}
