/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 10:30:56 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 16:03:18 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s_new;

	if (!s || !*s)
		return (NULL);
	if (!(s_new = ft_strnew(len)))
		return (NULL);
	return (ft_strncpy(s_new, s + start, len));
}
