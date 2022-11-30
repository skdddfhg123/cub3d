/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapError.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 22:06:56 by idongmin          #+#    #+#             */
/*   Updated: 2022/08/02 17:28:27 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	check_horizontal(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < cub->map_height)
	{
		if (cub->map[y][0] != ' ' && cub->map[y][0] != WALL)
			ft_exit("Map is not surronded by wall(WEST)\n");
		if (cub->map[y][cub->map_width - 1] != ' ' && \
			cub->map[y][cub->map_width - 1] != WALL)
			ft_exit("Map is not surronded by wall(EAST)\n");
		x = 0;
		while (++x < cub->map_width)
		{
			if (cub->map[y][x] == ' ')
			{
				if (cub->map[y][x - 1] != ' ' && cub->map[y][x - 1] != WALL)
					ft_exit("Map is not surroned by wall(EAST)\n");
				else if (x + 1 < cub->map_width && cub->map[y][x + 1] != ' ' && \
					cub->map[y][x + 1] != WALL)
					ft_exit("Map is not surronded by wall(WEST)\n");
			}
		}
	}
}

static void	check_vertical(t_cub *cub)
{
	int	x;
	int	y;

	x = -1;
	while (++x < cub->map_width)
	{
		if (cub->map[0][x] != ' ' && cub->map[0][x] != WALL)
			ft_exit("Map is not surronded by wall(SOUTH)\n");
		if (cub->map[cub->map_height - 1][x] != ' ' && \
			cub->map[cub->map_height - 1][x] != WALL)
			ft_exit("Map is not surronded by wall(NORTH)\n");
		y = 0;
		while (++y < cub->map_height)
		{
			if (cub->map[y][x] == ' ')
			{
				if (cub->map[y - 1][x] != ' ' && cub->map[y - 1][x] != WALL)
					ft_exit("Map is not surroned by wall(NORTH)\n");
				else if (y + 1 < cub->map_height && \
					cub->map[y + 1][x] != ' ' && cub->map[y + 1][x] != WALL)
					ft_exit("Map is not surronded by wall(SOUTH)\n");
			}
		}
	}
}

void	error_check(t_cub *cub)
{
	if (!(cub->ele.xpm_path[NORTH]) || !(cub->ele.xpm_path[WEST]) || \
		!(cub->ele.xpm_path[SOUTH]) || !(cub->ele.xpm_path[EAST]))
		ft_exit("Empty texture path\n");
	if (cub->ele.floor == -1 || cub->ele.ceiling == -1)
		ft_exit("Empty color\n");
	if (!(cub->map_width) || !(cub->map_height))
		ft_exit("Invalid map size\n");
	if (!(cub->user.spawn_pos))
		ft_exit("Empty player's spawning orietation\n");
	check_horizontal(cub);
	check_vertical(cub);
}
