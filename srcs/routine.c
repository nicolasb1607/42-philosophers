/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/06/13 14:17:33 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

int	fork_routine(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->forks[philo->left_fork]);
	philo->current_time = gettime_ms();
	if (check_death_1_fork(philo) == 1)
		return (1);
	print_take_fork(philo);
	if (philo->global->num_of_philo == 1)
	{
		ft_usleep_bis(philo->global->time_to_die, philo);
		philo->current_time = gettime_ms();
		pthread_mutex_unlock(&philo->global->forks[philo->left_fork]);
		print_dead(philo);
		return (1);
	}
	pthread_mutex_lock(&philo->global->forks[philo->right_fork]);
	philo->current_time = gettime_ms();
	if (check_death_2_fork(philo) == 1)
		return (1);
	print_take_fork(philo);
	return (0);
}

int	eat_routine(t_philo *philo)
{
	print_eating(philo);
	philo->start_to_die = philo->current_time;
	ft_usleep_bis(philo->global->time_to_eat, philo);
	philo->current_time = gettime_ms();
	if (check_death_2_fork(philo) == 1)
		return (1);
	pthread_mutex_unlock(&philo->global->forks[philo->right_fork]);
	pthread_mutex_unlock(&philo->global->forks[philo->left_fork]);
	philo->current_time = gettime_ms();
	if (is_death(philo) == 1)
	{
		print_dead(philo);
		return (1);
	}
	return (0);
}

int	sleeping_routine(t_philo *philo)
{
	print_sleeping(philo);
	ft_usleep_bis(philo->global->time_to_sleep, philo);
	philo->current_time = gettime_ms();
	if (check_death_classic(philo) == 1)
		return (1);
	return (0);
}

void	*routine(void *arg)
{
	t_philo	philo;

	philo = *(t_philo *) arg;
	if (philo.id % 2 == 0)
		ft_usleep(10);
	philo.start_to_die = gettime_ms();
	while (philo.global->number_of_meal == -1
		|| philo.meal_taken < philo.global->number_of_meal)
	{
		if (fork_routine(&philo) == 1)
			return (NULL);
		if (eat_routine(&philo) == 1)
			return (NULL);
		if (sleeping_routine(&philo) == 1)
			return (NULL);
		print_thinking(&philo);
		if (philo.global->num_of_philo == 3)
			ft_usleep_bis(100, &philo);
		else
			ft_usleep_bis(3, &philo);
	}
	pthread_mutex_lock(&philo.global->mutex_meals_taken);
	philo.global->all_meals_taken++;
	pthread_mutex_unlock(&philo.global->mutex_meals_taken);
	return (NULL);
}
