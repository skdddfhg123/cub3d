/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chaewkim <chaewkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 11:13:17 by idongmin          #+#    #+#             */
/*   Updated: 2022/08/02 15:28:50 by chaewkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/cub3d.h"

int	ft_filecheck(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*start_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 <= len_s2)
		return (0);
	start_s2 = s1 + len_s1 - len_s2;
	if (ft_strncmp(start_s2, s2, len_s1) == 0)
		return (1);
	return (0);
}

void	ft_exit(char *str)
{
	ft_putstr_fd("ERROR\n", 2);
	ft_putstr_fd(str, 2);
	exit(0);
}

size_t	ft_wordcnt(char const *s, char c)
{
	size_t	count;
	int		word_start;

	count = 0;
	word_start = 1;
	while (*s)
	{
		if (*s == c)
			word_start = 1;
		else if (word_start == 1)
		{
			count++;
			word_start = 0;
		}
		s++;
	}
	return (count);
}

void	ft_two_point_free(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*ft_strdup_nl(const char *str)
{
	int		i;
	char	*dst;

	dst = (char *)malloc(sizeof(char) * ft_strlen(str));
	if (!dst)
		return (NULL);
	i = 0;
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i - 1] = '\0';
	return (dst);
}
