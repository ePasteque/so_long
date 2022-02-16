/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplissage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:44:19 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/16 15:24:41 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remplissage(char **map, t_list *real_map, int tt_line)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = real_map;
	while (i < tt_line)
	{
		map[i] = real_map->content;
		real_map = real_map->next;
		i++;
	}
	map[tt_line] = NULL;
	ft_lstclear(&tmp, NULL);
}
