/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:23:50 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/05 15:23:11 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_check_and_create_tab_a(a, av)
{
    size_t  i;
    t_stack *node;

    i = 1;
    while (av + i)
    {
        node = ft_stacknew(ft_atoi(a + i));
        if (!node)
        {
            if (a)
                ft_stackclear(a);
            return (EXIT_FAILURE);
        }
        ft_stackadd_back(a, node);
        i++;
    }
    if (is_double(a))
    {
        ft_stackclear(a);
        return (EXIT_FAILURE);
    }
    return (EXIT_SUCCESS);
}

static int ft_only_nb(char **av)
{
    size_t i;
    size_t j;
    i = 1;
    while (av[i])
    {
        j = 0;
        while(av[i][j])
        {
            if ((av[i][0] == 43 || av[i][0] == 45) && j == 0)
                j++;
            if (!ft_isdigit(av[i][j]))
                return (EXIT_FAILURE);
            j++;
        }
        i++;
    }
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    t_stack   *tab_a;
    t_stack   *tab_b;

    tab_a = NULL;
    tab_b = NULL;
    if (ac > 2)
    {
        if (ft_only_nb(av))
            ft_exit();
        if (ft_check_and_create_tab_a(&tab_a, av))
            ft_exit();
        ft_sort(&tab_a, tab_b);
    }
    exit(EXIT_SUCCESS);
}