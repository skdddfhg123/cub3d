/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathUtil2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:16:23 by idongmin          #+#    #+#             */
/*   Updated: 2022/08/02 14:20:24 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

double	angle_per_pixel(void)
{
	return (fov_h() / (SX - 1.));
}

double	half_fov_h(void)
{
	return (fov_h() / 2.0);
}

double	pi_2(void)
{
	return (M_PI * 2);
}

int	min(int x, int y)
{
	if (x < y)
		return (x);
	else
		return (y);
}

int	max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}
