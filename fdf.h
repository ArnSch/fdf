/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:55:16 by aschenk           #+#    #+#             */
/*   Updated: 2015/01/12 17:19:24 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <mlx.h>
# include <math.h>
# include "libft/includes/libft.h"
# include "get_next_line.h"
# include <fcntl.h>
# include <unistd.h>

# define ZOOM						20
# define WIN_HEIGHT					1080
# define WIN_WIDTH					1920
# define POINT(next,x,y,z)			((t_fdf){(next), (x), (y), (z)})
# define DELTA(x,y)					((t_delta){(x), (y)})
# define SLOPE(x,y)					((t_slope){(x), (y)})

typedef	struct		s_fdf {
	void			*next;
	int				x;
	int				y;
	int				z;
}					t_fdf;

typedef struct		s_sl {
	void			*previous;
	t_fdf			*start;
	void			*next;
}					t_sl;

typedef struct		s_slope {
	int				x;
	int				y;
}					t_slope;

typedef struct		s_delta {
	int				x;
	int				y;
}					t_delta;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_sl			*data;
}					t_env;

void				put_pixel(t_sl *list, void *mlx, void *win);
t_fdf				*get_last_node(t_fdf *list);
t_fdf				*create_node(int line, int col);
t_sl				*create_line(void);
t_sl				*array_to_list(int l, char **tab);
t_sl				*parse(int fd, t_sl *list, t_sl *tmp);
#endif
