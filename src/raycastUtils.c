/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastUtils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: woon <woon@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 01:45:09 by woon              #+#    #+#             */
/*   Updated: 2022/07/25 04:42:45 by woon             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	map_get_cell(t_cub *cub, int x, int y)
{
	if (x >= 0 && x < cub->map_width && y >= 0 && y < cub->map_height)
		return (cub->map[y][x] - 48);
	else
		return (-1);
}

int	sgn(double d)
{
	if (is_zero(d))
		return (0);
	else
	{
		if (d > 0)
			return (1);
		else
			return (-1);
	}
}

double	l2dist(double x0, double y0, double x1, double y1)
{
	double	dx;
	double	dy;

	dx = x0 - x1;
	dy = y0 - y1;
	return (sqrt(dx * dx + dy * dy));
}
