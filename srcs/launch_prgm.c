/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 15:10:23 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/25 14:32:42 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	set_param(t_philo *philo, char **av)
{
	philo->num_of_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_eat = ft_atoi(av[3]);
	philo->time_to_sleep = ft_atoi(av[4]);
	philo->alive = 1;
}

void	display_param(t_philo philo)
{
	printf("num_of_philo = %d\n", philo.num_of_philo);
	printf("time_to_die = %d\n", philo.time_to_die);
	printf("time_to_eat = %d\n", philo.time_to_eat);
	printf("time_to_sleep = %d\n", philo.time_to_sleep);
	printf("alive = %d\n", philo.alive);	
}

void	launch_prgm(char **av)
{
	t_philo philo;

	set_param(&philo, av);
	display_param(philo);
	return ;
}