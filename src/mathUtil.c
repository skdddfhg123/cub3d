/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mathUtil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:10:27 by idongmin          #+#    #+#             */
/*   Updated: 2022/08/02 14:18:16 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

double	is_zero(double d)
{
	return (fabs(d) < EPS);
}

double	deg2rad(double d)
{
	return (d * M_PI / 180.0);
}

double	rad2deg(double d)
{
	return (d * 180.0 / M_PI);
}

double	fov_h(void)
{
	return (deg2rad(FOV));
}

double	fov_v(void)
{
	return (fov_h() * (double)SY / (double)SX);
}
