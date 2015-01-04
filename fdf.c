/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 14:43:43 by aschenk           #+#    #+#             */
/*   Updated: 2015/01/04 18:20:07 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/includes/libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include "fdf.h"
#include <stdlib.h>
#include <mlx.h>
#include <math.h>

t_fdf	*create_node(int line, int col)
{
	t_fdf	*node;

	if (!(node = (t_fdf *)malloc(sizeof(t_fdf))))
		return (NULL);
	node->y = line;
	node->x = col;
	return (node);
}

t_sl	*create_line(void)
{
	t_sl	*line;

	if (!(line = (t_sl *)malloc(sizeof(t_sl))))
		return (NULL);
	return (line);
}

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
			line->start = create_node((l * 20), (i * 20));
			tmp = line->start;
		}
		else
		{
			tmp->next = create_node((l * 20), (i * 20));
			tmp = tmp->next;
		}
		tmp->z = ft_atoi(tab[i]);
		tmp->x = (1920 - (25*20)) /2 + (int)(0.25 * (double)tmp->x - 0.25 * (double)tmp->y);
		tmp->y = (1080 - (25*20)) /2 + (int)(-(double)tmp->z + 0.3 * (double)tmp->x + 0.3 * (double)tmp->y);
		i++;
	}
	line->pxlsize_x = i * 20;
	return (line);
}

t_sl	*parse(char *line, int fd, t_sl *list, t_sl *tmp)
{
	t_sl		*tmp2;
	int			y;
	char		**tab;

	y = 0;
	while (get_next_line(fd, &line))
	{
		tab = ft_strsplit(line, ' ');
		if (y == 0)
		{
			list = array_to_list(y, tab);
			list->previous = NULL;
			tmp = list;
		}
		else
		{
			tmp->next = array_to_list(y, tab);
			tmp2 = tmp->next;
			tmp2->previous = tmp;
			tmp = tmp2;
		}
		y++;
	}
	free(line);
	list->pxlsize_y = y * 20;
	return (list);
}

t_slope		*create_slope(int x_slope, int y_slope)
{
	t_slope		*slope;

	if (!(slope = (t_slope *)malloc(sizeof(t_slope))))
		return (NULL);
	slope->x = x_slope;
	slope->y = y_slope;
	return (slope);
}

t_delta		*create_delta(int x_delta, int y_delta)
{
	t_delta		*delta;

	if (!(delta = (t_delta *)malloc(sizeof(t_delta))))
		return (NULL);
	delta->x = x_delta;
	delta->y = y_delta;
	return (delta);
}

int		set_pixel(void *img, t_sl *list, int x, int y)
{
	int		*image;
	int		bpp;

	bpp = 4;
	image = (int *)mlx_get_data_addr(img, &bpp, list->pxlsize_x * bpp, 0);
	image[(x * (list->pxlsize_x * bpp)) + (y * bpp)] = 0xFF0000;
}

int		draw_line(t_fdf *p1, t_fdf *p2, void *mlx, void *win)
{
	t_fdf	*tmp;
	t_delta	*delta;
	t_slope	*slope;
	int		err;
	int		e2;

	tmp = create_node(p1->y, p1->x);
	delta = create_delta(abs(p2->x - tmp->x), abs(p2->y - tmp->y));
	slope = create_slope((tmp->x < p2->x) ? 1 : -1, (tmp->y < p2->y) ? 1 : -1);
	err = ((delta->x > delta->y) ? delta->x : delta->y) / 2;
	while (1)
	{
		// everytime I pixel_put, I just switch the pixel at the address I have to red instead of black.
		mlx_pixel_put(mlx, win, tmp->x, tmp->y, 0xFF0000);
		if (tmp->x == p2->x && tmp->y == p2->y)
			break ;
		e2 = err;
		if (e2 > -delta->x && tmp->x != p2->x && (tmp->x += slope->x))
			err -= delta->y;
		if (e2 < delta->y && (tmp->y += slope->y))	
			err += delta->x;
	}
	return (1);
}

void	put_pixel(t_sl *list, void *mlx, void *win)
{
	t_fdf	*p1;
	t_fdf	*p2;
	t_fdf	*p3;
	t_sl	*tmp;

	while (list && (p1 = list->start))
	{
		p2 = p1->next;
		if ((tmp = list->previous) != NULL)
			p3 = tmp->start;
		while (p1)
		{
			if (p3 && draw_line(p1, p3, mlx, win))
				p3 = p3->next;
			if (p2 && draw_line(p1, p2, mlx, win))
				p2 = p2->next;
			p1 = p1->next;
		}
		list = list->next;
	}
}

int		main(int ac, char **av)
{
	t_sl		*list;
	void		*mlx;
	void		*win;
	void		*img;
	int			fd;

	if (ac != 2)
		return (-1);
	if (-1 == (fd = open(av[1], O_RDONLY)))
		return (-1);
	list = parse(ft_memalloc(256), fd, NULL, NULL);
	close(fd);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "42");
	img	= mlx_new_image(mlx, list->pxlsize_x, list->pxlsize_y);
	put_pixel(list, mlx, win);
	sleep(100);
	return (0);
}
