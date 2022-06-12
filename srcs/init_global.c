/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_global.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:11:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 10:11:38 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	set_param(t_global *global, char **av)
{
	global->num_of_philo = ft_atoi(av[1]);
	global->time_to_die = ft_atoi(av[2]);
	global->time_to_eat = ft_atoi(av[3]);
	global->time_to_sleep = ft_atoi(av[4]);
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
		return (NULL);
	if (pthread_mutex_init(&global->mutex_stop, NULL) != 0)
		return (NULL);
	if (pthread_mutex_init(&global->mutex_meals_taken, NULL) != 0)
		return (NULL);
	return (global);
}
