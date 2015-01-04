/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 20:05:48 by aschenk           #+#    #+#             */
/*   Updated: 2014/11/21 15:29:34 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isupper(int c)
{
	return ((c <= 'Z' && c >= 'A') ? 1 : 0);
}

int		ft_islower(int c)
{
	return ((c <= 'z' && c >= 'a') ? 1 : 0);
}

int		ft_isalpha(int c)
{
	if (ft_isascii(c))
		if (ft_isupper(c) || ft_islower(c))
			return (1);
	return (0);
}
