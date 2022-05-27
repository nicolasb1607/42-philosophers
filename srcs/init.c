/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 11:10:33 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/27 09:56:14 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

t_global *create_global(char **av)
{
	t_global *global;

	global = malloc(sizeof(t_global));
	if(!global)
	{
		printf("ERROR ALLOC GLOBAL\n");
		return (NULL);
	}
	set_param(global, av);
	global->philo = create_philo(global);
	return(global);
}

t_philo **create_philo(t_global *global)
{
	t_philo **philo;
	int i;

	philo = malloc(sizeof(t_philo*) * global->num_of_philo);
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
		init_philo(philo[i], i);
		i++;
	}
	return(philo);
}

void	init_philo(t_philo *philo, int i)
{
	philo->id = i + 1;
	philo->is_alive = 1;
	
}