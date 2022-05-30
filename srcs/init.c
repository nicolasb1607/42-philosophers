/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:10:33 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 21:10:26 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	set_param(t_global *global, char **av)
{
	global->num_of_philo = ft_atoi(av[1]) ;
	global->time_to_die = ft_atoi(av[2]) * 1000;
	global->time_to_eat = ft_atoi(av[3])* 1000;
	global->time_to_sleep = ft_atoi(av[4])* 1000;
	if (av[5])
		global->number_of_meal = ft_atoi(av[5]);
	else
		global->number_of_meal = -1;
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
	if (pthread_mutex_init(&global->printf, NULL) != 0)
		return NULL;

	return (global);
}

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
	philo->is_alive = 1;
	philo->global = global;
}


void	init_forks(t_global *global)
{
	int	i;

	i = 0;
	global->forks = malloc(sizeof(pthread_mutex_t) * global->num_of_philo);
	while (i < global->num_of_philo)
	{
		if(pthread_mutex_init(&global->forks[i], NULL) != 0)
		{
			printf("ERROR mutex init\n");
			return ;
		}
		i++;
	}
}

void	set_fork_to_philo(t_philo *philo, t_global *global)
{
	philo->left_fork =	philo->id % global->num_of_philo;;
	philo->right_fork = (philo->id + global->num_of_philo - 1) % global->num_of_philo;;
}