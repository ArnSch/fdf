/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:32:51 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:46:32 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *str)
{
	char	*str_dup;
	int		len;
	int		count;

	len = ft_strlen(str);
	count = 0;
	if (NULL == (str_dup = (char *)malloc(len + 1)))
		return (0);
	while (count <= len)
	{
		str_dup[count] = str[count];
		count++;
	}
	return (str_dup);
}
