/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:21:32 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/14 12:22:02 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy(t_vars *vars)
{
	mlx_clear_window(vars->mlx, vars->win);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	movement(t_vars *vars, int futur_y, int futur_x)
{
	if (vars->move.map[futur_y][futur_x] == 'E' && vars->move.nb_key ==
		vars->move.tt_key)
		destroy(vars);
	if (vars->move.map[futur_y][futur_x] != '1' &&
		vars->move.map[futur_y][futur_x] != 'E')
	{
		if (vars->move.map[futur_y][futur_x] == 'C')
		{
			vars->move.nb_key++;
			vars->move.map[futur_y][futur_x] = '0';
		}
		printf("%d\n", vars->move.nb_mvmt++);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites.floor,
			vars->move.x * 31, vars->move.y * 31);
		vars->move.y = futur_y;
		vars->move.x = futur_x;
		mlx_put_image_to_window(vars->mlx, vars->win, vars->sprites.me,
			vars->move.x * 31, vars->move.y * 31);
	}
}

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == KEY_ESC)
		destroy(vars);
	else if (keycode == KEY_W)
		movement(vars, vars->move.y - 1, vars->move.x);
	else if (keycode == KEY_A)
		movement(vars, vars->move.y, vars->move.x - 1);
	else if (keycode == KEY_S)
		movement(vars, vars->move.y + 1, vars->move.x);
	else if (keycode == KEY_D)
		movement(vars, vars->move.y, vars->move.x + 1);
	return (0);
}

void	hook(t_vars	*vars)
{
	vars->move.nb_mvmt = 1;
	vars->move.nb_key = 0;
	mlx_key_hook(vars->win, key_hook, vars);
}
