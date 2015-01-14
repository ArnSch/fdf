/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/29 12:09:30 by aschenk           #+#    #+#             */
/*   Updated: 2015/01/12 17:12:08 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	draw_line(t_fdf *first, t_fdf *second, void *mlx, void *win)
{
	t_fdf	tmp;
	t_delta	delta;
	t_slope	slope;
	int		err;
	int		e2;

	tmp = POINT(NULL, first->x, first->y, 0);
	delta = DELTA(fabs((double)second->x - (double)tmp.x),
			fabs((double)second->y - (double)tmp.y));
	slope = SLOPE((tmp.x < second->x) ? 1 : -1, (tmp.y < second->y) ? 1 : -1);
	err = ((delta.x > delta.y) ? delta.x : delta.y) / 2;
	while (1)
	{
		mlx_pixel_put(mlx, win, tmp.x, tmp.y, 0xFFFFFF);
		if ((tmp.x == second->x) && (tmp.y == second->y || e2 >= delta.y))
			break ;
		e2 = err;
		if (e2 > -delta.x && tmp.x != second->x && (tmp.x += slope.x))
			err -= delta.y;
		if (e2 < delta.y && (tmp.y += slope.y))
			err += delta.x;
	}
	return (1);
}

void		put_pixel(t_sl *list, void *mlx, void *win)
{
	t_fdf	*origin;
	t_fdf	*right;
	t_fdf	*above;

	above = NULL;
	while (list && (origin = list->start))
	{
		right = origin->next;
		if (list->previous)
			above = ((t_sl*)list->previous)->start;
		while (origin)
		{
			if (above && draw_line(origin, above, mlx, win))
				above = above->next;
			if (right && draw_line(origin, right, mlx, win))
				right = right->next;
			origin = origin->next;
		}
		list = list->next;
	}
}
