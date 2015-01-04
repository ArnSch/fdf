/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:55:16 by aschenk           #+#    #+#             */
/*   Updated: 2015/01/04 16:44:27 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef	struct		s_fdf {
		void			*next;
		int				y;
		int				x;
		int				z;

	}			t_fdf;

t_fdf	*get_last_node(t_fdf *list);

typedef struct		s_sl {
		void	*previous;
		t_fdf			*start;
		int		pxlsize_x;
		int		pxlsize_y
		void	*next;
	}				t_sl;

typedef struct		s_slope {
		int		x;
		int		y;
	}				t_slope;

typedef struct		s_delta {
		int		x;
		int		y;
	}				t_delta;
#endif
