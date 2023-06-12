/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:24:29 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/12 12:10:46 by nesdebie         ###   ########.fr       */
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
int		reverse_rotate(t_stack **stack);
int		rra(t_stack **stack_a);

/* Rotate */
int		rotate(t_stack **stack);
int		ra(t_stack **stack_a);

/* Push */
int		push(t_stack **stack_to, t_stack **stack_from);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_a, t_stack **stack_b);

/* Swap */
int		swap(t_stack **stack);
int		sa(t_stack **stack_a);

/* Mixed */
int		sa_rra(t_stack **stack_a);
int		ra_sa_rra(t_stack **stack_a);

/* Radix Sort */
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

/* Small sort */
void	sort_5(t_stack **stack_a, t_stack **stack_b);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);

/* Stack Manager */
void	ft_stackclear(t_stack **lst);
int		ft_stacksize(t_stack *lst);
t_stack	*ft_stacknew(int nb);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *head);

/* Arguments checker */
void	ft_check_args(int argc, char **argv);

/* Utils */
void	ft_error(char *msg);
void	ft_free(char **str);
int		is_sorted(t_stack **stack);
int		get_distance(t_stack **stack, int idx);
void	make_top(t_stack **stack, int distance);
void	free_stack(t_stack **stack);

#endif
