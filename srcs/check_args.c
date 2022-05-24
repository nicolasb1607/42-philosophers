/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:24:32 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/24 16:47:31 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

int	is_args_valid(int ac, char **av)
{
	if (is_number_arg_valid(ac) == 0)
		return (0);
	if (is_all_digit_arg(av) == 0)
	{
		ft_putstr_fd(ERROR_NOT_NUMERIC_ARGS, 2);
		return (0);
	}
	if (is_all_int_arg(av) == 0)
	{	
		ft_putstr_fd(ERROR_INT_OVERFLOW, 2);
		return (0);
	}
	return (1);
}

int	is_number_arg_valid(int ac)
{
	if (ac < 5)
	{
		ft_putstr_fd(ERROR_NOT_ENOUGHT_ARGS, 2);
		return (0);
	}
	if (ac > 6)
	{
		ft_putstr_fd(ERROR_TOO_MANY_ARGS, 2);
		return (0);
	}
	return (1);
}

int	is_all_digit_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (is_str_number(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_all_int_arg(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_is_int(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_str_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
