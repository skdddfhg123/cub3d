/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 03:32:08 by dongmlee          #+#    #+#             */
/*   Updated: 2022/03/15 15:11:21 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*last_lst;

	last_lst = lst;
	if (!lst || !(*f))
		return ;
	while (last_lst)
	{
		(*f)(last_lst->content);
		last_lst = last_lst->next;
	}
}
