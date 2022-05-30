/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/30 21:45:01 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"


int	check_if_dead(t_philo *philo)
{
	if (philo->current_time > (philo->start_to_die + philo->global->time_to_die))
		return (1); 
	else
		return (0);
}

void	*routine(void *arg)
{
	t_philo philo;
	int i;

	i = 0;
	philo = *(t_philo*) arg;
	philo.start_to_die = philo.global->start;
	while (i < philo.global->number_of_meal || philo.global->number_of_meal == -1)
	{
		pthread_mutex_lock(&philo.global->forks[philo.left_fork]);
		philo.current_time= gettime_ms();
		print_take_left_fork(&philo);
		
		if (check_if_dead(&philo) == 1)
			print_dead(&philo);
		
		pthread_mutex_lock(&philo.global->forks[philo.right_fork]);
		philo.current_time = gettime_ms();
		print_take_right_fork(&philo);
		
		if (check_if_dead(&philo) == 1)
			print_dead(&philo);
		
		philo.current_time = gettime_ms();
		philo.start_to_die = philo.current_time;
		print_eating(&philo);
		usleep(philo.global->time_to_eat);

		if (check_if_dead(&philo) == 1)
			print_dead(&philo);
		
		pthread_mutex_unlock(&philo.global->forks[philo.right_fork]);
		philo.current_time = gettime_ms();
		print_drop_right_fork(&philo);

		pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
		philo.current_time = gettime_ms();
		print_drop_left_fork(&philo);

		if (check_if_dead(&philo) == 1)
			print_dead(&philo);	
		philo.current_time = gettime_ms();
		print_sleeping(&philo);
		usleep(philo.global->time_to_sleep);
	
		if (check_if_dead(&philo) == 1)
			print_dead(&philo);
		
		philo.current_time = gettime_ms();
		print_thinking(&philo);

		if (check_if_dead(&philo) == 1)
			print_dead(&philo);
		i++;
	}
	return (NULL);
}