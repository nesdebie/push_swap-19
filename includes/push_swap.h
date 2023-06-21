/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:24:29 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/21 13:40:16 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

# define SPACE 32

typedef struct s_stack
{
	int				value;
	int				idx;
	struct s_stack	*next;
}	t_stack;

/* Reverse-Rotate */
void	rra(t_stack **stack_a);

/* Rotate */
void	ra(t_stack **stack_a);

/* Push */
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);

/* Swap */
void	sa(t_stack **stack_a);

/* Mixed */
void	sa_rra(t_stack **stack_a);
void	ra_sa_rra(t_stack **stack_a);

/* Radix Sort */
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/* Small sort */
void	simple_sort(t_stack **stack_a, t_stack **stack_b);

/* Stack Manager */
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stacknew(int nb);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *head);
int		free_stack(t_stack **stack);

/* Arguments checker */
void	ft_check_args(int ac, char **av, int i);

/* Utils */
void	ft_error(char *msg);
void	ft_free(char **str);
int		is_sorted(t_stack **stack);
int		get_distance(t_stack **stack, int idx);
void	make_top(t_stack **stack, int distance);

#endif
