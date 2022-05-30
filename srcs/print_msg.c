/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:55:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 17:40:41 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_msg.h"

void	print_take_fork(t_philo *philo)
{
	long current_time;

	current_time = gettime_ms();
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has taken a fork\n", current_time - philo->global->start ,  philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_eating(t_philo *philo)
{
	long current_time;

	current_time = gettime_ms();
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d is eating\n", current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_sleeping(t_philo *philo)
{
	long current_time;

	current_time = gettime_ms();
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d is sleeping\n", current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_thinking(t_philo *philo)
{
	long current_time;

	current_time = gettime_ms();
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d is thinking\n", current_time - philo->global->start , philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_drop_fork(t_philo *philo)
{
	long current_time;

	current_time = gettime_ms();
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has drop a fork\n", current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}