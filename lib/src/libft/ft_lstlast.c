/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 02:57:39 by dongmlee          #+#    #+#             */
/*   Updated: 2022/03/15 15:11:25 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_lst;

	last_lst = lst;
	if (!lst)
		return (0);
	while (last_lst->next)
	{
		last_lst = last_lst->next;
	}
	return (last_lst);
}
