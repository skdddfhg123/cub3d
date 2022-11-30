/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 21:45:15 by woon              #+#    #+#             */
/*   Updated: 2022/07/25 08:09:04 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_wall(t_cub *cub)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SY)
	{
		x = -1;
		while (++x < SX)
		{
			if (y > SY / 2)
				cub->img.data[SX * y + x] = cub->ele.ceiling;
			else
				cub->img.data[SX * y + x] = cub->ele.floor;
		}
	}
}

int	render(t_cub *cub)
{
	int		x;
	double	wdist;

	set_wall(cub);
	x = -1;
	while (++x < SX)
	{
		wdist = cast_single_ray(cub, x, deg2rad(cub->ray.th));
		draw_wall(cub, wdist, x);
	}
	mlx_put_image_to_window(cub->mlx, cub->win, cub->img.ptr, 0, 0);
	return (0);
}
