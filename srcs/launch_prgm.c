/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/26 17:51:44 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_param(t_global *global, char **av)
{
	global->num_of_philo = ft_atoi(av[1]);
	global->time_to_die = ft_atoi(av[2]);
	global->time_to_eat = ft_atoi(av[3]);
	global->time_to_sleep = ft_atoi(av[4]);
}

void	display_param(t_global global)
{
	printf("num_of_global = %d\n", global.num_of_philo);
	printf("time_to_die = %d\n", global.time_to_die);
	printf("time_to_eat = %d\n", global.time_to_eat);
	printf("time_to_sleep = %d\n", global.time_to_sleep);

}

void	launch_prgm(char **av)
{
	t_global *global;

	global = create_global(av);

	
	return ;
}