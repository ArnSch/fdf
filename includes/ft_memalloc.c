/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 10:56:54 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:38:30 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t		i;
	void		*mem;

	i = 0;
	if (NULL == (mem = malloc(sizeof(void *) * size)))
		return (NULL);
	while (i < size)
		((char *)mem)[i++] = '\0';
	return (ft_memset(mem, '\0', size + 1));
}
