/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/27 10:07:11 by nburat-d         ###   ########.fr       */
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

void	display_global(t_global global)
{
	int	i; 

	i = 0;
	while (global.philo[i])
	{
		printf("Mon id de philo %d\n", global.philo[i]->id);
		printf("en vie  %d\n", global.philo[i]->is_alive);
		i++;	
	}
}

void	launch_prgm(char **av)
{
	t_global *global;

	global = create_global(av);
	global->philo = create_philo(global);
	display_global(*global);

	return ;
}