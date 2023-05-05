/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:23:50 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/05 14:54:57 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_exit(void)
{
    ft_putstr_fd("Error\n", STDERR_FILENO);
    exit(EXIT_FAILURE);
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
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int main(int ac, char **av)
{
    t_tab   *tab_a;
    t_tab   *tab_b;

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