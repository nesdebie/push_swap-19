/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:49:37 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/21 11:38:24 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stacksize(*stack) < 2)
		return (1);
	head = *stack;
	tail = ft_stacklast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

void	ra(t_stack **stack_a)
{
	if (rotate(stack_a))
		return ;
	ft_putendl_fd("ra", 1);
}

void	ra_sa_rra(t_stack **stack_a)
{
	ra(stack_a);
	sa_rra(stack_a);
}
