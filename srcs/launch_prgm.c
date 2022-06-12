/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 10:17:08 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	malloc_threads(t_global *global)
{
	global->threads = malloc(sizeof(pthread_t) * global->num_of_philo);
}

void	launch_philo_threads(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_create(&global->threads[i], NULL, &routine, global->philo[i]);
		i++;
	}
}

void	join_philo_threads(t_global *global)
{
	int	i;

	i = 0;
	while (i < global->num_of_philo)
	{
		pthread_join(global->threads[i], NULL);
		i++;
	}
	return ;
}

int	is_all_meals_taken(t_global *global)
{
	pthread_mutex_lock(&global->mutex_meals_taken);
	if (global->all_meals_taken == global->num_of_philo)
	{	
		pthread_mutex_unlock(&global->mutex_meals_taken);
		return (1);
	}
	pthread_mutex_unlock(&global->mutex_meals_taken);
	return (0);
}

void	launch_prgm(char **av)
{
	t_global	*global;

	global = create_global(av);
	global->philo = create_philo(global);
	malloc_threads(global);
	global->start = gettime_ms();
	launch_philo_threads(global);
	while (1)
	{	
		ft_usleep(5);
		pthread_mutex_lock(&global->mutex_stop);
		if (is_all_meals_taken(global) == 1 || global->stop == 1)
		{
			pthread_mutex_unlock(&global->mutex_stop);
			break ;
		}
		pthread_mutex_unlock(&global->mutex_stop);
	}
	join_philo_threads(global);
	free_all_struct(global);
	return ;
}
