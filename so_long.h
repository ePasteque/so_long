/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbattest <lbattest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:23:25 by lbattest          #+#    #+#             */
/*   Updated: 2022/02/16 11:45:46 by lbattest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_obj {
	int	rock;
	int	exit;
	int	key;
	int	me;
	int	ref_length;
}				t_obj;

typedef struct s_sprites {
	void	*rock;
	void	*floor;
	void	*chest;
	void	*key;
	void	*me;
}				t_sprites;

typedef struct s_path {
	char	*chest;
	char	*floor;
	char	*rock;
	char	*key;
	char	*me;	
}				t_path;

typedef struct s_move {
	int		nb_mvmt;
	int		tt_key;
	int		nb_key;
	int		x;
	int		y;
	char	**map;
}				t_move;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	t_move		move;
	t_sprites	sprites;
}				t_vars;

void	error(int i);
void	print_map(char **map, t_vars *vars);
char	*get_next_line(int fd);
char	**parsing(char *name);
void	hook(t_vars	*vars);
int		destroy(t_vars *vars);
void	*free_all(char **str);
void	remplissage(char **map, t_list *real_map, int tt_line);

#endif
