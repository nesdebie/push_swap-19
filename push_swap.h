/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:24:29 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/09 10:23:53 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

# define SPACE 32

typedef struct s_stack
{
    int             nb;
	struct s_stack	*next;
    struct s_stack  *prev;
} t_stack;

void	ft_stackclear(t_stack **lst);
int     ft_stacksize(t_stack *lst);
t_stack	*ft_stacknew(void *nb);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
void	ft_stackadd_back(t_stack **lst, t_stack *new);

void	**ft_free(char **arr);
void    ft_exit(char **arr, int ac);

#endif