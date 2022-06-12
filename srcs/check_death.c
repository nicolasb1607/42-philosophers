/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 10:31:17 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/12 11:02:42 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "check_death.h"

int	is_death(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->mutex_stop);
	if ((philo->current_time - philo->start_to_die) > philo->global->time_to_die
		|| philo->global->stop == 1)
	{
		pthread_mutex_unlock(&philo->global->mutex_stop);
		return (1);
	}
	pthread_mutex_unlock(&philo->global->mutex_stop);
	return (0);
}

int	check_death_1_fork(t_philo *philo)
{
	if (is_death(philo) == 1)
	{
		pthread_mutex_unlock(&philo->global->forks[philo->left_fork]);
		print_dead(philo);
		return (1);
	}
	return (0);
}

int	check_death_2_fork(t_philo *philo)
{
	if (is_death(philo) == 1)
	{
		pthread_mutex_unlock(&philo->global->forks[philo->right_fork]);
		pthread_mutex_unlock(&philo->global->forks[philo->left_fork]);
		print_dead(philo);
		return (1);
	}
	return (0);
}

int	check_death_classic(t_philo *philo)
{
	if (is_death(philo) == 1)
	{
		print_dead(philo);
		return (1);
	}
	return (0);
}
