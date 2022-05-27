/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:10:33 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/27 14:28:49 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	set_param(t_global *global, char **av)
{
	global->num_of_philo = ft_atoi(av[1]);
	global->time_to_die = ft_atoi(av[2]);
	global->time_to_eat = ft_atoi(av[3]);
	global->time_to_sleep = ft_atoi(av[4]);
}

t_global	*create_global(char **av)
{
	t_global	*global;

	global = malloc(sizeof(t_global));
	if (!global)
	{
		printf("ERROR ALLOC GLOBAL\n");
		return (NULL);
	}
	set_param(global, av);
	if (pthread_mutex_init(&global->printf, NULL) != 0);
	
	return (global);
}

t_philo	**create_philo(t_global *global)
{
	t_philo	**philo;
	int		i;

	philo = malloc (sizeof(t_philo *) * global->num_of_philo);
	if (!philo)
	{
		printf("ERROR ALLOC PHILO\n");
		return (NULL);
	}
	i = 0;
	while (i < global->num_of_philo)
	{
		philo[i] = malloc(sizeof(t_philo));
		if (!philo)
		{
			printf("ERROR ALLOC PHILO\n");
			return (NULL);
		}
		init_philo(philo[i], i, global);
		i++;
	}
	return (philo);
}

void	init_philo(t_philo *philo, int i, t_global *global)
{
	philo->id = i + 1;
	philo->is_alive = 1;
	philo->global = global;
}
