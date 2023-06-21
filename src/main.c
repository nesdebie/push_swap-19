/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:23:50 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/21 13:40:00 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*get_next_min(t_stack **stack)
{
	t_stack	*head;
	t_stack	*min;
	int		has_min;

	min = NULL;
	has_min = 0;
	head = *stack;
	if (head)
	{
		while (head)
		{
			if ((head->idx == -1) && (!has_min || head->value < min->value))
			{
				min = head;
				has_min = 1;
			}
			head = head->next;
		}
	}
	return (min);
}

void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->idx = index++;
		head = get_next_min(stack);
	}
}

static void	init_stack(t_stack **stack, int ac, char **av, int i)
{
	t_stack	*new;
	char	**args;

	if (ac == 2)
	{
		args = ft_split(av[1], SPACE);
		if (!args)
			ft_error("Error");
	}
	else
	{
		i = 0;
		args = av;
	}
	while (args[++i])
	{
		new = ft_stacknew(ft_atoi(args[i]));
		if (!new)
			ft_error("Error");
		ft_stackadd_back(stack, new);
	}
	index_stack(stack);
	if (ac == 2)
		ft_free(args);
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stacksize(*stack_a) < 6)
		simple_sort(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	if (ac < 2)
		return (0);
	ft_check_args(ac, av, -1);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = (t_stack **)malloc(sizeof(t_stack));
	if (stack_b)
	{
		*stack_a = NULL;
		*stack_b = NULL;
		init_stack(stack_a, ac, av, -1);
		if (is_sorted(stack_a))
		{
			free_stack(stack_a);
			return (free_stack(stack_b));
		}
		sort_stack(stack_a, stack_b);
		free_stack(stack_b);
	}
	return (free_stack(stack_a));
}
