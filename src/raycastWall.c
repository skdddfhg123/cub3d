/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastWall.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:35:10 by woon              #+#    #+#             */
/*   Updated: 2022/08/02 14:18:01 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	set_step_dist(t_cub *cub)
{
	if (cub->ray.xstep != 0)
		cub->ray.f = cub->ray.xslope * (cub->ray.nx - cub->user.pos_x) \
		+ cub->user.pos_y;
	if (cub->ray.ystep != 0)
		cub->ray.g = cub->ray.yslope * (cub->ray.ny - cub->user.pos_y) \
		+ cub->user.pos_x;
	cub->ray.dist_v = l2dist(cub->user.pos_x, cub->user.pos_y, \
	cub->ray.nx, cub->ray.f);
	cub->ray.dist_h = l2dist(cub->user.pos_x, cub->user.pos_y, \
	cub->ray.g, cub->ray.ny);
}

int	get_wall_intersection(t_cub *cub, double ray, double *wx, double *wy)
{
	int	cell;

	init_ray(cub, ray, cub->user.pos_x, cub->user.pos_y);
	while (!cub->ray.hit)
	{
		set_step_dist(cub);
		set_mapx_mapy(cub);
		cell = map_get_cell(cub, cub->ray.mapx, cub->ray.mapy);
		if (cell < 0)
			break ;
		if (cell == 1)
		{
			set_wall_state(cub, wx, wy);
			break ;
		}
		if (cub->ray.hit_side == VERT)
			cub->ray.nx += cub->ray.xstep;
		else
			cub->ray.ny += cub->ray.ystep;
	}
	return (cub->ray.hit);
}

double	cast_single_ray(t_cub *cub, int x, double th)
{
	double	ray;

	ray = (th - half_fov_h()) + (x * angle_per_pixel());
	if (!get_wall_intersection(cub, ray, &cub->ele.wx, &cub->ele.wy))
		return (INFINITY);
	return (l2dist(cub->user.pos_x, cub->user.pos_y, \
	cub->ele.wx, cub->ele.wy) * cos(th - ray));
}
