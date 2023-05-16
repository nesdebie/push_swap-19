/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:51:29 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/16 15:08:07 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverseRotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*tail;

	if (ft_stacksize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_stacklast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			 head->next = NULL;
			 break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	rra(t_stack **stack_a)
{
	if (reverseRotate(stack_a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (0);
}

int	rrb(t_stack **stack_b)
{
	if (reverseRotate(stack_b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (0);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	if ((ft_stacksize(*stack_a) < 2) || (ft_stacksize(*stack_b) < 2))
		return (-1);
	reverseRotate(stack_a);
	reverseRotate(stack_b);
	ft_putendl_fd("rrr", 1);
	return (0);
}