/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMapUtil.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 00:04:25 by idongmin          #+#    #+#             */
/*   Updated: 2022/07/21 23:51:17 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	ft_isdigit_str(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isformat(char *str, char *fmt)
{
	int		len_str;
	int		len_fmt;
	char	*start_fmt;

	len_str = ft_strlen(str);
	len_fmt = ft_strlen(fmt);
	if (len_str <= len_fmt)
		return (0);
	start_fmt = str + len_str - len_fmt;
	if (ft_strncmp(start_fmt, fmt, len_fmt) == 0)
		return (1);
	return (0);
}

size_t	ft_find_maxwidth(t_list *lst)
{
	size_t	ret;
	size_t	tmp;

	ret = 0;
	while (lst)
	{
		tmp = ft_strlen((const char *)lst->content);
		if (tmp > ret)
			ret = tmp;
		lst = lst->next;
	}
	return (ret);
}
