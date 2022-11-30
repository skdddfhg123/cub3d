/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 02:53:30 by dongmlee          #+#    #+#             */
/*   Updated: 2022/07/21 20:12:48 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void		*arr;

	arr = (void *)malloc(size * count);
	if (!arr)
		return (0);
	ft_memset(arr, 0, count * size);
	return (arr);
}
