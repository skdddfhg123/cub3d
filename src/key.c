/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 03:20:24 by woon              #+#    #+#             */
/*   Updated: 2022/08/02 14:19:23 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	move_f_b(t_cub *cub, double amt)
{
	cub->ray.nx = cub->user.pos_x + amt * cos(deg2rad(cub->ray.th));
	cub->ray.ny = cub->user.pos_y + amt * sin(deg2rad(cub->ray.th));
	if (map_get_cell(cub, cub->ray.nx, cub->ray.ny) == 1)
		return ;
	cub->user.pos_x = cub->ray.nx;
	cub->user.pos_y = cub->ray.ny;
}

void	move_l_r(t_cub *cub, int th)
{
	cub->ray.nx = cub->user.pos_x + MOVE_UNIT * cos(deg2rad(cub->ray.th) + th);
	cub->ray.ny = cub->user.pos_y + MOVE_UNIT * sin(deg2rad(cub->ray.th) + th);
	if (map_get_cell(cub, cub->ray.nx, cub->ray.ny) == 1)
		return ;
	cub->user.pos_x = cub->ray.nx;
	cub->user.pos_y = cub->ray.ny;
}

void	rotate_user(t_cub *cub, double th)
{
	cub->ray.th += rad2deg(th);
	if (cub->ray.th < 0)
		cub->ray.th += 360;
	else if (cub->ray.th > 360)
		cub->ray.th -= 360;
}

int	exit_cub3d(void)
{
	printf("Red button is pressed\n");
	exit(0);
}

int	key_press(int key, t_cub *cub)
{
	if (key == KEY_W)
		move_f_b(cub, MOVE_UNIT);
	if (key == KEY_S)
		move_f_b(cub, -MOVE_UNIT);
	if (key == KEY_A)
		move_l_r(cub, -90);
	if (key == KEY_D)
		move_l_r(cub, 90);
	if (key == KEY_LEFT)
		rotate_user(cub, -ROT_UNIT);
	if (key == KEY_RIGHT)
		rotate_user(cub, ROT_UNIT);
	if (key == KEY_ESC)
	{
		printf("Exit key is pressed\n");
		exit(0);
	}
	return (0);
}
