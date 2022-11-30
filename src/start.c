/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 01:38:38 by woon              #+#    #+#             */
/*   Updated: 2022/08/02 14:22:16 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	init_mlx(t_cub *cub)
{
	cub->img.ptr = mlx_new_image(cub->mlx, SX, SY);
	cub->img.data = (int *)mlx_get_data_addr(cub->img.ptr, \
		&cub->img.bpp, &cub->img.size_line, &cub->img.endian);
	cub->win = mlx_new_window(cub->mlx, SX, SY, "CUB3D");
}

void	start(t_cub	*cub)
{
	init_mlx(cub);
	mlx_hook(cub->win, X_EVENT_KEY_PRESS, 0, &key_press, cub);
	mlx_hook(cub->win, X_EVENT_KEY_EXIT, 0, &exit_cub3d, cub);
	mlx_loop_hook(cub->mlx, &render, cub);
	mlx_loop(cub->mlx);
}
