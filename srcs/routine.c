/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 10:37:31 by nburat-d          #+#    #+#             */
/*   Updated: 2022/05/31 14:11:40 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "routine.h"

void	print_val(t_philo *philo)
{
	pthread_mutex_lock(&philo->global->printf);
	//printf(" current_time %ld, start_to_die %ld,", philo->current_time, philo->start_to_die, philo->global->time_to_die);
	printf("DIFF = %ld , time to die %d\n",philo->current_time - philo->start_to_die, philo->global->time_to_die);
	pthread_mutex_unlock(&philo->global->printf);
}


int	is_death(t_philo *philo)
{
	print_val(philo);
	if((philo->current_time - philo->start_to_die) > philo->global->time_to_die)
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

	philo.start_to_die = gettime_ms();
	while (i < philo.global->number_of_meal || philo.global->number_of_meal == -1)
	{
		pthread_mutex_lock(&philo.global->forks[philo.left_fork]);
		philo.current_time = gettime_ms();
		print_take_left_fork(&philo);
		
		if (is_death(&philo) == 1)
			print_dead(&philo);		
		
		pthread_mutex_lock(&philo.global->forks[philo.right_fork]);
		philo.current_time = gettime_ms();
		print_take_right_fork(&philo);
		
		if (is_death(&philo) == 1)
			print_dead(&philo);		

		print_eating(&philo);
		philo.start_to_die = philo.current_time;
		usleep(philo.global->time_to_eat * 1000);

		if (is_death(&philo) == 1)
			print_dead(&philo);		

		pthread_mutex_unlock(&philo.global->forks[philo.right_fork]);
		philo.current_time = gettime_ms();
		print_drop_right_fork(&philo);

		if (is_death(&philo) == 1)
			print_dead(&philo);		

		pthread_mutex_unlock(&philo.global->forks[philo.left_fork]);
		philo.current_time = gettime_ms();
		print_drop_left_fork(&philo);

		if (is_death(&philo) == 1)
			print_dead(&philo);		

		philo.current_time = gettime_ms();
		print_sleeping(&philo);
		usleep(philo.global->time_to_sleep * 1000);
	
		if (is_death(&philo) == 1)
			print_dead(&philo);		

		philo.current_time = gettime_ms();
		print_thinking(&philo);
		
		if (is_death(&philo) == 1)
			print_dead(&philo);		
		
		i++;
	}
	return (NULL);
}