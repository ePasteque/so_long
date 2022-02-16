/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 13:00:13 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/16 15:23:40 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	open_map(char *name)
{
	int	fd;
	int	i;

	i = 0;
	while (name[i + 4])
		i++;
	if (ft_strnstr(&name[i], ".ber", 4) == 0)
		error(5);
	fd = open(name, O_RDONLY);
	if (fd < 0)
		error(0);
	return (fd);
}

static void	following(int nb_line, char **map, int i, t_obj *obj)
{
	if (nb_line == 0 || !map[nb_line + 1])
	{
		if (obj->rock != obj->ref_length - 1)
			error(1);
		if (!map[nb_line + 1])
		{
			if (obj->me != 1)
				error(1);
			else if (obj->key < 1 || obj->exit < 1)
				error(1);
			i++;
		}
	}
	else
	{
		if (map[nb_line][0] != '1' || (map[nb_line][i - 1] == '\n' &&
			map[nb_line][i - 2] != '1'))
			error(1);
	}
	if (i != obj->ref_length)
		error(1);
}

static void	check_map(char **map, t_obj *obj)
{
	int		i;
	int		y;

	y = -1;
	while (map[++y])
	{
		obj->rock = 0;
		i = -1;
		while (map[y][++i])
		{
			if (y == 0)
				obj->ref_length++;
			if (map[y][i] == '1')
				obj->rock++;
			else if (map[y][i] == 'C')
				obj->key++;
			else if (map[y][i] == 'E')
				obj->exit++;
			else if (map[y][i] == 'P')
				obj->me++;
			else if (map[y][i] != '0' && map[y][i] != '\n')
				error(1);
		}
		following(y, map, i, obj);
	}
}

static char	**init(char *tmp, int fd, t_obj *obj)
{
	int		i;
	char	**map;
	t_list	*real_map;
	t_list	*new_list_elem;

	real_map = NULL;
	i = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		new_list_elem = ft_lstnew(tmp);
		if (!new_list_elem)
		{
			free(tmp);
			error(4);
		}
		ft_lstadd_back(&real_map, new_list_elem);
		i++;
	}
	map = malloc(sizeof(char *) * (i + 1));
	remplissage(map, real_map, i);
	check_map(map, obj);
	return (map);
}

char	**parsing(char *name)
{
	int		i;
	int		fd;
	t_obj	obj;
	char	*tmp;
	char	**map;

	obj.exit = 0;
	obj.me = 0;
	obj.ref_length = 0;
	obj.key = 0;
	i = 0;
	tmp = NULL;
	fd = open_map(name);
	map = init(tmp, fd, &obj);
	close(fd);
	return (map);
}
