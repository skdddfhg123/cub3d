/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: idongmin <idongmin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 03:18:31 by dongmlee          #+#    #+#             */
/*   Updated: 2022/03/15 15:11:12 by idongmin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_lst;

	tmp_lst = *lst;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		*lst = tmp_lst->next;
		del(tmp_lst->content);
		free(tmp_lst);
		tmp_lst = *lst;
	}
}
