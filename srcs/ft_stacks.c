/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:58:14 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/23 10:01:38 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_stacklast(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->next == NULL)
			return (tmp);
	}
	return (tmp);
}

int	ft_stacksize(t_stack *lst)
{
	size_t	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_stack	*ft_stacknew(int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = nb;
	new->idx = -1;
	new->next = NULL;
	return (new);
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (lst && new)
	{
		new->next = tmp;
		*lst = new;
	}
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (!*lst && new)
	{
		new->next = tmp;
		*lst = new;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
