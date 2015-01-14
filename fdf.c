/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aschenk <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 14:43:43 by aschenk           #+#    #+#             */
/*   Updated: 2015/01/12 17:11:07 by aschenk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_env *env)
{
	put_pixel(env->data, env->mlx, env->win);
	return (0);
}

int		key_hook(int keycode, t_env *env)
{
	(void)env;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int		main(int ac, char **av)
{
	t_env		env;
	int			fd;
	char		test[6];

	if (ac != 2)
		exit(1);
	if (-1 == (fd = open(av[1], O_RDONLY)) || (read(fd, test, 0)) < 0)
		exit(1);
	env.data = parse(fd, NULL, NULL);
	close(fd);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_WIDTH, WIN_HEIGHT, "42");
	mlx_expose_hook(env.win, expose_hook, &env);
	mlx_key_hook(env.win, key_hook, &env);
	mlx_loop(env.mlx);
	return (0);
}
