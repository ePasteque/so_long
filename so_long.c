/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 13:00:06 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/16 14:16:26 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(int i)
{
	if (i == 0)
		perror("Error\nso_long");
	else if (i == 1)
		write(1, "Error\nso_long: Invalid map\n", 28);
	else if (i == 2)
		write(1, "Error\nso_long: Invalid number of argument\n", 43);
	else if (i == 3)
		write(1, "Error\nso_long: Can't load a sprite\n", 36);
	else if (i == 4)
		write(1, "Error\nso_long: Allocation error\n", 33);
	else if (i == 5)
		write(1, "Error\nso_long: No such file or directory\n", 42);
	exit(1);
}

void	*free_all(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars		vars;

	if (argc != 2)
		error(2);
	vars.move.map = parsing(argv[1]);
	print_map(vars.move.map, &vars);
	hook(&vars);
	mlx_hook(vars.win, 17, 1L << 0, destroy, &vars);
	mlx_loop(vars.mlx);
	free_all(vars.move.map);
	return (0);
}
