/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 15:04:20 by nesdebie          #+#    #+#             */
/*   Updated: 2023/05/09 10:23:58 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	**ft_free(char **arr)
{
    int i;

    i = 0;
    while (arr[i])
        i++;
	while (i >= 0)
		free(arr[i--]);
	free(arr);
	return (NULL);
}

void    ft_exit(char **arr, int ac)
{
    if (ac == 2)
        ft_free(arr);
    ft_putstr_fd("Error\n", STDERR_FILENO);
    exit(EXIT_FAILURE);
}