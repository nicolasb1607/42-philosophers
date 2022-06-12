/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:10:33 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 10:11:34 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_philo	**create_philo(t_global *global)
{
	t_philo	**philo;
	int		i;

	philo = malloc (sizeof(t_philo *) * global->num_of_philo);
	init_forks(global);
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
		set_fork_to_philo(philo[i], global);
		i++;
	}
	return (philo);
}

void	init_philo(t_philo *philo, int i, t_global *global)
{
	philo->id = i + 1;
	philo->global = global;
	philo->meal_taken = 0;
}

void	init_forks(t_global *global)
{
	int	i;

	i = 0;
	global->forks = malloc(sizeof(pthread_mutex_t) * global->num_of_philo);
	while (i < global->num_of_philo)
	{
		if (pthread_mutex_init(&global->forks[i], NULL) != 0)
		{
			printf("ERROR mutex init\n");
			return ;
		}
		i++;
	}
}

void	set_fork_to_philo(t_philo *philo, t_global *global)
{
	if (philo->id % 2 == 0)
	{
		philo->left_fork = philo->id % global->num_of_philo;
		philo->right_fork = (philo->id + global->num_of_philo - 1)
			% global->num_of_philo;
	}
	else
	{
		philo->right_fork = philo->id % global->num_of_philo;
		philo->left_fork = (philo->id + global->num_of_philo - 1)
			% global->num_of_philo;
	}
}
