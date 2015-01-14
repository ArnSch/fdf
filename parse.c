/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 11:20:48 by aschenk           #+#    #+#             */
/*   Updated: 2015/01/12 17:12:31 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_sl	*array_to_list(int l, char **tab)
{
	int			i;
	t_sl		*line;
	t_fdf		*tmp;

	i = 0;
	while (tab[i])
	{
		if (i == 0)
		{
			line = create_line();
			line->start = create_node((l * ZOOM), (i * ZOOM));
			tmp = line->start;
		}
		else
		{
			tmp->next = create_node((l * ZOOM), (i * ZOOM));
			tmp = tmp->next;
		}
		tmp->z = ft_atoi(tab[i]);
		tmp->x = 700 + (int)(0.3 * (double)tmp->x - 0.3 * (double)tmp->y);
		tmp->y = (WIN_HEIGHT - (700)) / 2 + (int)(-(double)tmp->z + 0.25 *
					(double)tmp->x + 0.25 * (double)tmp->y);
		i++;
	}
	return (line);
}

t_sl	*parse(int fd, t_sl *list, t_sl *tmp)
{
	t_sl		*tmp2;
	int			y;
	char		**tab;
	char		*line;

	y = 0;
	while (get_next_line(fd, &line) && (tab = ft_strsplit(line, ' ')))
	{
		if (y == 0 && (list = array_to_list(y, tab)) != NULL)
		{
			list->previous = NULL;
			tmp = list;
		}
		else if ((tmp->next = array_to_list(y, tab)) != NULL)
		{
			tmp2 = tmp->next;
			tmp2->previous = tmp;
			tmp = tmp2;
		}
		else
			exit(1);
		y++;
	}
	free(line);
	return (list);
}
