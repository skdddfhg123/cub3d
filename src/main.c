/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 10:53:53 by idongmin          #+#    #+#             */
/*   Updated: 2022/08/02 17:19:11 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	init_set(t_cub *cub, char *arg)
{
	ft_memset(cub, 0, sizeof(t_cub));
	cub->ele.floor = -1;
	cub->ele.ceiling = -1;
	if (!ft_filecheck(arg, ".cub"))
		ft_exit("Invalid .cub file format\n");
	cub->fd = open(arg, O_RDONLY);
	if (cub->fd == -1)
		ft_exit("Fail to open .cub file\n");
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (argc != 2)
		ft_exit("Please write ./cub3D map.cup\n");
	init_set(&cub, argv[1]);
	check_map(&cub);
	set_texture(&cub);
	start(&cub);
	return (0);
}
