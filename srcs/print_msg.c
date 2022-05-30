/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 10:55:01 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 21:46:42 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_msg.h"

void	print_take_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has taken left fork\n", philo->current_time - philo->global->start ,  philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_take_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has taken right fork\n", philo->current_time - philo->global->start ,  philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_take_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has taken a fork\n", philo->current_time - philo->global->start ,  philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_eating(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d is eating\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_sleeping(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d is sleeping\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_thinking(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d is thinking\n", philo->current_time - philo->global->start , philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_drop_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has drop a fork\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_drop_left_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has drop left fork\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_drop_right_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d has drop right fork\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}

void	print_dead(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	printf("[%ld] philo #%d IS DEAD\n", philo->current_time - philo->global->start, philo->id);
	pthread_mutex_unlock(&philo->global->printf);
}