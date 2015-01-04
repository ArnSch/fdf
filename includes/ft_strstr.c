/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 18:44:31 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 16:02:42 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	if (ft_strlen(s2) > ft_strlen(s1))
		return (NULL);
	while (*s1 && s2[i])
	{
		if (*(s1 + i) != s2[i])
		{
			s1++;
			i = 0;
		}
		else
			i++;
	}
	return ((i == 0) ? NULL : (char *)s1);
}
