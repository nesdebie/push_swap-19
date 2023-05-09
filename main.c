/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:23:50 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/09 11:05:34 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_is_sorted(t_stack *a)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = a;
    tmp2 = a->next;
    while (tmp1->next)
    {
        while (tmp2)
        {
            if (tmp1->nb > tmp2->nb)
                return (EXIT_FAILURE);
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp1->next;
    }
    return (EXIT_SUCCESS);
}

static int  ft_is_double(t_stack *a)
{
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = a;
    tmp2 = a->next;
    while (tmp1->next)
    {
        while (tmp2)
        {
            if (tmp1->nb == tmp2->nb)
                return (EXIT_FAILURE);
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp1->next;
    }
    return (EXIT_SUCCESS);
}

static int  ft_check_and_create_tab_a(t_stack *a, char **av)
{
    size_t  i;
    t_stack *node;

    i = 0;
    while (av + i)
    {
        node = ft_stacknew(ft_atoi(av + i));
        if (!node)
        {
            if (a)
                ft_stackclear(a);
            return (EXIT_FAILURE);
        }
        ft_stackadd_back(a, node);
        i++;
    }
    if (ft_is_double(a))
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

int ft_pushswap(t_stack *tab_a)
{
    t_stack *tab_b;

    tab_b = NULL;
    if (!ft_is_sorted(tab_a));
        ft_sort(tab_a, tab_b);
    ft_stackclear(tab_a);
    return (EXIT_SUCCESS);
}

int main(int ac, char **av)
{
    t_stack   **tab_a;
    char      **tmp;

    tab_a = NULL;
    if (ac > 1)
    {
        tmp = av + 1;
        if (ac == 2)
        {
            tmp = ft_split(av + 1, SPACE);
            if (!tmp)
                ft_exit(NULL, 0);
        }
        if (ft_only_nb(tmp))
            ft_exit(tmp, ac);
        if (ft_check_and_create_tab_a(&tab_a, tmp))
            ft_exit(tmp, ac);
        if (ac == 2)
            ft_free(tmp);
        ft_pushswap(&tab_a);
    }
    return (EXIT_SUCCESS);
}