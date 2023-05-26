/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:53:00 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/23 10:01:49 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_stackclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	tmp = *lst;
	while (tmp)
	{
		*lst = tmp;
		tmp = tmp->next;
		free(*lst);
	}
	*lst = NULL;
}

void	ft_error(char *msg)
{
	ft_putendl_fd(msg, 1);
	exit(0);
}
