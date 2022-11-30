/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastHeight.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 20:09:53 by woon              #+#    #+#             */
/*   Updated: 2022/08/02 14:18:15 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	get_wall_height(double dist)
{
	double	height;

	height = 2.0 * dist * tan(fov_v() / 2.0);
	return ((int)(SY * (WALL_H / height)));
}

void	get_color(t_cub *cub, int y, double lum)
{
	double	txratio;
	int		tx;
	int		ty;

	if (cub->ele.wdir == WEST || cub->ele.wdir == EAST)
		txratio = cub->ele.wy - floor(cub->ele.wy);
	else
		txratio = cub->ele.wx - floor(cub->ele.wx);
	tx = (int)(txratio * TEX_WIDTH);
	ty = (int)((double)(y - cub->ele.y0) * TEX_HEIGHT / cub->ele.wh);
	cub->ele.color = fade_color(cub->ele.tex[cub->ele.wdir] \
	[TEX_WIDTH * ty + tx], lum);
}

void	draw_wall(t_cub *cub, double wdist, int x)
{
	int		ystart;
	int		yend;
	double	lum;

	lum = get_luminosity(cub, wdist);
	cub->ele.wh = get_wall_height(wdist);
	cub->ele.y0 = (int)((SY - cub->ele.wh) / 2.0);
	cub->ele.y1 = cub->ele.y0 + cub->ele.wh - 1;
	ystart = max(0, cub->ele.y0);
	yend = min(SY - 1, cub->ele.y1);
	while (ystart <= yend)
	{
		get_color(cub, ystart, lum);
		cub->img.data[SX * ystart + x] = cub->ele.color;
		ystart++;
	}
}
