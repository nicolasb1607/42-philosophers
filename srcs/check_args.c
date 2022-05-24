/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 10:24:32 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/24 13:56:09 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_args.h"

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

int	is_args_valid(int ac, char **av)
{
	if(ac == 5 || ac == 6)
	{
		if (is_all_int_arg(av) == 1)
			return (1);	
	}
	return (0);
}