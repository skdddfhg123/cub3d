/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setTexture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 02:19:44 by woon              #+#    #+#             */
/*   Updated: 2022/07/25 07:35:59 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

void	get_texture_from_xpm(t_cub *cub, int *tex, char *xpm_path, t_img *img)
{
	int		x;
	int		y;

	img->ptr = mlx_xpm_file_to_image(cub->mlx, xpm_path,
			&img->width, &img->height);
	img->data = (int *)mlx_get_data_addr(
			img->ptr, &img->bpp, &img->size_line, &img->endian);
	y = -1;
	while (++y < img->height)
	{
		x = -1;
		while (++x < img->width)
			tex[img->width * y + x] = img->data[img->width * y + \
			(img->width - x - 1)];
	}
	mlx_destroy_image(cub->mlx, img->ptr);
}

void	set_texture(t_cub *cub)
{
	int		i;
	t_img	img;

	cub->mlx = mlx_init();
	i = 0;
	while (i < 4)
	{
		get_texture_from_xpm(cub, cub->ele.tex[i], cub->ele.xpm_path[i], &img);
		free(cub->ele.xpm_path[i]);
		i++;
	}
}
