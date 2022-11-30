/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkElement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongmlee <dongmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:16:07 by idongmin          #+#    #+#             */
/*   Updated: 2022/08/02 17:50:18 by dongmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

static void	check_element_err(char *word, int wordcnt)
{
	if (ft_strncmp(word, "NO\0", 3) == 0 && wordcnt != 2)
		ft_exit("Invalid NO line format\n");
	else if (ft_strncmp(word, "SO\0", 3) == 0 && wordcnt != 2)
		ft_exit("Invalid SO line format\n");
	else if (ft_strncmp(word, "WE\0", 3) == 0 && wordcnt != 2)
		ft_exit("Invalid WE line format\n");
	else if (ft_strncmp(word, "EA\0", 3) == 0 && wordcnt != 2)
		ft_exit("Invalid EA line format\n");
	else if (ft_strncmp(word, "F\0", 2) == 0 && wordcnt != 2)
		ft_exit("Invalid F line format\n");
	else if (ft_strncmp(word, "C\0", 2) == 0 && wordcnt != 2)
		ft_exit("Invalid C line format\n");
}

int	check_type(t_cub *cub, char **word, int wordcnt)
{
	char	*tmp_word;
	int		ret;

	ret = 0;
	tmp_word = NULL;
	if (word[1])
		tmp_word = ft_strdup_nl(word[1]);
	check_element_err(word[0], wordcnt);
	if (ft_strncmp(word[0], "NO\0", 3) == 0)
		set_texure(cub, tmp_word, NORTH);
	else if (ft_strncmp(word[0], "SO\0", 3) == 0)
		set_texure(cub, tmp_word, SOUTH);
	else if (ft_strncmp(word[0], "WE\0", 3) == 0)
		set_texure(cub, tmp_word, WEST);
	else if (ft_strncmp(word[0], "EA\0", 3) == 0)
		set_texure(cub, tmp_word, EAST);
	else if (ft_strncmp(word[0], "F\0", 2) == 0)
		set_color(cub, tmp_word, FLOOR);
	else if (ft_strncmp(word[0], "C\0", 2) == 0)
		set_color(cub, tmp_word, CEILING);
	else if (ft_strchr(word[0], '1'))
		ret = MAP;
	free(tmp_word);
	return (ret);
}

static void	set_color_utils(t_cub *cub, int type, int hex)
{
	if (type == FLOOR && cub->ele.floor == -1)
		cub->ele.floor = hex;
	else if (type == CEILING && cub->ele.ceiling == -1)
		cub->ele.ceiling = hex;
	else
		ft_exit("Multiple floor/ceiling colors\n");
}

void	set_color(t_cub *cub, char *rgb_color, int type)
{
	char	**rgb;
	int		hex;
	int		rgb_nbr;
	int		i;

	rgb = ft_split(rgb_color, ',');
	if (!rgb)
		ft_exit("Fail to split RGB\n");
	i = -1;
	hex = 0;
	while (++i < 3)
	{
		if (!rgb[i] || !ft_isdigit_str(rgb[i]))
			ft_exit("Invalid RGB format\n");
		rgb_nbr = ft_atoi(rgb[i]);
		if (rgb_nbr > 255 || rgb_nbr < 0)
			ft_exit("Invalid RGB range\n");
		hex = hex * 256 + rgb_nbr;
	}
	set_color_utils(cub, type, hex);
	ft_two_point_free(rgb);
	cub->map_flag++;
}

void	set_texure(t_cub *cub, char *xpm_path, int type)
{
	int		fd;

	if (!xpm_path)
		ft_exit("Empty xpm path\n");
	if (!ft_isformat(xpm_path, ".xpm"))
		ft_exit("Invalid xpm path format\n");
	fd = open(xpm_path, O_RDONLY);
	if (fd == -1)
		ft_exit("Fail to open .xpm file\n");
	close(fd);
	if (cub->ele.xpm_path[type] != NULL)
		ft_exit("Multiple xpm paths\n");
	cub->ele.xpm_path[type] = ft_strdup(xpm_path);
	cub->map_flag++;
}
