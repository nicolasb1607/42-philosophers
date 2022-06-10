/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/10 10:29:34 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		i++;	
	}
}

void	malloc_threads(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->num_of_philo)
	{
		global->threads = malloc(sizeof(pthread_t));
		i++;
	}
}

void	launch_philo_threads(t_global *global)
{
	int i;

	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_create(&global->threads[i], NULL, &routine, global->philo[i]);
		i++;
	}
}

void	join_philo_threads(t_global *global)
{
	int i; 
	
	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_join(global->threads[i], NULL);
		i++;
	}
}

int	is_all_meals_taken(t_global *global)
{
	if(global->all_meals_taken == global->num_of_philo)
		return (1);
	return (0);
}

void	launch_prgm(char **av)
{
	t_global *global;

	global = create_global(av);
	global->philo = create_philo(global);
	malloc_threads(global);
	global->start = gettime_ms();
	launch_philo_threads(global);
	while(1)
	{
		if (is_all_meals_taken(global) == 1 || global->stop == 1)
			return ;
	}
	join_philo_threads(global);
	return ;
}