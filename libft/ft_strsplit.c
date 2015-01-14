/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 12:50:04 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 16:02:30 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_count(char const *s, char c)
{
	size_t		count;
	size_t		i;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i - 1] == c && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		j;
	char		**tab;

	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (ft_count(s, c) + 1))))
		return (NULL);
	if (!s || !*s)
		return (tab);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (s[i] != c && s[i])
				i++;
			if (!(tab[j] = (char *)ft_memalloc(i + 1)))
				return (NULL);
			tab[j++] = ft_strsub(s, 0, i);
			s = s + i;
		}
		else
			s++;
	}
	return (tab);
}
