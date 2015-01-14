/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 11:57:54 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 16:03:56 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t		len;
	size_t		i;
	char		*s_dup;
	char		*temp;
	char		*s_r;

	if (!s || !*s)
		return (NULL);
	len = ft_strlen(s);
	if (!(s_dup = ft_strnew(len)))
		return (NULL);
	s_dup = ft_strcpy(s_dup, s);
	temp = s_dup;
	while ((*s_dup == ' ' || *s_dup == '\t' ||
				*s_dup == '\n') && *s_dup != '\0')
		s_dup++;
	if ((len = ft_strlen(s_dup)) == 0)
		return (ft_strdup(s_dup));
	i = len - 1;
	while ((s_dup[i] == ' ' || s_dup[i] == '\t' ||
				s_dup[i] == '\n') && s_dup[i] != '\0')
		s_dup[i--] = '\0';
	s_r = (i == 0) ? ft_strdup(s_dup) : ft_strsub((char const *)s_dup, 0, len);
	free(temp);
	return (s_r);
}
