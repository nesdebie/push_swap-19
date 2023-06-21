/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:46:42 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/21 11:39:33 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;
	int		tmp_idx;

	if (ft_stacksize(*stack) < 2)
		return (1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		ft_error("Error occured while swapping!");
	tmp_val = head->value;
	tmp_idx = head->idx;
	head->value = next->value;
	head->idx = next->idx;
	next->value = tmp_val;
	next->idx = tmp_idx;
	return (0);
}

void	sa(t_stack **stack_a)
{
	if (swap(stack_a))
		return ;
	ft_putendl_fd("sa", 1);
}

void	sa_rra(t_stack **stack_a)
{
	sa(stack_a);
	rra(stack_a);
}
