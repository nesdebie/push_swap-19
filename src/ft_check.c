/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nesdebie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:55:49 by nesdebie          #+#    #+#             */
/*   Updated: 2023/06/30 13:15:36 by nesdebie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static long long	ft_bigatoi(char const *str)
{
	int				i;
	int				sign;
	long long		result;

	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == SPACE || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - 48;
		if (result > INT32_MAX && (result * sign != INT32_MIN))
			ft_error("Error");
		i++;
	}
	return ((sign * result));
}

static int	ft_contains(int num, char **av, int i)
{
	i++;
	while (av[i])
	{
		if (ft_bigatoi(av[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	if ((num[0] == '-' || num[0] == '+') && i == 1)
		return (0);
	return (1);
}

void	ft_check_args(int ac, char **av, int i)
{
	long long	tmp;

	if (ac == 2)
	{
		av = ft_split(av[1], SPACE);
		if (!av)
			ft_error("Error");
	}
	else
		i = 0;
	while (av[++i])
	{
		tmp = ft_bigatoi(av[i]);
		if (!ft_isnum(av[i]))
			ft_error("Error");
		if (ft_contains(tmp, av, i))
			ft_error("Error");
	}
	if (ac == 2)
		ft_free(av);
}
