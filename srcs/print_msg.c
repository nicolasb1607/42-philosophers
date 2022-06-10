/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:55:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/10 16:51:34 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_msg.h"

void	print_take_fork(t_philo *philo)
{
	
	pthread_mutex_lock(&philo->global->printf);
	if (philo->global->stop == 0)
		printf("[%ld] philo #%d has taken a fork\n", philo->current_time - philo->global->start ,  philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	if (philo->global->stop == 0)
		printf("[%ld] philo #%d is eating\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
	philo->meal_taken = philo->meal_taken + 1;
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	if (philo->global->stop == 0)
		printf("[%ld] philo #%d is sleeping\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	if (philo->global->stop == 0)
		printf("[%ld] philo #%d is thinking\n", philo->current_time - philo->global->start , philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_dead(t_philo *philo)
{
		pthread_mutex_lock(&philo->global->printf);
		if (philo->global->stop == 0)
		{
			printf("[%ld] philo #%d IS DEAD\n", philo->current_time - philo->global->start, philo->id);
			pthread_mutex_lock(&philo->global->mutex_stop);
			philo->global->stop = 1;
			pthread_mutex_unlock(&philo->global->mutex_stop);
		}
		pthread_mutex_unlock(&philo->global->printf);
}