/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 11:52:51 by aschenk           #+#    #+#             */
/*   Updated: 2015/01/12 17:11:50 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*get_last_node(t_fdf *list)
{
	t_fdf	*tmp;

	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_fdf	*create_node(int line, int col)
{
	t_fdf	*node;

	if (!(node = (t_fdf *)malloc(sizeof(t_fdf))))
		exit(1);
	node->y = line;
	node->x = col;
	node->next = NULL;
	return (node);
}

t_sl	*create_line(void)
{
	t_sl	*line;

	if (!(line = (t_sl *)malloc(sizeof(t_sl))))
		exit(1);
	line->previous = NULL;
	line->start = NULL;
	line->next = NULL;
	return (line);
}
