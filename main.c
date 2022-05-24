/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:50:38 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/24 14:04:17 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	if (is_args_valid(ac, av) == 1)
	{
		printf("All right\n");
		//launch_prgm();
	}
	else
		printf("Arg not valid\n");
	return (0);
}
