/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settingRay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 02:58:08 by woon              #+#    #+#             */
/*   Updated: 2022/07/25 09:30:48 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	set_wall_state(t_cub *cub, double *wx, double *wy)
{
	if (cub->ray.hit_side == VERT)
	{
		if (cub->ray.xstep > 0)
			cub->ele.wdir = WEST;
		else
			cub->ele.wdir = EAST;
		*wx = cub->ray.nx;
		*wy = cub->ray.f;
	}
	else
	{
		if (cub->ray.ystep > 0)
			cub->ele.wdir = SOUTH;
		else
			cub->ele.wdir = NORTH;
		*wx = cub->ray.g;
		*wy = cub->ray.ny;
	}
	cub->ray.hit = TRUE;
}

void	set_nx_ny(t_cub *cub, double px, double py)
{
	if (cub->ray.xstep > 0)
		cub->ray.nx = floor(px) + 1;
	else
	{
		if (cub->ray.xstep < 0)
			cub->ray.nx = ceil(px) - 1;
		else
			cub->ray.nx = px;
	}
	if (cub->ray.ystep > 0)
		cub->ray.ny = floor(py) + 1;
	else
	{
		if (cub->ray.ystep < 0)
			cub->ray.ny = ceil(py) - 1;
		else
			cub->ray.ny = py;
	}
}

void	set_mapx_mapy(t_cub *cub)
{
	if (cub->ray.dist_v < cub->ray.dist_h)
	{
		if (cub->ray.xstep == 1)
			cub->ray.mapx = (int)(cub->ray.nx);
		else
			cub->ray.mapx = (int)(cub->ray.nx) - 1;
		cub->ray.mapy = (int)(cub->ray.f);
		cub->ray.hit_side = VERT;
	}
	else
	{
		cub->ray.mapx = (int)(cub->ray.g);
		if (cub->ray.ystep == 1)
			cub->ray.mapy = (int)(cub->ray.ny);
		else
			cub->ray.mapy = (int)(cub->ray.ny) - 1;
		cub->ray.hit_side = HORIZ;
	}
}

void	init_ray(t_cub *cub, double ray, double px, double py)
{
	cub->ray.xstep = sgn(cos(ray));
	cub->ray.ystep = sgn(sin(ray));
	if (cub->ray.xstep)
		cub->ray.xslope = tan(ray);
	else
		cub->ray.xslope = INFINITY;
	if (cub->ray.ystep)
		cub->ray.yslope = 1. / tan(ray);
	set_nx_ny(cub, px, py);
	cub->ray.f = INFINITY;
	cub->ray.g = INFINITY;
	cub->ray.hit = FALSE;
	cub->ray.hit_side = -1;
}
