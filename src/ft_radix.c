/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:42:52 by nesdebie          #+#    #+#             */
/*   Updated: 2023/07/03 10:31:51 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	get_max_bits(t_stack **stack)
{
	int		max;
	int		max_bits;

	max_bits = 0;
	max = ft_stacksize(*stack);
	while ((max >> max_bits))
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_stacksize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->idx >> i) & 1))
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_stacksize(*stack_b))
			pa(stack_a, stack_b);
		i++;
	}
}
