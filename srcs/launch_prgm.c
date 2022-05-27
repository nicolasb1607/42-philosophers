/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/27 14:25:54 by nburat-d         ###   ########.fr       */
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
		printf("en vie  %d\n", global.philo[i]->is_alive);
		i++;	
	}
}

void	launch_prgm(char **av)
{
	t_global *global;
	pthread_t *threads;
	int	i; 

	global = create_global(av);
	global->philo = create_philo(global);
	//display_global(*global);
	while (i < global->num_of_philo)
	{
		threads = malloc(sizeof(pthread_t));
		i++;
	}
	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_create(&threads[i], NULL, &routine, global->philo[i]);
		i++;
	}
	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
	return ;
}