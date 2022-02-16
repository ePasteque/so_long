/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:36:28 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/14 12:05:41 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init(t_sprites *sprites, void *mlx)
{
	t_path	path;
	int		width;
	int		heigth;

	path.chest = "./sprites/sprite_chest.xpm";
	path.floor = "./sprites/sprite_floor.xpm";
	path.rock = "./sprites/sprite_rock.xpm";
	path.key = "./sprites/sprite_key.xpm";
	path.me = "./sprites/sprite_me.xpm";
	sprites->chest = mlx_xpm_file_to_image(mlx, path.chest, &width, &heigth);
	if (!sprites->chest)
		error(3);
	sprites->floor = mlx_xpm_file_to_image(mlx, path.floor, &width, &heigth);
	if (!sprites->floor)
		error(3);
	sprites->rock = mlx_xpm_file_to_image(mlx, path.rock, &width, &heigth);
	if (!sprites->rock)
		error(3);
	sprites->key = mlx_xpm_file_to_image(mlx, path.key, &width, &heigth);
	if (!sprites->key)
		error(3);
	sprites->me = mlx_xpm_file_to_image(mlx, path.me, &width, &heigth);
	if (!sprites->me)
		error(3);
}

static void	*open_win(void *mlx, char **map)
{
	int	x;
	int	y;

	y = 0;
	x = 0;
	while (map[y][x])
		x++;
	while (map[y])
		y++;
	x--;
	return (mlx_new_window(mlx, x * 31, y * 31, "so_long"));
}

static void	forest(char **map, t_vars *v, int x, int y)
{
	if (map[y][x] == '1')
		mlx_put_image_to_window(v->mlx, v->win, v->sprites.rock,
			x * 31, y * 31);
	else if (map[y][x] == '0')
		mlx_put_image_to_window(v->mlx, v->win, v->sprites.floor,
			x * 31, y * 31);
	else if (map[y][x] == 'P')
	{
		mlx_put_image_to_window(v->mlx, v->win, v->sprites.me, x * 31, y * 31);
		v->move.x = x;
		v->move.y = y;
	}
	else if (map[y][x] == 'C')
	{
		v->move.tt_key++;
		mlx_put_image_to_window(v->mlx, v->win, v->sprites.key, x * 31, y * 31);
	}
	else if (map[y][x] == 'E')
		mlx_put_image_to_window(v->mlx, v->win, v->sprites.chest,
			x * 31, y * 31);
}

void	print_map(char **map, t_vars *vars)
{
	int	y;
	int	x;

	y = -1;
	vars->mlx = mlx_init();
	vars->win = open_win(vars->mlx, map);
	init(&vars->sprites, vars->mlx);
	vars->move.tt_key = 0;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			forest(map, vars, x, y);
	}
}
